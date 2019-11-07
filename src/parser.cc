///////////////////////////////////////////////////////////
// codigo fuente: parser.cc                              //
// fecha de inicio: 05/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase parser para analizar la sintaxis de  //
//            codigo en lenguaje RTLog.                  //
//                                                       //
// clase implementada:                                   //
//  Parser                                               //
// propiedades:                                          //
//  block_name - identificador del nombre del block.     //
//  m_clouds - cloud logic.                              //
//  m_constants - diccionario de constantes.             //
//  m_i2r_paths - caminos i2r.                           //
//  m_r2o_paths - caminos r2o.                           //
//  m_r2r_paths - caminos r2r.                           //
//  degraph - grafo del circuito desincronizado.         //
//  generate_ids - id de los indices de los generates.   //
//  generate_index - valor de los indices de los         //
//                   generates.                          //
//  generate_rel_flags - indicadores de expresiones      //
//                       booleanas en un when.           //
//  graph - grafo del circuito.                          //
//  local_table - tabla de wires locales.                //
//  meta_graph - meta grafo del circuito.                //
//  port_table - tabla de puertos.                       //
//  tok - implementacion del tokenizer.                  //
//  op_token - token obtenido ( num o op ).              //
//  token - token obtenido ( keywords o id ).            //
// metodos:                                              //
//  assign - parsing de sentencias de asignacion.        //
//  block - parsing de la definicion bloque.             //
//  boolean - parsing de sentencias if.                  //
//  concatenation - parsing de sentencias de             //
//                  concatenacion.                       //
//  decls - parsing de la definicion wire internos.      //
//  desync - desincroniza el grafo.                      //
//  dim - parsing de la dimension de un bus.             //
//  emit - genera el archivo Verilog.                    //
//  expr - parsing de sentencias de suma y resta.        //
//  f_eval_expr - parsing de una expresion evaluada.     //
//  f_eval_factor - proposito: parsing de un factor      //
//      evaluado.                                        //
//  f_eval_logic - parsing de una expresion logica.      //
//  f_eval_rel - parsing de una expresion relacional.    //
//  f_eval_term - parsing de un termino evaluado.        //
//  f_eval_unary - parsing de un unary evaluado.         //
//  getNodes - obtiene los numeros de nodos de un        //
//            identificador.                             //
//  factor - parsing de factores.                        //
//  for_generate - parsing de un for generate.           //
//  f_find_const - determina si existe una constante.    //
//  f_find_param - determina si existe un parametro.     //
//  f_generate_condition - parsing de la condicion       //
//      de un when.                                      //
//  f_generate_conditional - parsing de un for generate  //
//      condicionado por whens.                          //
//  f_generate_factor - parsing de un factor de la       //
//      condicion que activa el when.                    //
//  init - inicializaccion del parser.                   //
//  inputs - parsing de la definicion puertos de         //
//           entrada.                                    //
//  Insert_FC - inserta fork controllers en forma        //
//              recursiva.                               //
//  Insert_JC - inserta join controllers en forma        //
//              recursiva.                               //
//  leftValue - parsing del left value.                  //
//  left_value_offset - parsing de la indexacion de un   //
//                      left value.                      //
//  logical - parsing de sentencias logicas.             //
//  makeTree - completa arbol de multiplexores.          //
//             ( 2 sobrecargas ).                        //
//  offset - parsing de un indice.                       //
//  outputs - parsing de la definicion puertos de        //
//            salida.                                    //
//  parameters - parsing de la definicion de parametros. //
//  ports - parsing de la definicion de puertos.         //
//  rel - parsing de sentencias de comparacion.          //
//  replication - parsing de sentencias de replicacion.  //
//  report - genera informe de compilacion.              //
//  f_report_async_graph - informa el grafo asincronico  //
//      generado.                                        //
//  f_report_cloud_logic - informa la cloud logic.       //
//  f_report_general - informe general                   //
//                     de la compilacion.                //
//  f_report_graph - informa el grafo generado.          //
//  f_report_i2r_paths - informa los caminos i2r.        //
//  f_report_metagraph - informa el metagrafo.           //
//  f_report_r2o_paths - informa los caminos r2o.        //
//  f_report_r2r_paths - informa los caminos r2r.        //
//  run - analiza la sintaxis del archivo fuente         //
//        agendado.                                      //
//  selection - parsing de sentencias case.              //
//  shift - parsing de sentencias de desplazamiento.     //
//  slicing - parsing de un subvector.                   //
//  stmt - parsing de una sentencia.                     //
//  stmts - parsing de la lista de sentencias.           //
//  term - parsing de sentencias de producto.            //
//  throw_nl - descarta new lines.                       //
//  unary - parsing de operaciones unarias.              //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <fstream>

#include "parser.h"
#include "port.h"
#include "tag.h"
#include "tokenizer.h"

///////////////////////////////////////////////////////////
// metodo: setAsync                                      //
// proposito: setear tipo de clock a local               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::setAsync(void)
{
	is_async = true;
}

///////////////////////////////////////////////////////////
// metodo: setSync                                       //
// proposito: setear tipo de clock a global              //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::setSync(void)
{
	is_async = false;
}

///////////////////////////////////////////////////////////
// metodo: getClock                                      //
// proposito: getear tipo de clock                       //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

bool Parser::getClock(void)
{
	return is_async;
}

///////////////////////////////////////////////////////////
// metodo: assign                                        //
// proposito: parsing de sentencias de asignacion.       //
//            ej:                                        //
//            sig_o = sig_i                              //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::assign(void)
{
	// gramatica
	// assign := lvalue = concatenation

	int expc_width;
	int net;
	int node;
	vector<int> lvalue;
	vector<int> rvalue;

	tok.retract();

	lvalue = leftValue();

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en una asignacion."
				<< endl;
		cout << "id = right value :P." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// =
	if (!token.match(TK_OP, OP_ASSGN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token =." << endl;
		cout << "Error de sintaxis en asignacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	expc_width = lvalue.size();

	rvalue = concatenation(expc_width);

	// asignaciones no condicionadas por un if
	if (env.size() == 0)
	{
		// dimension de los vectores
		if (!widthCheck(lvalue, rvalue))
		{
			cout << "[ERROR] Las longitudes de palabra no coinciden." << endl;
			cout << "Error en una asignacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		graph.connect(lvalue, rvalue);

		if (!throw_nl())
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo."
					<< endl;
			cout << "El codigo debe terminar en end." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
	// asignacion condicionada por un if
	else
	{
		// dimension de los vectores
		if (!widthCheck(lvalue, rvalue))
		{
			cout << "[ERROR] Las longitudes de palabra no coinciden." << endl;
			cout << "Error en una asignacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		makeTree(rvalue, lvalue);

		if (!throw_nl())
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo."
					<< endl;
			cout << "El codigo debe terminar en end." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
}

///////////////////////////////////////////////////////////
// metodo: block                                         //
// proposito: parsing de la definicion bloque.           //
//            ej:                                        //
//            block myblock begin                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::block(void)
{
	// gramatica
	// bloque := block id begin | block id nl_list begin
	// nl_list = nl_list newline | e

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion block."
				<< endl;
		cout << "No define un block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// block
	if (!token.match(TK_KW, KW_BLOCK))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token block." << endl;
		cout << "No define el block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion block."
				<< endl;
		cout << "No define un block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (!token.match(TK_ID))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un identificador de block."
				<< endl;
		cout << "No define un block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// nombre del block
	block_name = token.getN();
	tok.lockSymbol(block_name);

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion block."
				<< endl;
		cout << "No define un block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
block." << endl;
		cout << "Error de sintaxis en construccion block." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// new line
	if (!token.match(TK_NL))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un enter." << endl;
		cout << "La declaracion de un block debe estar \
en una linea." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}
}

///////////////////////////////////////////////////////////
// metodo: boolean                                       //
// proposito: parsing de sentencias if.                  //
//            ej:                                        //
//            if sel begin                               //
//                m = a                                  //
//            end else begin                             //
//                m = b                                  //
//            end                                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::boolean(void)
{
	// gramatica
	// boolean := if concatenation nl_list begin nl stmts end
	// nl_list = nl_list newline | e

	int net;
	vector<int> cond;
	Env nesting;

//	cond = concatenation(-1);
	cond = logical(-1);
	net = cond[0];

	// buffer a la condicion
	nesting.node = graph.insertBuf(cond);

	// entrada true de un if ( entrada de datos i0 )
	nesting.data_in = 0;
	nesting.is_case = false;
	env.push_back(nesting);

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	stmts();

	env.pop_back();

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// else
	if (!token.match(TK_KW, KW_ELSE))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token else." << endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// entrada false de un if ( entrada de datos i1 )
	nesting.data_in = 1;
	env.push_back(nesting);

	stmts();

	env.pop_back();

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion if."
				<< endl;
		cout << "Error de sintaxis en construccion if." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}
}

///////////////////////////////////////////////////////////
// metodo: concatenation                                 //
// proposito: parsing de sentencias de concatenacion.    //
//            ej:                                        //
//            a cat b                                    //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::concatenation(int expc_width)
{
	// gramatica
	// concatenation := concatenation cat replication |
	//                  concatenation
	int node;
	vector<int> bus;
	vector<int> op2;

	bus = replication(expc_width);

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera una replication o concatenation." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// term cat factor
	while (token.match(TK_KW, KW_CAT))
	{
		op2 = replication(expc_width);

		// concatena el segundo operando al primero
		for (auto &net : op2)
		{
			bus.push_back(net);
		}

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera una replication o concatenation." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: decls                                         //
// proposito: parsing de la definicion wire internos.    //
//            ej:                                        //
//            logic foo[4]                               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::decls(void)
{
	int buf;
	int i;
	int reg;
	int reg_id;
	int w;
	int width;
	int wire_id;
	Port wire;
	vector<int> nodes;

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en declaraciones locales."
				<< endl;
		cout << "Error de sintaxis en declaraciones locales." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// agenda wire hasta que aparezcan sentencias
	while (token.match(TK_KW, KW_LOGIC) ||
			token.match(TK_KW, KW_REG))
	{
		// logic
		if (token.match(TK_KW, KW_LOGIC))
		{
			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en declaraciones locales."
						<< endl;
				cout << "logic a :)" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// id
			if (!token.match(TK_ID))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un identificador de wire."
						<< endl;
				cout << "logic id :P" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// rescata identificador del wire
			wire_id = token.getN();

			wire.name = tok.getSymbol(wire_id);
			wire.reg = PORT_LOGIC;

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en declaraciones locales."
						<< endl;
				cout << "logic a :)" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// [
			if (token.match(TK_OP, OP_IX_OP))
			{
				width = dim();

				wire.dim = width;

				if (!tok.getNext(token))
				{
					cout << "[ERROR] Insuficientes tokens." << endl;
					cout << "Final abrupto del codigo en declaraciones locales."
							<< endl;
					cout << "Error de sintaxis en construccion en declaraciones locales."  << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// ]
				if (!token.match(TK_OP, OP_IX_CL))
				{
					cout << "[ERROR] Token invalido." << endl;
					cout << "Se esperaba un token ]."
							<< endl;
					cout << "Desbalanceo de corchetes en en declaraciones locales."  << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// verifica que el identificador no este usado
				if (tok.isSymbolUsed(wire_id))
				{
					cout << "[ERROR] Identificador ya usado." << endl;
					cout << "El identificador del wire no debe \
haberse usado previamente" << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				if (!tok.getNext(token))
				{
					cout << "[ERROR] Insuficientes tokens." << endl;
					cout << "Final abrupto del codigo en declaraciones locales." << endl;
					cout << "Error de sintaxis en construccion ports." << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// new line
				if (!token.match(TK_NL))
				{
					cout << "[ERROR] Token invalido." << endl;
					cout << "Se esperaba un enter." << endl;
					cout << "Error de sintaxis en declaraciones locales." << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				tok.lockSymbol(wire_id);

				for (i = 0; i < width; i++)
				{
					// inserta buffers
					buf = graph.insertBuf();
					nodes.push_back(buf);
				}

				// asocia el bus al identificador
				tok.annotateSymbolNodes(wire_id, nodes);

				nodes.clear();
			}
			// new line
			else if (token.match(TK_NL))
			{
				// verifica que el identificador no este usado
				if (tok.isSymbolUsed(wire_id))
				{
					cout << "[ERROR] Identificador ya usado." << endl;
					cout << "El identificador del wire no debe \
haberse usado previamente" << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				tok.lockSymbol(wire_id);

				wire.dim = 1;

				// inserta buffer
				buf = graph.insertBuf();
				nodes.push_back(buf);

				// asocia el buffer al identificador
				tok.annotateSymbolNodes(wire_id, nodes);

				nodes.clear();
			}
			// error
			else
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "Las declaraciones locales deben estar \
en una linea." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}
		}
		// reg
		else if (token.match(TK_KW, KW_REG))
		{
			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en declaraciones locales."
						<< endl;
				cout << "reg a :)" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// id
			if (!token.match(TK_ID))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un identificador de reg."
						<< endl;
				cout << "reg id :P" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// rescata identificador del reg
			reg_id = token.getN();

			wire.name = tok.getSymbol(reg_id);
			wire.reg = PORT_LOGIC;

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en declaraciones locales."
						<< endl;
				cout << "reg a :)" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// [
			if (token.match(TK_OP, OP_IX_OP))
			{
				width = dim();

				wire.dim = width;

				if (!tok.getNext(token))
				{
					cout << "[ERROR] Insuficientes tokens." << endl;
					cout << "Final abrupto del codigo en declaraciones locales."
							<< endl;
					cout << "Error de sintaxis en construccion en declaraciones locales."  << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// ]
				if (!token.match(TK_OP, OP_IX_CL))
				{
					cout << "[ERROR] Token invalido." << endl;
					cout << "Se esperaba un token ]."
							<< endl;
					cout << "Desbalanceo de corchetes en en declaraciones locales."  << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				if (!tok.getNext(token))
				{
					cout << "[ERROR] Insuficientes tokens." << endl;
					cout << "Final abrupto del codigo en declaraciones locales." << endl;
					cout << "Error de sintaxis en construccion ports." << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// new line
				if (!token.match(TK_NL))
				{
					cout << "[ERROR] Token invalido." << endl;
					cout << "Se esperaba un enter." << endl;
					cout << "Error de sintaxis en declaraciones locales." << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				// verifica que el identificador no este usado
				if (tok.isSymbolUsed(reg_id))
				{
					cout << "[ERROR] Identificador ya usado." << endl;
					cout << "El identificador del reg no debe \
haberse usado previamente" << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				tok.lockSymbol(reg_id);

				for (i = 0; i < width; i++)
				{
					// inserta registros
					buf = graph.insertReg();
					nodes.push_back(buf);

					// anota registro
					graph.Annotate(buf, reg_id, i);
				}

				// asocia el bus al identificador
				tok.annotateSymbolNodes(reg_id, nodes);

				nodes.clear();
			}
			// new line
			else if (token.match(TK_NL))
			{
				// verifica que el identificador no este usado
				if (tok.isSymbolUsed(reg_id))
				{
					cout << "[ERROR] Identificador ya usado." << endl;
					cout << "El identificador del wire no debe \
haberse usado previamente" << endl;
					cout << "Linea: " << tok.getNLine() << endl;
					exit(1);
				}

				tok.lockSymbol(reg_id);

				wire.dim = 1;

				// inserta buffer
				reg = graph.insertReg();
				nodes.push_back(reg);

				// anota registro
				graph.Annotate(reg, reg_id, -1);

				// asocia el registro al identificador
				tok.annotateSymbolNodes(reg_id, nodes);

				nodes.clear();
			}
			// error
			else
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "Las declaraciones locales deben estar \
en una linea." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}
		}

		if (!throw_nl())
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en declaraciones locales."
					<< endl;
			cout << "Error de sintaxis en declaraciones locales." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		local_table.push_back(wire);
	}
}

///////////////////////////////////////////////////////////
// metodo: desync                                        //
// proposito: desincroniza el grafo.                     //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::desync(void)
{
	char c;
	int llc;
	int lc;
	int port_id;
	int w;
    std::ofstream file;
    std::string path;
    std::string vname;
	std::vector<int> c_latch;
	std::vector<int> fin_bus;
	std::vector<int> fin_ids;
	std::vector<int> fout_bus;
	std::vector<int> fout_ids;
	std::vector<int> latch_bus;
	std::vector<std::vector<int>> cloud;
	std::vector<int> ids;
	std::vector<std::vector<int>> inputs;
	std::vector<std::vector<int>> outputs;
	std::vector<int> l_latch;
	std::vector<int> latches;
	std::vector<std::vector<int>> i2r_paths;
	std::vector<std::vector<int>> r2o_paths;
	Port puerto;

	// clona el grafo del circuito
	degraph = graph;

	// reemplaza los flip-flops por latches
	degraph.Reg2Latch();

	this->m_r2r_paths = graph.getR2RPaths();

    this->m_cloud = degraph.Get_Cloud_Logic(this->m_r2r_paths);

	// inserta latch-controllers en los latches
	latches = degraph.Get_Latch_Ids();

	for (auto l : latches)
	{
		latch_bus = degraph.Get_Latch_From_Id(l);

		lc = degraph.Insert_LC(latch_bus);

		// busca latch de fanin
		fin_bus.clear();

		for (auto p : this->m_r2r_paths)
		{
			for (auto r : latch_bus)
			{
				// toma paths donde el latch coincida
				// con el capture latch
				if (p[p.size() - 1] == r)
				{
					fin_bus.push_back(p[0]);
				}
			}
		}

		fin_ids = degraph.Query_Ids(fin_bus);

		// busca latch de fanout
		fout_bus.clear();

		for (auto p : this->m_r2r_paths)
		{
			for (auto r : latch_bus)
			{
				// toma paths donde el latch coincida
				// con el launching latch
				if (p[0] == r)
				{
					fout_bus.push_back(p[p.size() - 1]);
				}
			}
		}

		fout_ids = degraph.Query_Ids(fout_bus);

		// inserta latch-controller en el meta grafo
		meta_graph.Insert_LC(lc, l, fin_ids, fout_ids);
	}

	meta_graph.Make_Join_Tree();

	meta_graph.Make_Fork_Tree();

	// implementa los arboles de join controllers
	for (int i = 0; i < meta_graph.Query_Join_Tree_Count(); i++)
	{
		int jc;
		BTree *jc_tree;

		jc_tree = meta_graph.Query_Join_Tree(i);

		// arbol de join controllers
		// inserta join controller primario
		if (jc_tree->Get_Node() == -2)
		{
			jc = Insert_JC(jc_tree, meta_graph.Query_LC(i),
							FAN_ACK_LEFT, FAN_REQ_LEFT);
		}
		// no hay arbol de join controllers
		// conexion directa del handshake
		else
		{
		}
	}

	// implementa los arboles de fork controllers
	for (int i = 0; i < meta_graph.Query_Fork_Tree_Count(); i++)
	{
		int fc;
		BTree *fc_tree;

		fc_tree = meta_graph.Query_Fork_Tree(i);

		// arbol de fork controllers
		// inserta fork controller primario
		if (fc_tree->Get_Node() == -2)
		{
			fc = Insert_FC(fc_tree, meta_graph.Query_LC(i),
							FAN_REQ_RIGHT, FAN_ACK_RIGHT);
		}
		// no hay arbol de fork controllers
		// conexion directa del handshake
		else
		{
		}
	}

	// conecta join controllers o latch controllers
	// con fork controllers o latch controllers
	for (auto l : latches)
	{
		// busca los fork controllers o el latch controller
		// para cada latch
		int branch;
		int branch_l;
		int i, j, k;
		int fc;
		int jc;

		i = meta_graph.Find_From_Id(l);

		// obtiene los fanouts
		fout_ids = meta_graph.Get_Fout_Id(i);

		// hay un solo fan-out
		// no hay fork controller tree
		// esta conectado directo al latch controller
		if (fout_ids.size() == 1)
		{
			lc = meta_graph.Query_LC(i);

			j = meta_graph.Find_From_Id(fout_ids[0]);

			jc = meta_graph.Find_JC(j, l, branch);

			// no hay join controller tree
			// esta conectado directo
			// al latch controller
			if (branch == BRANCH_CENTER)
			{
				jc = meta_graph.Query_LC(j);

				w = degraph.drive(lc, FAN_REQ_RIGHT);
				degraph.connect(jc, w, FAN_REQ_LEFT);

				w = degraph.drive(jc, FAN_ACK_LEFT);
				degraph.connect(lc, w, FAN_ACK_RIGHT);
			}
			// conectado al fan in 1 del
			// join controller
			else if (branch == BRANCH_LEFT)
			{
				w = degraph.drive(lc, FAN_REQ_RIGHT);
				degraph.connect(jc, w, FAN_REQ_LEFT_1);

				w = degraph.drive(jc, FAN_ACK_LEFT_1);
				degraph.connect(lc, w, FAN_ACK_RIGHT);
			}
			// conectado al fan in 2 del
			// join controller
			else if (branch == BRANCH_RIGHT)
			{
				w = degraph.drive(lc, FAN_REQ_RIGHT);
				degraph.connect(jc, w, FAN_REQ_LEFT_2);

				w = degraph.drive(jc, FAN_ACK_LEFT_2);
				degraph.connect(lc, w, FAN_ACK_RIGHT);
			}
		}
		// fork controller tree
		else
		{
			lc = meta_graph.Query_LC(i);

			// recorre todos los fan outers del
			// fork controller tree
			for (auto f : fout_ids)
			{
				k = meta_graph.Find_From_Id(l);

				fc = meta_graph.Find_FC(i, f, branch_l);

				j = meta_graph.Find_From_Id(f);

				jc = meta_graph.Find_JC(j, l, branch);

				// no hay join controller tree
				// esta conectado directo
				// al latch controller
				if (branch == BRANCH_CENTER)
				{
					jc = meta_graph.Query_LC(j);

					if (branch_l == BRANCH_LEFT)
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_1);
					}
					else
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_2);
					}

					degraph.connect(jc, w, FAN_REQ_LEFT);

					w = degraph.drive(jc, FAN_ACK_LEFT);

					if (branch_l == BRANCH_LEFT)
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_1);
					}
					else
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_2);
					}
				}
				// conectado al fan in 1 del
				// join controller
				else if (branch == BRANCH_LEFT)
				{
					if (branch_l == BRANCH_LEFT)
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_1);
					}
					else
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_2);
					}

					degraph.connect(jc, w, FAN_REQ_LEFT_1);

					w = degraph.drive(jc, FAN_ACK_LEFT_1);

					if (branch_l == BRANCH_LEFT)
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_1);
					}
					else
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_2);
					}
				}
				// conectado al fan in 2 del
				// join controller
				else if (branch == BRANCH_RIGHT)
				{
					if (branch_l == BRANCH_LEFT)
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_1);
					}
					else
					{
						w = degraph.drive(fc, FAN_REQ_RIGHT_2);
					}

					degraph.connect(jc, w, FAN_REQ_LEFT_2);

					w = degraph.drive(jc, FAN_ACK_LEFT_2);

					if (branch_l == BRANCH_LEFT)
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_1);
					}
					else
					{
						degraph.connect(fc, w, FAN_ACK_RIGHT_2);
					}
				}
			}
		}
	}

	// inserta handshake en los puertos de entrada
	this->m_i2r_paths = graph.Get_I2R_Paths();

	inputs = degraph.Get_Input_Logic(this->m_i2r_paths);

	for (auto c : inputs)
	{
		c_latch = degraph.Get_Capture_Latch_From_Id(c[0]);

		int	w = degraph.queryFanin(c_latch[0], FAN_LE);

		int lc = degraph.queryDriver(w);

		int l_req = degraph.insertPortIn();

		port_id = tok.symbolFindPush("lr_" + tok.getSymbol(c[0]));

		puerto.nodes.clear();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_IN;
		puerto.dim = 1;
		puerto.nodes.push_back(l_req);
		port_table.push_back(puerto);


		degraph.Annotate(l_req, port_id, -1);

		// asocia el bus al identificador
		w = degraph.drive(l_req);

		degraph.connect(lc, w, FAN_REQ_LEFT);

		int l_ack = degraph.insertPortOut();

		port_id = tok.symbolFindPush("la_" + tok.getSymbol(c[0]));

		puerto.nodes.clear();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_OUT;
		puerto.dim = 1;
		puerto.nodes.push_back(l_ack);
		port_table.push_back(puerto);

		w = degraph.drive(lc, FAN_ACK_LEFT);

		degraph.connect(l_ack, w);
	}

	// inserta handshake en los puertos de salida
	this->m_r2o_paths = degraph.Get_R2O_Paths();

	outputs = degraph.Get_Output_Logic(this->m_r2o_paths);

	for (auto c : outputs)
	{
		c_latch = degraph.Get_Launching_Latch_From_Id(c[0]);

		int	w = degraph.queryFanin(c_latch[0], FAN_LE);

		int lc = degraph.queryDriver(w);

		int r_req = degraph.insertPortOut();

		port_id = tok.symbolFindPush("rr_" + tok.getSymbol(c[0]));

		puerto.nodes.clear();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_OUT;
		puerto.dim = 1;
		puerto.nodes.push_back(r_req);
		port_table.push_back(puerto);

		w = degraph.drive(lc, FAN_REQ_RIGHT);

		degraph.connect(r_req, w);

		int r_ack = degraph.insertPortIn();

		port_id = tok.symbolFindPush("ra_" + tok.getSymbol(c[0]));

		puerto.nodes.clear();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_IN;
		puerto.dim = 1;
		puerto.nodes.push_back(r_ack);
		port_table.push_back(puerto);

		w = degraph.drive(r_ack);

		degraph.connect(lc, w, FAN_ACK_RIGHT);
	}

    vname = this->getFullName(filename);
	vname = this->getMainName(vname);
	path = this->getPath(filename);

    /* archivo para generar constraints */
	file.open(path + vname + "_constraints", fstream::out);

    for (auto paths : this->m_r2r_paths)
    {
        file << tok.getSymbol(this->degraph.get_id_annotation(paths[0])) << "[";
        file << this->degraph.get_ix_annotation(paths[0]) << "], ";

        file << tok.getSymbol(this->degraph.get_id_annotation(paths[paths.size() - 1])) << "[";
        file << this->degraph.get_ix_annotation(paths[paths.size() - 1]) << "]";

        file << std::endl;
    }

    file.close();
}

///////////////////////////////////////////////////////////
// metodo: dim                                           //
// proposito: parsing de la dimension de un bus.         //
//            ej:                                        //
//            [W * 2]                                    //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  dimension del bus.                                   //
///////////////////////////////////////////////////////////

int Parser::dim(void)
{
	int d;
	int num_id;
	int param_id;

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (op_token.match(TK_NUM))
	{
		// rescata identificador de la constante
		num_id = op_token.getN();

		d = tok.getNum(num_id);
	}
	// id ( parameter )
	else if (op_token.match(TK_ID))
	{
		// rescata identificador del parametro
		param_id = op_token.getN();

		auto it = params.find(param_id);

		// parametro encontrado
		if (it != params.end())
		{
			d = params[param_id];
		}
		// parametro no encontrado
		else
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Identificador no reconocido como parametro."
					<< endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
	else
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante o identificador."
				<< endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	return d;
}

///////////////////////////////////////////////////////////
// metodo: emit                                          //
// proposito: genera el archivo Verilog.                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  true - generacion exitosa.                           //
//  false - hubo errores durante la generacion.          //
///////////////////////////////////////////////////////////

bool Parser::emit(void)
{
	emt.create(is_async);

	emt.module(tok.getSymbol(block_name));

	emt.ports(port_table, is_async);

	emt.decls(local_table);

	if (tie_hi_used || tie_lo_used)
	{
		emt.ties(tie_hi_used, tie_lo_used);
	}

    if (is_async)
    {
    	emt.body(degraph.getCells(), degraph.getNets());
    }
    else
    {
    	emt.body(graph.getCells(), graph.getNets());
    }

	emt.tail();

	return true;
}

///////////////////////////////////////////////////////////
// metodo: expr                                          //
// proposito: parsing de sentencias de suma y resta.     //
//            ej:                                        //
//            a + b                                      //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::expr(int expc_width)
{
	// gramatica
	// expr := expr + term |
	//			expr +x term |
	//			expr - term |
	//			expr -x term |
	//			term
	int node;
	vector<int> bus;
	vector<int> op2;

	bus = term(expc_width);

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un term o + o +x o - o -x" << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// expr + term o expr +x term o expr - term o expr -x term
	while (op_token.match(TK_OP, OP_ADD) ||
			op_token.match(TK_OP, OP_ADDC) ||
			op_token.match(TK_OP, OP_SUB) ||
			op_token.match(TK_OP, OP_SUBB))
	{
		// expr + term
		if (op_token.match(TK_OP, OP_ADD))
		{
			op2 = term(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una suma." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			node = graph.insertAdder(bus, op2);

			bus = graph.driveBus(node);
		}
		// expr +x term
		else if (op_token.match(TK_OP, OP_ADDC))
		{
			op2 = term(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una suma con acarreo." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			node = graph.insertAdderCout(bus, op2);

			bus = graph.driveBus(node);
		}
		// expr - term
		else if (op_token.match(TK_OP, OP_SUB))
		{
			op2 = term(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una resta." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			node = graph.insertSub(bus, op2);

			bus = graph.driveBus(node);
		}
		// expr -x term
		else if (op_token.match(TK_OP, OP_SUBB))
		{
			op2 = term(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una resta con prestamo." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			node = graph.insertSubBout(bus, op2);

			bus = graph.driveBus(node);
		}

		if (!tok.getNext(op_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera un term o + o +x o - o -x" << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

/********************************************************
 * metodo: f_eval_expr                                  *
 * proposito: parsing de una expresion evaluada.        *
 *            ej:                                       *
 *            i * 8 + j                                 *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion de la expresion.                         *
 ********************************************************/

int Parser::f_eval_expr()
{
	int ix1, ix2;
	Token v_op_token;

	/* gramatica
	 * eval_expr := eval_expr + eval_term |
     *              eval_expr - eval_term |
     *              eval_term
     */
	ix1 = this->f_eval_term();

	if (!tok.getNext(v_op_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Se espera un eval_term o + - ";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* eval_expr + eval_term
     * o eval_expr - eval_term
     */
	while (v_op_token.match(TK_OP, OP_ADD) ||
			v_op_token.match(TK_OP, OP_SUB))
	{
		ix2 = this->f_eval_term();

		/* eval_expr + eval_term */
		if (v_op_token.match(TK_OP, OP_ADD))
		{
			ix1 += ix2;
		}
		/* eval_expr - eval_term */
		else if (v_op_token.match(TK_OP, OP_SUB))
		{
			ix1 -= ix2;
		}

		if (!tok.getNext(v_op_token))
		{
			std::cout << "[ERROR] Insuficientes tokens.";
			std::cout << std::endl;
			std::cout << "Se espera un eval_term o + - ";
			std::cout << std::endl;
			std::cout << "Error de sintaxis en una expresion evaluada.";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}
	}

	tok.retract();

	return ix1;
}

/********************************************************
 * metodo: f_eval_factor                                *
 * proposito: parsing de un factor evaluado.            *
 *            ej:                                       *
 *            i                                         *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion del factor.                              *
 ********************************************************/

int Parser::f_eval_factor()
{
	bool index_found = false;
	uint32_t id;
	int ix;
	uint32_t num_id;

	Token v_ix_token;

	/* gramatica
	 * eval_factor := num |
	 *                id
     *                ( eval_logic )
     */
	if (!tok.getNext(v_ix_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Final abrupto de una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Linea: ";
		std::cout << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* id */
	if (v_ix_token.match(TK_ID))
	{
		/* puede ser un parametro */
		id = v_ix_token.getN();

		if (this->f_find_param(id))
		{
			return this->params[id];
		}

		/* puede ser una constante */
		if (this->f_find_const(id))
		{
			return this->m_constants[id];
		}

		/* busca el indice entre los generate */
		for (int i = 0; i < generate_ids.size(); i++)
		{
			if (generate_ids[i] == id)
			{
				index_found = true;
				ix = i;

				std::cout << "For generate index ";
				std::cout << id;
				std::cout << " = ";
				std::cout << generate_indices[ix];
				std::cout << std::endl;

				break;
			}
		}

		if (!index_found)
		{
			std::cout << "[ERROR] Indice de un generate inexistente.";
			std::cout << std::endl;
			std::cout << "Error de sintaxis en una indexacion.";
			std::cout << std::endl;
			std::cout << "Linea: ";
			std::cout << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}

		return generate_indices[ix];
	}
	/* num */
	else if (v_ix_token.match(TK_NUM))
	{
		num_id = v_ix_token.getN();

		/* obtiene indice */
		ix = tok.getNum(num_id);

		return ix;
	}
	/* ( eval_logic ) */
	else if (v_ix_token.match(TK_OP, OP_PAR_OP))
	{
		ix = this->f_eval_logic();

		if (!tok.getNext(v_ix_token))
		{
			std::cout << "[ERROR] Insuficientes tokens." << std::endl;
			std::cout << "Se esperaba un )." << std::endl;
			std::cout << "Desbalanceo de parentesis." << std::endl;
			std::cout << "Linea: " << tok.getNLine() << std::endl;
			exit(1);
		}

		// )
		if (!v_ix_token.match(TK_OP, OP_PAR_CL))
		{
			std::cout << "[ERROR] Token invalido." << std::endl;
			std::cout << "Se esperaba un )." << std::endl;
			std::cout << "Desbalanceo de parentesis." << std::endl;
			std::cout << "Linea: " << tok.getNLine() << std::endl;
			exit(1);
		}

	}
	else
	{
		std::cout << "[ERROR] Token invalido.";
		std::cout << std::endl;
		std::cout << "Se esperaba una constante.";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una indexacion.";
		std::cout << std::endl;
		std::cout << "Linea: ";
		std::cout << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	return -1;
}

/********************************************************
 * metodo: f_eval_logic                                 *
 * proposito: parsing de una expresion logica.          *
 *            ej:                                       *
 *            i > 0 and i < 3                           *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion de la expresion.                         *
 ********************************************************/

int Parser::f_eval_logic()
{
	int ix1, ix2;
	Token v_op_token;

	/* gramatica
	 * eval_expr := eval_logic and eval_rel |
     *              eval_rel
     */
	ix1 = this->f_eval_rel();

	if (!tok.getNext(v_op_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Se espera un eval_rel o and";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* eval_logic and eval_rel |
     * eval_rel
     */
	while (v_op_token.match(TK_KW, KW_AND))
	{
		ix2 = this->f_eval_rel();

		/* eval_rel and eval_expr */
		if (v_op_token.match(TK_KW, KW_AND))
		{
			ix1 = (ix1 & ix2);
		}

		if (!tok.getNext(v_op_token))
		{
			std::cout << "[ERROR] Insuficientes tokens.";
			std::cout << std::endl;
			std::cout << "Se espera un eval_rel o and";
			std::cout << std::endl;
			std::cout << "Error de sintaxis en una expresion evaluada.";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}
	}

	tok.retract();

	return ix1;
}

/********************************************************
 * metodo: f_eval_rel                                   *
 * proposito: parsing de una expresion relacional.      *
 *            ej:                                       *
 *            i < 7                                     *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion de la expresion.                         *
 ********************************************************/

int Parser::f_eval_rel()
{
	int ix1, ix2;
	Token v_op_token;

	/* gramatica
	 * eval_expr := eval_rel < eval_expr |
     *              eval_expr
     */
	ix1 = this->f_eval_expr();

	if (!tok.getNext(v_op_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Se espera un eval_term o + - ";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* eval_rel < eval_expr |
     * eval_rel <= eval_expr
     * eval_rel > eval_expr |
     * eval_rel >= eval_expr |
     * eval_rel == eval_expr |
     * eval_rel
     */
	while (v_op_token.match(TK_OP, OP_CP_LW) ||
            v_op_token.match(TK_OP, OP_CP_LWEQ) ||
            v_op_token.match(TK_OP, OP_CP_GR) ||
            v_op_token.match(TK_OP, OP_CP_GREQ) ||
            v_op_token.match(TK_OP, OP_CP_NEQ) ||
            v_op_token.match(TK_OP, OP_CP_EQ))
	{
		this->m_generate_rel_flags.back() = true;

		ix2 = this->f_eval_expr();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "eval term 2 " << ix2;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "token operator ";
		v_op_token.print();
		std::cout << std::endl;
		std::cout << std::endl;


		/* eval_rel < eval_expr */
		if (v_op_token.match(TK_OP, OP_CP_LW))
		{
			ix1 = (ix1 < ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		/* eval_rel <= eval_expr */
		else if (v_op_token.match(TK_OP, OP_CP_LWEQ))
		{
			ix1 = (ix1 <= ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		/* eval_rel > eval_expr */
		else if (v_op_token.match(TK_OP, OP_CP_GR))
		{
			ix1 = (ix1 > ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		/* eval_rel >= eval_expr */
		else if (v_op_token.match(TK_OP, OP_CP_GREQ))
		{
			ix1 = (ix1 >= ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		/* eval_rel == eval_expr */
		else if (v_op_token.match(TK_OP, OP_CP_EQ))
		{
			ix1 = (ix1 == ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		/* eval_rel != eval_expr */
		else if (v_op_token.match(TK_OP, OP_CP_NEQ))
		{
			ix1 = (ix1 != ix2);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "eval add " << ix1;
			std::cout << std::endl;
			std::cout << std::endl;
		}

		if (!tok.getNext(v_op_token))
		{
			std::cout << "[ERROR] Insuficientes tokens.";
			std::cout << std::endl;
			std::cout << "Se espera un eval_term o + - ";
			std::cout << std::endl;
			std::cout << "Error de sintaxis en una expresion evaluada.";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}
	}

	tok.retract();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "eval expr " << ix1;
	std::cout << std::endl;
	std::cout << std::endl;

	return ix1;
}

/********************************************************
 * metodo: f_eval_term                                  *
 * proposito: parsing de un termino evaluado.           *
 *            ej:                                       *
 *            i * 8                                     *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion del termino.                             *
 ********************************************************/

int Parser::f_eval_term()
{
	int ix1, ix2;

	Token v_op_token;

	/* gramatica
	 * eval_term := eval_term * eval_unary |
     *              eval_term / eval_unary |
     *              eval_unary
     */
	ix1 = this->f_eval_unary();

	if (!tok.getNext(v_op_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Se espera un eval_unary o + - ";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una expresion evaluada.";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* eval_term * eval_unary
     * o eval_term / eval_unary
     */
	while (v_op_token.match(TK_OP, OP_MULT) ||
			v_op_token.match(TK_OP, OP_DIV))
	{
		ix2 = this->f_eval_unary();

		/* eval_term + eval_unary */
		if (v_op_token.match(TK_OP, OP_MULT))
		{
			ix1 *= ix2;
		}
		/* eval_term / eval_unary */
		else if (v_op_token.match(TK_OP, OP_DIV))
		{
			ix1 /= ix2;
		}

		if (!tok.getNext(v_op_token))
		{
			std::cout << "[ERROR] Insuficientes tokens.";
			std::cout << std::endl;
			std::cout << "Se espera un eval_unary o + - ";
			std::cout << std::endl;
			std::cout << "Error de sintaxis en una expresion evaluada.";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}
	}

	tok.retract();

	return ix1;
}

/********************************************************
 * metodo: f_eval_unary                                 *
 * proposito: parsing de un unary evaluado.             *
 *            ej:                                       *
 *            +i                                        *
 * parametros:                                          *
 *  ninguno.                                            *
 * devuelve:                                            *
 *  evaluacion del unary.                               *
 ********************************************************/

int Parser::f_eval_unary()
{
	/* gramatica
	 * eval_unary := -eval_factor |
	 *			     + eval_factor |
	 *			     eval_factor
     */
	int net;
	int node;
	vector<int> bus;
	vector<int> rvalue;

	Token v_token;

	if (!tok.getNext(v_token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Se espera un eval_factor o eval_unary.";
		std::cout << std::endl;
		std::cout << "Error de sintaxis en una indexacion.";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* + eval_factor */
	if (v_token.match(TK_OP, OP_ADD))
	{
		return this->f_eval_factor();
	}
	/* - eval_factor */
	else if (v_token.match(TK_OP, OP_SUB))
	{
		return -this->f_eval_factor();
	}
	/* eval_factor */
	else
	{
		tok.retract();

		return this->f_eval_factor();
	}
}

///////////////////////////////////////////////////////////
// metodo: factor                                        //
// proposito: parsing de factores.                       //
//            ej:                                        //
//            a                                          //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::factor(int expc_width)
{
	// gramatica
	// factor := id | num
	int net;
	vector<int> nodes;
	vector<int> rvalue;

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un factor." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (token.match(TK_ID))
	{
		nodes = getNodes(token.getN());

		// verifica que el identificador este declarado
		if (nodes.size() == 0)
		{
			cout << "[ERROR] Identificador no declarado." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se esperaba un new line o un [." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// [ indexacion
		if (token.match(TK_OP, OP_IX_OP))
		{
			rvalue = offset(nodes);

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Se esperaba un ]." << endl;
				cout << "Error de sintaxis en una sentencia." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// ]
			if (!token.match(TK_OP, OP_IX_CL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un ]." << endl;
				cout << "Desbalanceo de corchetes." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}
		}
		// id sin indexar
		else
		{
			tok.retract();

			for (auto &n: nodes)
			{
				net = graph.drive(n);

				rvalue.push_back(net);
			}
		}

		return rvalue;
	}
	// num
	else if (token.match(TK_NUM))
	{
		nodes = tok.dec2Bin(tok.getNum(token.getN()),
							expc_width);

		for (auto &n: nodes)
		{
			// usa tie hi
			if (n)
			{
				tie_hi_used = true;
			}
			// usa tie lo
			else
			{
				tie_lo_used = true;
			}

			net = graph.drive(n);

			rvalue.push_back(net);
		}

		return rvalue;
	}
	// (
	else if (token.match(TK_OP, OP_PAR_OP))
	{
		rvalue = concatenation(expc_width);

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se esperaba un )." << endl;
			cout << "Desbalanceo de parentesis." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// )
		if (!token.match(TK_OP, OP_PAR_CL))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un )." << endl;
			cout << "Desbalanceo de parentesis." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		return rvalue;
	}
	// error
	else
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un id o un num." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}
}

/*********************************************************
 * metodo: f_find_const                                  *
 * proposito: determina si existe una constante.         *
 * parametros:                                           *
 *  id - id de la constante.                             *
 * devuelve:                                             *
 *  true - la constante existe.                          *
 *  false - la constante no existe.                      *
 *********************************************************/

bool Parser::f_find_const(uint32_t id)
{
	if (this->m_constants.find(id) == this->m_constants.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*********************************************************
 * metodo: f_find_param                                  *
 * proposito: determina si existe un parametro.          *
 * parametros:                                           *
 *  id - id del parametro.                               *
 * devuelve:                                             *
 *  true - el parametros existe.                         *
 *  false - el parametos no existe.                      *
 *********************************************************/

bool Parser::f_find_param(uint32_t id)
{
	if (this->params.find(id) == this->params.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

///////////////////////////////////////////////////////////
// metodo: for_generate                                  //
// proposito: parsing de un for generate.                //
//            for i in range(0, 7):                      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::for_generate(void)
{
	int index_id;
	int ix1, ix2;
	int num_id;

	// gramatica
	// forgenerate := for id in range ( num , num ) :
    //                nl_list begin nl_list stmts end

	// id
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (!token.match(TK_ID))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un identificador de indice."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// rescata identificador del indice
	index_id = token.getN();

	// verifica que el identificador no este usado
	if (tok.isSymbolUsed(index_id))
	{
		cout << "[ERROR] Identificador ya usado." << endl;
		cout << "El identificador del indice no debe \
haberse usado previamente" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	/* bloquea el uso del simbolo para que no lo
     * redeclaren dentro del for
     */
	tok.lockSymbol(index_id);
	tok.set_type(index_id, E_TYPE_ITER_INDEX);

	// in
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// in
	if (!token.match(TK_KW, KW_IN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba keyword in."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// range
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// range
	if (!token.match(TK_KW, KW_RANGE))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba keyword range."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// (
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// (
	if (!token.match(TK_OP, OP_PAR_OP))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba (."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (!tok.getNext(ix1_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (!ix1_token.match(TK_NUM))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	num_id = ix1_token.getN();

	// obtiene indice
	ix1 = tok.getNum(num_id);

	// ,
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// ,
	if (!token.match(TK_OP, OP_COMMA))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba ,."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (!tok.getNext(ix2_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (!ix2_token.match(TK_NUM))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	num_id = ix2_token.getN();

	// obtiene indice
	ix2 = tok.getNum(num_id);

	// )
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// )
	if (!token.match(TK_OP, OP_PAR_CL))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba )."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// :
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// :
	if (!token.match(TK_OP, OP_RANGE))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba :."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// ix1 > ix2
	if (ix1 > ix2)
	{
		cout << "[ERROR] Indices incorrectos." << endl;
		cout << "Debe ir de menor a mayor." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba keyword begin."  << endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;

		token.print();
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	tok.retract();
	tok.recovery_point();

	// when
	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en un for."
				<< endl;
		cout << "for i in range (0, 7): :)" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	/* when
     * for generate condicional
     */
	if (token.match(TK_KW, KW_WHEN))
	{
		tok.retract();

		/* for generate condicionado por whens
         * recibe como argumentos al rango del indice
         * y el identificador ( el nombre )
         */
		f_generate_conditional(index_id, ix1, ix2);
	}
	/* for generate incondicional */
	else
	{
		for (int ix = ix1; ix <= ix2; ix++)
		{
			std::cout << "-for generate ";
			std::cout << std::endl;

			generate_ids.push_back(index_id);
			generate_indices.push_back(ix);

			tok.restore();
			tok.recovery_point();

			stmts();

			std::cout << "-stmts end ";
			std::cout << std::endl;

			generate_ids.pop_back();
			generate_indices.pop_back();
		}
	}

	/* libera el uso del simbolo.
     * Solo esta bloqueado dentro del alcance del for.
     */
	tok.unlock_symbol(index_id);

	tok.restore();
}

/**********************************************************
 * metodo: f_generate_condition                           *
 * proposito: parsing de la condicion de un when.         *
 *            when 0:                                     *
 *                a[i] = 0                                *
 *                end                                     *
 * parametros:                                            *
 *  index_id - identificador del indice.                  *
 *  ix1 - valor inicial del indice.                       *
 *  ix2 - valor final del indice.                         *
 *  ix_matches - valores que satisfacen la condicion.     *
 *               ( por referencia ).                      *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Parser::f_generate_condition(int index_id,
                                    int ix1,
									int ix2,
									std::vector<int> &ix_matches)
{
	int ix;

	tok.recovery_point();

	/* recorre todo los indice por si se trata de un rango */
	for (int i = ix1; i <= ix2; i++)
	{
		tok.restore();
    	tok.recovery_point();

	    generate_ids.push_back(index_id);
	    generate_indices.push_back(i);

		ix = this->f_eval_logic();

		generate_ids.pop_back();
		generate_indices.pop_back();

		/* es un rango */
		if (this->m_generate_rel_flags.back())
		{
            /* la condicion retorno true */
            if (ix)
            {
    			ix_matches.push_back(i);
            }
		}
		/* es un numero constante */
		else
		{
			ix_matches.push_back(ix);

			break;
		}
	}

	/* : */
	if (!tok.getNext(token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Final abrupto del codigo en un for.";
		std::cout << std::endl;
		std::cout << "for i in range (0, 7): :)";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* : */
	if (!token.match(TK_OP, OP_RANGE))
	{
		std::cout << "[ERROR] Token invalido.";
		std::cout << std::endl;
		std::cout << "Se esperaba :.";
		std::cout << std::endl;
		std::cout << "for i in range (0, 7): :)";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}
}

/**********************************************************
 * metodo: f_generate_conditional                         *
 * proposito: parsing de un for generate condicionado por *
 *            whens.                                      *
 *            ej:                                         *
 *            for i in range(0, 1):                       *
 *            begin                                       *
 *                when 0:                                 *
 *                    a[i] = 0                            *
 *                    end                                 *
 *                when 1:                                 *
 *                    a[i] = 1                            *
 *                    end                                 *
 *            end                                         *
 * parametros:                                            *
 *  index_id - identificador del indice.                  *
 *  ix1 - valor inicial del indice.                       *
 *  ix2 - valor final del indice.                         *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Parser::f_generate_conditional(int index_id, int ix1, int ix2)
{
	/* gramatica
	 * generate_conditional := when generate_condition : nl_list stmts |
     *                         when others: nl_list stmts
	 */
	bool v_index_used[ix2];
	std::vector<int> ix_matches;

	/* por el momento ningun indice fue usado */
	for (int i = ix1; i <= ix2; i++)
	{
		v_index_used[i] = false;
	}

	/* when o end */
	if (!tok.getNext(token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Final abrupto del codigo en un when.";
		std::cout << std::endl;
		std::cout << "when 0: :)";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* solo el end para el for generate */
	while (!token.match(TK_KW, KW_END))
	{
		/* ahora solo admitimos when */
		if (!token.match(TK_KW, KW_WHEN))
		{
			std::cout << "[ERROR] Token invalido.";
			std::cout << std::endl;
			std::cout << "Se esperaba keyword when.";
			std::cout << std::endl;
			std::cout << "when 0: :)";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;

			token.print();
			exit(1);
		}

		/* others */
		if (!tok.getNext(token))
		{
			std::cout << "[ERROR] Insuficientes tokens.";
			std::cout << std::endl;
			std::cout << "Final abrupto del codigo en un when.";
			std::cout << std::endl;
			std::cout << "when 0: :)";
			std::cout << std::endl;
			std::cout << "Linea: " << tok.getNLine();
			std::cout << std::endl;
			exit(1);
		}

		/* puede ser others */
		if (token.match(TK_KW, KW_OTHERS))
		{
			/* : */
			if (!tok.getNext(token))
			{
				std::cout << "[ERROR] Insuficientes tokens.";
				std::cout << std::endl;
				std::cout << "Final abrupto del codigo en un for.";
				std::cout << std::endl;
				std::cout << "for i in range (0, 7): :)";
				std::cout << std::endl;
				std::cout << "Linea: " << tok.getNLine();
				std::cout << std::endl;
				exit(1);
			}

			/* : */
			if (!token.match(TK_OP, OP_RANGE))
			{
				std::cout << "[ERROR] Token invalido.";
				std::cout << std::endl;
				std::cout << "Se esperaba :.";
				std::cout << std::endl;
				std::cout << "for i in range (0, 7): :)";
				std::cout << std::endl;
				std::cout << "Linea: " << tok.getNLine();
				std::cout << std::endl;
				exit(1);
			}

			tok.getNext(token);

			tok.recovery_point();

			std::cout << "-when others " << ix1 << " to " << ix2;
			std::cout << std::endl;

			/* recorre cada indice no usado */
			for (int ix = ix1; ix <= ix2; ix++)
			{
				if (!v_index_used[ix])
				{
				    tok.restore();
				    tok.recovery_point();

					generate_ids.push_back(index_id);
					generate_indices.push_back(ix);

					stmts();

					generate_ids.pop_back();
					generate_indices.pop_back();
				}
			}
		}
		/* condicion que activa el when */
		else
		{
			tok.retract();

			ix_matches.clear();

			this->m_generate_rel_flags.push_back(false);

			f_generate_condition(index_id, ix1, ix2, ix_matches);

			this->m_generate_rel_flags.pop_back();

			tok.getNext(token);

			tok.recovery_point();

			/* recorre cada indice de la condicion */
			for (auto ix : ix_matches)
			{
				tok.restore();
				tok.recovery_point();

				std::cout << "index match " << ix;
				std::cout << std::endl;

				generate_ids.push_back(index_id);
				generate_indices.push_back(ix);

				stmts();

				generate_ids.pop_back();
				generate_indices.pop_back();

				v_index_used[ix] = true;
			}
		}
		/* when o end */
		if (!throw_nl())
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion block."
					<< endl;
			cout << "No define un block." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
}

/**********************************************************
 * metodo: f_generate_factor                              *
 * proposito: parsing de un factor de la condicion que    *
 *            activa el when.                             *
 *            when 0:                                     *
 *                a[i] = 0                                *
 *                end                                     *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  valor del indice.                                     *
 *********************************************************/

int Parser::f_generate_factor()
{
	int d;
	int num_id;

	/* num */
	if (!tok.getNext(token))
	{
		std::cout << "[ERROR] Insuficientes tokens.";
		std::cout << std::endl;
		std::cout << "Final abrupto del codigo en un when.";
		std::cout << std::endl;
		std::cout << "when 0: :)";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* num */
	if (!token.match(TK_NUM))
	{
		std::cout << "[ERROR] Token invalido.";
		std::cout << std::endl;
		std::cout << "Se esperaba :.";
		std::cout << std::endl;
		std::cout << "when 0: :)";
		std::cout << std::endl;
		std::cout << "Linea: " << tok.getNLine();
		std::cout << std::endl;
		exit(1);
	}

	/* rescata identificador de la constante */
	num_id = token.getN();

	std::cout << "num id" << num_id;
	std::cout << std::endl;

	d = tok.getNum(num_id);

	std::cout << "index match " << d;
	std::cout << std::endl;

	return d;
}

/*********************************************************
 * metodo: getFullName                                   *
 * proposito: obtiene el nombre completo del archivo.    *
 * argumentos:                                           *
 *  name - nombre del archivo con su ruta.               *
 * devuelve:                                             *
 *  nombre del archivo.                                  *
 *********************************************************/

std::string Parser::getFullName(std::string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != std::string::npos)
	{
		return (name.substr(i + 1, name.length() - i));
	}

	return ("");
}

/*********************************************************
 * metodo: getMainName                                   *
 * proposito: obtiene el nombre principal del archivo.   *
 * argumentos:                                           *
 *  name - nombre del archivo con extension.             *
 * devuelve:                                             *
 *  nombre del archivo.                                  *
 *********************************************************/

std::string Parser::getMainName(std::string name)
{
	size_t i = name.rfind('.', name.length());

	if (i != std::string::npos)
	{
		return (name.substr(0, i));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getNodes                                      //
// proposito: obtiene los numeros de nodos de un         //
//            identificador.                             //
// argumentos:                                           //
//  id - numero de identificador.                        //
// devuelve:                                             //
//  vector con los numeros de nodos.                     //
///////////////////////////////////////////////////////////

vector<int> Parser::getNodes(int id)
{
	vector<int> nodes;

	nodes = tok.getNodes(id);

	return nodes;
}

/*********************************************************
 * metodo: getPath                                       *
 * proposito: obtiene la ruta del archivo.               *
 * argumentos:                                           *
 *  name - nombre del archivo.                           *
 * devuelve:                                             *
 *  ruta del archivo.                                    *
 *********************************************************/

std::string Parser::getPath(std::string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != std::string::npos)
	{
		return (name.substr(0, i + 1));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: init                                          //
// proposito: inicializaccion del parser.                //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::init(void)
{
	// agrega tie cells
	// Tie Low = cell 0
	// Tie High = cell 1
	graph.insertTieLo();
	graph.insertTieHi();

	// tie cells aun no usadas
	tie_hi_used = false;
	tie_lo_used = false;
}

///////////////////////////////////////////////////////////
// metodo: inputs                                        //
// proposito: parsing de la definicion puertos de        //
//            entrada.                                   //
//            ej:                                        //
//            input logic en                             //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::inputs(void)
{
	int i;
	int in;
	int port_id;
	int width;
	vector<int> nodes;
	Port puerto;
	// gramatica
	// inputs := nl_list input logic id |
	//           nl_list input logic id[dim] |
	// dim := num | id
	// nl_list = nl_list newline | e

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// logic
	if (!token.match(TK_KW, KW_LOGIC))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token logic." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (!token.match(TK_ID))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un identificador de port."
				<< endl;
		cout << "input port id :P" << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// rescata identificador del puerto
	port_id = token.getN();

	puerto.name = tok.getSymbol(port_id);
	puerto.dir = PORT_IN;

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// [
	if (token.match(TK_OP, OP_IX_OP))
	{
		width = dim();

		puerto.dim = width;

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
	ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// ]
		if (!token.match(TK_OP, OP_IX_CL))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un token ]."
					<< endl;
			cout << "Desbalanceo de corchetes en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// new line
		if (!token.match(TK_NL))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un enter." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// verifica que el identificador no este usado
		if (tok.isSymbolUsed(port_id))
		{
			cout << "[ERROR] Identificador ya usado." << endl;
			cout << "El identificador del puerto no debe \
haberse usado previamente" << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		tok.lockSymbol(port_id);

		for (i = 0; i < width; i++)
		{
			// inserta puerto de entrada
			in = graph.insertPortIn();
			nodes.push_back(in);
			puerto.nodes.push_back(in);

			graph.Annotate(in, port_id, i);
		}

		// asocia el bus al identificador
		tok.annotateSymbolNodes(port_id, nodes);
	}
	// new line
	else if (token.match(TK_NL))
	{
		// verifica que el identificador no este usado
		if (tok.isSymbolUsed(port_id))
		{
			cout << "[ERROR] Identificador ya usado." << endl;
			cout << "El identificador del puerto no debe \
haberse usado previamente" << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		tok.lockSymbol(port_id);

		// inserta puerto de entrada
		in = graph.insertPortIn();
		nodes.push_back(in);
		puerto.nodes.push_back(in);

		graph.Annotate(in, port_id, -1);

		// asocia el bus al identificador
		tok.annotateSymbolNodes(port_id, nodes);

		puerto.dim = 1;
	}
	// error
	else
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un enter." << endl;
		cout << "La declaracion de un puerto debe estar \
en una linea." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	port_table.push_back(puerto);
}

///////////////////////////////////////////////////////////
// metodo: Insert_FC                                     //
// proposito: inserta fork controllers en forma          //
//            recursiva.                                 //
// argumentos:                                           //
//  fc_tree - arbol de fork controllers.                 //
//  lc - latch controller.                               //
//  fout_u2d - fanout upstream->downstream.              //
//  fin_d2u - fanin downstream->upstream.                //
// devuelve:                                             //
//  numero de celda fork controller que encabeza el      //
//  arbol.                                               //
///////////////////////////////////////////////////////////

int Parser::Insert_FC(BTree *fc_tree, int lc, int fout_u2d,
						int fin_d2u)
{
	int n;
	int w;

	if (fc_tree->Get_Node() == -2)
	{
		n = degraph.Insert_FC(lc);
		fc_tree->Set_Cell(n);

		w = degraph.drive(lc, fout_u2d);
		degraph.connect(n, w, FAN_REQ_LEFT);

		w = degraph.drive(n, FAN_ACK_LEFT);
		degraph.connect(lc, w, fin_d2u);

		Insert_FC(fc_tree->Get_Left(), n,
			FAN_REQ_RIGHT_1, FAN_ACK_RIGHT_1);

		Insert_FC(fc_tree->Get_Right(), n,
			FAN_REQ_RIGHT_2, FAN_ACK_RIGHT_2);
	}
}

///////////////////////////////////////////////////////////
// metodo: Insert_JC                                     //
// proposito: inserta join controllers en forma          //
//            recursiva.                                 //
// argumentos:                                           //
//  jc_tree - arbol de join controllers.                 //
//  lc - latch controller.                               //
//  fout_u2d - fanout upstream->downstream.              //
//  fin_d2u - fanin downstream->upstream.                //
// devuelve:                                             //
//  numero de celda join controller que encabeza el      //
//  arbol.                                               //
///////////////////////////////////////////////////////////

int Parser::Insert_JC(BTree *jc_tree, int lc, int fout_u2d,
						int fin_d2u)
{
	int n;
	int w;

	if (jc_tree->Get_Node() == -2)
	{
		n = degraph.Insert_JC(lc);
		jc_tree->Set_Cell(n);

		w = degraph.drive(lc, fout_u2d);
		degraph.connect(n, w, FAN_ACK_RIGHT);

		w = degraph.drive(n, FAN_REQ_RIGHT);
		degraph.connect(lc, w, fin_d2u);

		Insert_JC(jc_tree->Get_Left(), n,
			FAN_ACK_LEFT_1, FAN_REQ_LEFT_1);

		Insert_JC(jc_tree->Get_Right(), n,
			FAN_ACK_LEFT_2, FAN_REQ_LEFT_2);
	}
}

///////////////////////////////////////////////////////////
// metodo: leftValue                                     //
// proposito: parsing del left value.                    //
//            ej:                                        //
//            a                                          //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::leftValue(void)
{
	uint32_t v_ix1, v_ix2;
	std::vector<int> nodes;
	std::vector<int> lvalue;

	/* gramatica
	 * leftvalue := id |
     *              id [ num ] |
     *              id [ num : num ]
     */
	tok.getNext(token);

	// rescata identificador del left value
	nodes = getNodes(token.getN());

	// verifica que el identificador este declarado
	if (nodes.size() == 0)
	{
		cout << "[ERROR] Identificador no declarado." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se esperaba un new line o un [." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// [ indexacion
	if (token.match(TK_OP, OP_IX_OP))
	{
		/* rescata primer indice */
		v_ix1 = this->f_eval_expr();

		std::cout << std::endl;
		std::cout << "offset";
		std::cout << std::endl;
		std::cout << v_ix1;
		std::cout << std::endl;

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se esperaba un ]." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		/* : */
		if (token.match(TK_OP, OP_RANGE))
		{
			/* rescata segundo indice */
			v_ix2 = this->f_eval_expr();

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Se esperaba un ]." << endl;
				cout << "Error de sintaxis en una sentencia." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			if (!token.match(TK_OP, OP_IX_CL))
			{
				std::cout << "[ERROR] Token invalido." << endl;
				std::cout << "Se esperaba un ]." << endl;
				std::cout << "Desbalanceo de corchetes." << endl;
				std::cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			/* ix1 > ix2 */
			if (v_ix1 <= v_ix2)
			{
				std::cout << "[ERROR] Indices incorrectos." << std::endl;
				std::cout << "El MSb debe ser mayor al LSb." << std::endl;
				std::cout << "Error de sintaxis en una indexacion." << std::endl;
				std::cout << "Linea: " << tok.getNLine() << std::endl;
				exit(1);
			}

			for (int i = v_ix2; i <= v_ix1; i++)
			{
				lvalue.push_back(nodes[i]);
			}
		}
		/* ]
         * indexa un solo bit
         */
		else if (token.match(TK_OP, OP_IX_CL))
		{
			lvalue.push_back(nodes[v_ix1]);
		}
		else
		{
			std::cout << "[ERROR] Token invalido." << endl;
			std::cout << "Se esperaba un ]." << endl;
			std::cout << "Desbalanceo de corchetes." << endl;
			std::cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
	else
	{
		tok.retract();

		for (auto &n: nodes)
		{
			lvalue.push_back(n);
		}
	}

	return lvalue;
}

///////////////////////////////////////////////////////////
// metodo: left_value_offset                             //
// proposito: parsing de la indexacion de un left value. //
//            ej:                                        //
//            a[3]                                       //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::left_value_offset(vector<int> bus)
{
	bool index_found = false;
	int id;
	int ix;
	int net;
	int num_id;
	vector<int> elem;

	// gramatica
	// left_value_offset := num |
    //                      id
	if (!tok.getNext(ix1_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto de una indexacion." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (ix1_token.match(TK_ID))
	{
		id = ix1_token.getN();

		/* busca el indice entre los generate */
		for (int i = 0; i < generate_ids.size(); i++)
		{
			if (generate_ids[i] == id)
			{
				index_found = true;
				ix = i;

				std::cout << "For generate index ";
				std::cout << id;
				std::cout << " = ";
				std::cout << generate_indices[ix];
				std::cout << std::endl;

				break;
			}
		}

		if (!index_found)
		{
			cout << "[ERROR] Indice de un generate inexistente." << endl;
			cout << "Error de sintaxis en una indexacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		net = bus[generate_indices[ix]];

		elem.push_back(net);

		return elem;
	}
	// num
	else if (!ix1_token.match(TK_NUM))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	num_id = ix1_token.getN();

	// obtiene indice
	ix = tok.getNum(num_id);

	// indice fuera de rango
	if (ix >= bus.size())
	{
		cout << "[ERROR] Indice fuera de rango." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	net = bus[ix];

	elem.push_back(net);

	return elem;
}

///////////////////////////////////////////////////////////
// metodo: logical                                       //
// proposito: parsing de sentencias logicas.             //
//            ej:                                        //
//            a and b                                    //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::logical(int expc_width)
{
	// gramatica
	// logical := logical and rel |
	//            logical or rel |
	//            logical xor rel |
	//            logical xnor rel |
	//            rel
	int node;
	vector<int> bus;
	vector<int> op2;

	bus = rel(expc_width);

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un rel o and" << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// logical and rel o logical or rel o logical xor rel
	// o logical xnor rel
	while (op_token.match(TK_KW, KW_AND) ||
			op_token.match(TK_KW, KW_OR) ||
			op_token.match(TK_KW, KW_XOR) ||
			op_token.match(TK_KW, KW_XNOR))
	{
		// logical and rel
		if (op_token.match(TK_KW, KW_AND))
		{
			op2 = rel(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una operacion logica." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			bus = graph.insertAnd2(bus, op2);
		}
		// logical or rel
		else if (op_token.match(TK_KW, KW_OR))
		{
			op2 = rel(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una operacion logica." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			bus = graph.insertOr2(bus, op2);
		}
		// logical xor rel
		else if (op_token.match(TK_KW, KW_XOR))
		{
			op2 = rel(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una operacion logica." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			bus = graph.insertXor2(bus, op2);
		}
		// logical xnor rel
		else if (op_token.match(TK_KW, KW_XNOR))
		{
			op2 = rel(expc_width);

			// verifica que las longitudes de palabra
			// de los operandos coincidan
			if (!widthCheck(bus, op2))
			{
				cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
				cout << "En una operacion logica." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			bus = graph.insertXnor2(bus, op2);
		}

		if (!tok.getNext(op_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera un rel o and" << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: makeTree                                      //
// proposito: completa arbol de multiplexores.           //
// argumentos:                                           //
//  fanin - net a conectar.                              //
//  node - nodo raiz.                                    //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::makeTree(int fanin, int node)
{
	int i;
	int m;
	int net;
	Env b;
	vector<int> chain;

	cout << "Make Tree" << endl << endl;

	cout << "Environment list" << endl;

	for (auto &s : env)
	{
//		cout << "Selector Node " << s.node << endl;
	}

	// consulta si ya existe parte del arbol de mux
	net = graph.queryFanin(node, 0);
	// no existe el arbol de mux
	if (net == -1)
	{
		cout << "Mux Tree creando" << endl;

		// proviene de un if
		if (!env[0].is_case)
		{
			net = graph.drive((env[0].node)[0]);
			m = graph.insertMux2(net);
			net = graph.drive(m);
			graph.connect(node, net);

			node = m;

			chain.push_back(node);
		}
	}
	// ya existe el arbol de mux
	else
	{
		cout << "Mux Tree existe. Explorando." << endl;
		// se posiciona en el mux root
		node = graph.queryDriver(net);

		chain.push_back(node);
	}

	// recorre el arbol de mux
	for (i = 0; i < env.size(); i++)
	{
		b = env[i];

		// en la etapa mas profunda no se hace nada
		// solo se conecta
		if (i != env.size() - 1)
		{
			// proviene de un if
			if (!b.is_case)
			{
				// true
				if (b.data_in == 0)
				{
					// consulta si ya existe parte del arbol de mux
					net = graph.queryFanin(node, 1);
				}
				// false
				else
				{
					// consulta si ya existe parte del arbol de mux
					net = graph.queryFanin(node, 2);
				}

				b = env[i + 1];

				if (net == -1)
				{


					net = graph.drive(b.node[0]);
					m = graph.insertMux2(net);
					net = graph.drive(m);
					graph.connect(node, net);

					node = m;

					chain.push_back(node);
				}
				else
				{
					// se sumerge en el arbol
					node = graph.queryDriver(net);
					chain.push_back(node);
				}
			}
		}
	}

	for (auto &n : chain)
	{
		cout << n << " -> ";
	}

	graph.connect(node, fanin);

	cout << endl;
}

///////////////////////////////////////////////////////////
// metodo: makeTree                                      //
// proposito: completa arbol de multiplexores de buses.  //
// argumentos:                                           //
//  fanin - bus a conectar.                              //
//  node - bus de nodos raices.                          //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::makeTree(vector<int> fanin, vector<int> node)
{
	for (int i = 0; i < fanin.size(); i++)
	{
		// completa arbol de multiplexores
		makeTree(fanin[i], node[i]);
	}
}

///////////////////////////////////////////////////////////
// metodo: offset                                        //
// proposito: parsing de un indice.                      //
//            ej:                                        //
//            a[3]                                       //
// argumentos:                                           //
//  bus - bus a indexar.                                 //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::offset(vector<int> bus)
{
	bool index_found = false;
	int id;
	int ix;
	int net;
	int num_id;
	vector<int> elem;
	Token v_token;

	// gramatica
	// offset := id | num | slicing
	ix = this->f_eval_expr();

/*	if (!tok.getNext(ix1_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto de una indexacion." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// id
	if (ix1_token.match(TK_ID))
	{
		id = ix1_token.getN();

		/* busca el indice entre los generate */
/*		for (int i = 0; i < generate_ids.size(); i++)
		{
			if (generate_ids[i] == id)
			{
				index_found = true;
				ix = i;

				std::cout << "For generate index ";
				std::cout << id;
				std::cout << std::endl;

				break;
			}
		}

		if (!index_found)
		{
			cout << "[ERROR] Indice de un generate inexistente." << endl;
			cout << "Error de sintaxis en una indexacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		net = bus[generate_indices[ix]];

		net = graph.drive(net);

		elem.push_back(net);

		return elem;
	}

	// num
	if (!ix1_token.match(TK_NUM))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	num_id = ix1_token.getN();

	// obtiene indice
	ix = tok.getNum(num_id);

*/
	if (!tok.getNext(v_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto de una indexacion." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// :
	if (v_token.match(TK_OP, OP_RANGE))
	{
		elem = slicing(bus, ix);

		return elem;
	}

	tok.retract();

	// indice fuera de rango
	if (ix >= bus.size())
	{
		cout << "[ERROR] Indice fuera de rango." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	net = graph.drive(bus[ix]);

	elem.push_back(net);

	return elem;
}

///////////////////////////////////////////////////////////
// metodo: outputs                                       //
// proposito: parsing de la definicion puertos de        //
//            salida.                                    //
//            ej:                                        //
//            output logic tc                            //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::outputs(void)
{
	int i;
	int net;
	int out, reg;
	int port_id;
	int width;
	vector<int> nodes;
	Port puerto;
	// gramatica
	// outputs := nl_list output logic id |
	//            nl_list output logic id[dim] |
	//            nl_list output reg id |
	//            nl_list output reg id[dim]
	// dim := num | id
	// nl_list = nl_list newline | e

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// logic
	if (token.match(TK_KW, KW_LOGIC))
	{
		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// id
		if (!token.match(TK_ID))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un identificador de port."
					<< endl;
			cout << "output logic id :P" << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// rescata identificador del puerto
		port_id = token.getN();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_OUT;
		puerto.reg = PORT_LOGIC;

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// [
		if (token.match(TK_OP, OP_IX_OP))
		{
			width = dim();

			puerto.dim = width;

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
		ports." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// ]
			if (!token.match(TK_OP, OP_IX_CL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un token ]."
						<< endl;
				cout << "Desbalanceo de corchetes en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
ports." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// new line
			if (!token.match(TK_NL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// verifica que el identificador no este usado
			if (tok.isSymbolUsed(port_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del puerto no debe \
	haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			tok.lockSymbol(port_id);

			for (i = 0; i < width; i++)
			{
				// inserta puerto de salida
				out = graph.insertPortOut();
				nodes.push_back(out);
				puerto.nodes.push_back(out);
			}

			// asocia el bus al identificador
			tok.annotateSymbolNodes(port_id, nodes);
		}
		// new line
		else if (token.match(TK_NL))
		{
			// verifica que el identificador no este usado
			if (tok.isSymbolUsed(port_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del puerto no debe \
haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			tok.lockSymbol(port_id);

			// inserta puerto de salida
			out = graph.insertPortOut();
			nodes.push_back(out);
			puerto.nodes.push_back(out);

			// asocia el bus al identificador
			tok.annotateSymbolNodes(port_id, nodes);

			puerto.dim = 1;
		}
		// error
		else
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un enter." << endl;
			cout << "La declaracion de un puerto debe estar \
en una linea." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
	// reg
	else if (token.match(TK_KW, KW_REG))
	{
		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// id
		if (!token.match(TK_ID))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un identificador de port."
					<< endl;
			cout << "output reg id :P" << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// rescata identificador del puerto
		port_id = token.getN();

		puerto.name = tok.getSymbol(port_id);
		puerto.dir = PORT_OUT;
		puerto.reg = PORT_REG;

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion \
ports." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// [
		if (token.match(TK_OP, OP_IX_OP))
		{
			width = dim();

			puerto.dim = width;

			// verifica que el identificador no este usado
			if (tok.isSymbolUsed(port_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del puerto no debe \
	haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
ports." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// ]
			if (!token.match(TK_OP, OP_IX_CL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un token ]."
						<< endl;
				cout << "Desbalanceo de corchetes en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
ports." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// new line
			if (!token.match(TK_NL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "Error de sintaxis en construccion ports." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			tok.lockSymbol(port_id);

			for (i = 0; i < width; i++)
			{
				// inserta puerto de salida
				out = graph.insertPortOut();

				// inserta registro
				reg = graph.insertReg();
				// se considera como nodo al registro
				// y no al puerto para poder acceder
				// a su contenido
				nodes.push_back(reg);
				// usamos out para que el emitter
				// pueda hallar el nombre de puerto
				puerto.nodes.push_back(out);

				net = graph.drive(reg);
				graph.connect(out, net);

				// anota registro
				graph.Annotate(reg, port_id, i);
			}

			// asocia el bus al identificador
			tok.annotateSymbolNodes(port_id, nodes);
		}
		// new line
		else if (token.match(TK_NL))
		{
			// verifica que el identificador no este usado
			if (tok.isSymbolUsed(port_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del puerto no debe \
haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			puerto.dim = 1;

			tok.lockSymbol(port_id);

			// inserta puerto de salida
			out = graph.insertPortOut();

			// inserta registro
			reg = graph.insertReg();
			// se considera como nodo al registro
			// y no al puerto para poder acceder
			// a su contenido
			nodes.push_back(reg);
			// usamos out para que el emitter
			// pueda hallar el nombre de puerto
			puerto.nodes.push_back(out);

			net = graph.drive(reg);
			graph.connect(out, net);

			// anota registro
			graph.Annotate(reg, port_id, -1);

			// asocia el bus al identificador
			tok.annotateSymbolNodes(port_id, nodes);
		}
		// error
		else
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba un enter." << endl;
			cout << "La declaracion de un puerto debe estar \
en una linea." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}
	// error
	else
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token logic o reg." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	port_table.push_back(puerto);
}

///////////////////////////////////////////////////////////
// metodo: parameters                                    //
// proposito: parsing de la definicion de parametros.    //
//            ej:                                        //
//            parameters begin                           //
//      	      natural WIDTH = 8                      //
//            end                                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::parameters(void)
{
	int num_id;
	int param_id;
	uint32_t constant_id;
	uint32_t v_constant;
	// gramatica
	// parametros := parameters begin nl nl_list param_list end
    // param_list := nl_list natural id = num nl_list |
    //               nl_list constant id = eval_expr nl_list | e

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
parameters o ports." << endl;
		cout << "No define parameters o ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// parameters
	if (!token.match(TK_KW, KW_PARAM))
	{
		// que no haya parameters no significa un error
		// si comienza una construccion ports
		// dejamos a ports que defina si hubo error
		tok.retract();

		return;
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
parameters." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
parameters." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// new line
	if (!token.match(TK_NL))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un enter." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
parameters." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// agenda parametros hasta que encuentre end
	while (!token.match(TK_KW, KW_END))
	{
		/* natural */
		if (token.match(TK_KW, KW_NATURAL))
		{
/*			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba el token natural." << endl;
			cout << "Error de sintaxis en construccion parameters." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}*/
			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// id
			if (!token.match(TK_ID))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un identificador de parameter."
						<< endl;
				cout << "natural id = value :)." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// rescata identificador del parametro
			param_id = token.getN();

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// =
			if (!token.match(TK_OP, OP_ASSGN))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba el token =." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			if (!tok.getNext(op_token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// num
			if (!op_token.match(TK_NUM))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba el valor del parametro."
						<< endl;
				cout << "natural id = value :(." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// rescata identificador del valor de parametro
			num_id = op_token.getN();

	 		if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// new line
			if (!token.match(TK_NL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "La declaracion de un parametro debe estar \
	en una linea." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// verifica que el identificador no este usado
			if (tok.isSymbolUsed(param_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del parametro no debe \
	haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// carga el parametro
			params[param_id] = tok.getNum(num_id);
			tok.lockSymbol(param_id);

			if (!throw_nl())
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
		parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}
		}
		/* constant */
		else if (token.match(TK_KW, KW_CONSTANT))
		{
/*			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba el token natural." << endl;
			cout << "Error de sintaxis en construccion parameters." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}*/
			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// id
			if (!token.match(TK_ID))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un identificador de parameter."
						<< endl;
				cout << "natural id = value :)." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// rescata identificador del parametro
			constant_id = token.getN();

			if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// =
			if (!token.match(TK_OP, OP_ASSGN))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba el token =." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			std::cout << "-eval expr";
			std::cout << std::endl;

			/* rescata identificador del valor de la constante */
			v_constant = this->f_eval_expr();

			std::cout << "-eval expr ok";
			std::cout << std::endl;

	 		if (!tok.getNext(token))
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
	parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			// new line
			if (!token.match(TK_NL))
			{
				cout << "[ERROR] Token invalido." << endl;
				cout << "Se esperaba un enter." << endl;
				cout << "La declaracion de un parametro debe estar \
	en una linea." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			/* verifica que el identificador no este usado */
			if (tok.isSymbolUsed(constant_id))
			{
				cout << "[ERROR] Identificador ya usado." << endl;
				cout << "El identificador del parametro no debe \
	haberse usado previamente" << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				exit(1);
			}

			/* carga la constante */
			this->m_constants[constant_id] = v_constant;
			tok.lockSymbol(constant_id);

			if (!throw_nl())
			{
				cout << "[ERROR] Insuficientes tokens." << endl;
				cout << "Final abrupto del codigo en construccion \
		parameters." << endl;
				cout << "Error de sintaxis en construccion parameters." << endl;
				cout << "Linea: " << tok.getNLine() << endl;
				token.print();
				exit(1);
			}
		}
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
paramaters." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// new line
	if (!token.match(TK_NL))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un enter." << endl;
		cout << "Error de sintaxis en construccion parameters." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}
}

///////////////////////////////////////////////////////////
// metodo: ports                                         //
// proposito: parsing de la definicion de puertos.       //
//            ej:                                        //
//            ports begin                                //
//	              input logic sig_i                      //
//                output logic sig_o                     //
//            end                                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::ports(void)
{
	// gramatica
	// ports := nl_list ports begin nl nl_list port_list end
    // port_list := nl_list input_port |
	//              nl_list output_port
	// nl_list = nl_list newline | e

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
parameters o ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// ports
	if (!token.match(TK_KW, KW_PORTS))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token ports." << endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion ports."
				<< endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion ports."
				<< endl;
		cout << "No define ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// agenda puertos hasta que encuentre end
	while (!token.match(TK_KW, KW_END))
	{
		// input
		if (token.match(TK_KW, KW_INPUT))
		{
			inputs();
		}
		// output
		else if (token.match(TK_KW, KW_OUTPUT))
		{
			outputs();
		}
		else
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba el token input o output." << endl;
			cout << "Error de sintaxis en construccion ports." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		if (!throw_nl())
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Final abrupto del codigo en construccion ports."
					<< endl;
			cout << "Debe terminar la construccion ports con end." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion \
port." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// new line
	if (!token.match(TK_NL))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba un enter." << endl;
		cout << "Error de sintaxis en construccion ports." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}
}

///////////////////////////////////////////////////////////
// metodo: rel                                           //
// proposito: parsing de sentencias de comparacion.      //
//            ej:                                        //
//            a == b                                     //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::rel(int expc_width)
{
	// gramatica
	// rel := shift == shift |
	//			shift != shift |
	//			shift > shift |
	//			shift >= shift
	//			shift < shift |
	//			shift
	int node;
	vector<int> bus;
	vector<int> op2;

	bus = shift(expc_width);

	// para que funcione el autoajuste
	// de la longitud de palabra
	// de las constantes en las comparaciones
	expc_width = bus.size();

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un shift o ==" << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// shift == shift
	if (op_token.match(TK_OP, OP_CP_EQ))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpEq(bus, op2);

		bus = graph.driveBus(node);
	}
	// shift != shift
	else if (op_token.match(TK_OP, OP_CP_NEQ))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpNeq(bus, op2);

		bus = graph.driveBus(node);
	}
	// shift > shift
	else if (op_token.match(TK_OP, OP_CP_GR))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpGr(bus, op2);

		bus = graph.driveBus(node);
	}
	// shift >= shift
	else if (op_token.match(TK_OP, OP_CP_GREQ))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpGEq(bus, op2);

		bus = graph.driveBus(node);
	}
	// shift < shift
	else if (op_token.match(TK_OP, OP_CP_LW))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpLw(bus, op2);

		bus = graph.driveBus(node);
	}
	// shift <= shift
	else if (op_token.match(TK_OP, OP_CP_LWEQ))
	{
		op2 = shift(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una comparacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertCpLEq(bus, op2);

		bus = graph.driveBus(node);
	}
	else
	{
		tok.retract();
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: replication                                   //
// proposito: parsing de sentencias de replicacion.      //
//            ej:                                        //
//            a rep 5                                    //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::replication(int expc_width)
{
	// gramatica
	// replication := replication rep num |
	//                logical
	int i, j;
	int num_id;
	int times;
	vector<int> bus;
	vector<int> nets;
	vector<int> nodes;

	bus = logical(expc_width);

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un logical o rep." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// logical rep num
	while (op_token.match(TK_KW, KW_REP))
	{
		if (!tok.getNext(op_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se esperaba una constante." << endl;
			cout << "Error de sintaxis en un rep." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// num
		if (!op_token.match(TK_NUM))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba una constante." << endl;
			cout << "Error de sintaxis en construccion rep." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// buffers sobre el bus a replicar
		nodes = graph.insertBuf(bus);

		// rescata identificador de la constante
		num_id = op_token.getN();

		times = tok.getNum(num_id);

		cout << "Replication " << times << " veces" << endl;

		bus.clear();

		// replica el bus
		for (j = 0; j < times; j++)
		{
			nets = graph.driveBus(nodes);

			for (i = 0; i < nodes.size(); i++)
			{
				bus.push_back(nets[i]);
			}
		}

		if (!tok.getNext(op_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera un logical o rep." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

/**********************************************************
 * metodo: report                                         *
 * proposito: genera informe de compilacion.              *
 * parametros:                                            *
 *  rep_type - tipo de informe.                           *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::report(int rep_type)
{
	std::vector<std::vector<int>> cloud;
	std::vector<std::vector<int>> r2r_paths;
/*
	cout << "Parameters" << endl;
	cout << "----------" << endl << endl;

	cout << "Number of parameters: " << params.size()
			<< endl << endl;

	cout << "Parameter name\t\tValue" << endl << endl;

	for (auto& p : params)
	{
	    std::cout << tok.getSymbol(p.first) << "\t\t\t"
			<< p.second << std::endl;
	}*/

	switch (rep_type)
	{
		case E_REPORT_ASYNC_GRAPH:
			this->f_report_async_graph();
            break;
		case E_REPORT_GENERAL:
			this->f_report_general();

			break;
		case E_REPORT_GRAPH:
			this->f_report_graph();
            break;
		case E_REPORT_METAGRAPH:
			this->f_report_metagraph();
			break;
		case E_REPORT_CLOUD_LOGIC:
			this->f_report_cloud_logic();
            break;
		case E_REPORT_I2R_PATHS:
			this->f_report_i2r_paths();
            break;
		case E_REPORT_R2O_PATHS:
			this->f_report_r2o_paths();
            break;
		case E_REPORT_R2R_PATHS:
			this->f_report_r2r_paths();
            break;
		default:
			;
	}

//	graph.Serialize();
/*
	r2r_paths = graph.getR2RPaths();

	cout << endl;

	cout << "Cloud logic" << endl;
	cout << "-----------" << endl << endl;

	cloud = graph.Get_Cloud_Logic(r2r_paths);

	for (auto c : cloud)
	{
		std::cout << "id: " << tok.getSymbol(c[0]) << std::endl;

		if (c.size() > 1)
		{
			for (int i = 1; i < c.size(); i++)
			{
				std::cout << tok.getSymbol(c[i]);

				std::cout << std::endl;
			}
		}

		std:cout << std::endl;
	}

	tok.print_symbol_table();*/
}

/**********************************************************
 * metodo: f_report_cloud_logic                           *
 * proposito: informa la cloud logic.                     *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_cloud_logic()
{
    uint32_t n;

	std::cout << "Cloud Logic" << std::endl;
	std::cout << "-----------" << std::endl << std::endl;

    n = 1;

	for (auto p : this->m_cloud)
	{
        /* formato
         * capture, launching1, launching2, ...
         */

        /* lo primero en la lista es un registro de capture */
        std::cout << n << ": ";
        std::cout << "Capture: " << tok.getSymbol(p[0]);
        std::cout << " Launching: ";

        /* el resto son los registros launching de fan in
         * del registro anterior
         */
        for (int i = 1; i < p.size(); i++)
        {
            std::cout << tok.getSymbol(p[i]);

            if (i != p.size() - 1)
            {
                std::cout << ", ";
            }
        }

        ++n;

		std::cout << std::endl;
	}
}

/**********************************************************
 * metodo: f_report_general                               *
 * proposito: informe general de la compilacion.          *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_general()
{
	std::cout << "Parser Report";
	std::cout << std::endl;
	std::cout << "------ ------";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Block Name: ";
	std::cout << tok.getSymbol(block_name);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Parameters: ";
	std::cout << params.size();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Inputs: ";
	std::cout << graph.get_n_inputs();
	std::cout << std::endl;
	std::cout << "Outputs: ";
	std::cout << graph.get_n_outputs();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Cells: ";
	std::cout << graph.get_n_cells();
	std::cout << std::endl;

	std::cout << "Nets: ";
	std::cout << graph.get_n_nets();
	std::cout << std::endl;
	std::cout << std::endl;

    if (is_async)
    {
	    std::cout << "Latches: ";
	    std::cout << graph.get_n_regs();
	    std::cout << std::endl;
	    std::cout << "L2L paths: ";
	    std::cout << graph.get_n_r2r();
	    std::cout << std::endl;
	    std::cout << "I2L paths: ";
	    std::cout << graph.get_n_i2r();
	    std::cout << std::endl;
	    std::cout << "L2O paths: ";
	    std::cout << graph.get_n_r2o();
	    std::cout << std::endl;
	    std::cout << std::endl;
    }
    else
    {
	    std::cout << "Registers: ";
	    std::cout << graph.get_n_regs();
	    std::cout << std::endl;
	    std::cout << "R2R paths: ";
	    std::cout << graph.get_n_r2r();
	    std::cout << std::endl;
	    std::cout << "I2R paths: ";
	    std::cout << graph.get_n_i2r();
	    std::cout << std::endl;
	    std::cout << "R2O paths: ";
	    std::cout << graph.get_n_r2o();
	    std::cout << std::endl;
	    std::cout << std::endl;
    }

    return true;
}

/**********************************************************
 * metodo: f_report_graph                                 *
 * proposito: informa el grafo generado.                  *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_graph()
{
	std::cout << "Circuit Graph" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << std::endl;

	graph.print();

    return true;
}

/**********************************************************
 * metodo: f_report_async_graph                           *
 * proposito: informa el grafo asincronico generado.      *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_async_graph()
{
	std::cout << "Circuit Async Graph" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;

	degraph.print();

    return true;
}

/**********************************************************
 * metodo: f_report_i2r_paths                             *
 * proposito: informa los caminos i2r.                    *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_i2r_paths()
{
    uint32_t    p;

	std::cout << "Input-to-Register Paths" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;

    p = 1;

    if (this->is_async)
    {
        for (auto path : this->m_i2r_paths)
        {
            std::cout << p << ". ";

            for (int i = 0; i < path.size(); ++i)
            {
                /* registro capture */
                if (i == path.size() - 1)
                {
                    std::cout << "->" << path[i] << "[Reg] ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(";
                    std::cout << degraph.get_type_string(path[i]);
                    std::cout << ") ";
                }
            }

            std::cout << std::endl;
            ++p;
        }
    }
    else
    {
    	this->m_i2r_paths = graph.Get_I2R_Paths();

        for (auto path : this->m_i2r_paths)
        {
            for (int i = 0; i < path.size(); ++i)
            {
                /* registro launching */
                if (i == 0)
                {
                    std::cout << tok.getSymbol(path[i]) << "[Reg]-> ";
                }
                /* registro capture */
                else if (i == path.size() - 1)
                {
                    std::cout << tok.getSymbol(path[i]) << "->[Reg] ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(Celda) ";
                }
            }

            std::cout << std::endl;
        }
    }

    return true;
}

/**********************************************************
 * metodo: f_report_metagraph                             *
 * proposito: informa el meta grafo.                      *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_metagraph()
{
	std::cout << "Circuit Meta Graph" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;

	meta_graph.Print(0);

    return true;
}

/**********************************************************
 * metodo: f_report_r2o_paths                             *
 * proposito: informa los caminos r2o.                    *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_r2o_paths()
{
    uint32_t    p;

	std::cout << "Register-to-Output Paths" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

    p = 1;

    if (this->is_async)
    {
        for (auto path : this->m_r2o_paths)
        {
            std::cout << p << ". ";

            for (int i = 0; i < path.size(); ++i)
            {
                /* registro launching */
                if (i == 0)
                {
                    std::cout << path[i] << "[Reg]-> ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(";
                    std::cout << degraph.get_type_string(path[i]);
                    std::cout << ") ";
                }
            }

            std::cout << std::endl;
            ++p;
        }
    }
    else
    {
    	this->m_i2r_paths = graph.Get_I2R_Paths();

        for (auto path : this->m_i2r_paths)
        {
            for (int i = 0; i < path.size(); ++i)
            {
                /* registro launching */
                if (i == 0)
                {
                    std::cout << tok.getSymbol(path[i]) << "[Reg]-> ";
                }
                /* registro capture */
                else if (i == path.size() - 1)
                {
                    std::cout << tok.getSymbol(path[i]) << "->[Reg] ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(Celda) ";
                }
            }

            std::cout << std::endl;
        }
    }

    return true;
}

/**********************************************************
 * metodo: f_report_r2r_paths                             *
 * proposito: informa los caminos r2r.                    *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

bool Parser::f_report_r2r_paths()
{
    uint32_t    p;

	std::cout << "Register-to_Register Paths" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;

    p = 1;

    if (this->is_async)
    {
        for (auto path : this->m_r2r_paths)
        {
            std::cout << p << ". ";

            for (int i = 0; i < path.size(); ++i)
            {
                /* registro launching */
                if (i == 0)
                {
                    std::cout << path[i] << "[Reg]-> ";
                }
                /* registro capture */
                else if (i == path.size() - 1)
                {
                    std::cout << "->" << path[i] << "[Reg] ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(";
                    std::cout << degraph.get_type_string(path[i]);
                    std::cout << ") ";
                }
            }

            std::cout << std::endl;
            ++p;
        }
   }
    else
    {
    	this->m_r2r_paths = graph.getR2RPaths();

        for (auto path : this->m_r2r_paths)
        {
            for (int i = 0; i < path.size(); ++i)
            {
                /* registro launching */
                if (i == 0)
                {
                    std::cout << path[i] << "[Reg]-> ";
                }
                /* registro capture */
                else if (i == path.size() - 1)
                {
                    std::cout << path[i] << "->[Reg] ";
                }
                /* cloud logic */
                else
                {
                    std::cout << path[i] << "(";
                    std::cout << graph.get_type_string(path[i]);
                    std::cout << ") ";
                }
            }

            std::cout << std::endl;
        }
    }

    return true;
}

///////////////////////////////////////////////////////////
// metodo: run                                           //
// proposito: analiza la sintaxis del archivo fuente     //
//            agendado.                                  //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  true - analisis exitoso.                             //
//  false - encontro errores en el analisis.             //
///////////////////////////////////////////////////////////

bool Parser::run(void)
{
	// gramatica
	// hdl := block ports stmts |
	//			block ports decls stmts |
	//			block parameters ports stmts |
	//			block parameters ports decls stmts

	init();

	block();

	parameters();

	ports();

	decls();

	stmts();

	return true;
}

///////////////////////////////////////////////////////////
// metodo: selection                                     //
// proposito: parsing de sentencias case.                //
//            ej:                                        //
//            case s begin                               //
//                case_0:                                //
//                begin                                  //
//                    m = a                              //
//                end                                    //
//                others:                                //
//                begin                                  //
//                    m = b                              //
//                end                                    //
//            end                                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::selection(void)
{
	vector<int> selector;
	Env nesting;

	selector = concatenation(1);

	// buffer a la condicion
	nesting.node = graph.insertBuf(selector);

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion case."
				<< endl;
		cout << "Error de sintaxis en construccion case." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// begin
	if (!token.match(TK_KW, KW_BEGIN))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba el token begin." << endl;
		cout << "Error de sintaxis en construccion case." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo en construccion case."
				<< endl;
		cout << "Error de sintaxis en construccion case." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// recorre casos hasta el end
	while (!token.match(TK_KW, KW_END))
	{
		// case_xx:
		if (!token.match(TK_KW, KW_NATURAL))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba el token natural." << endl;
			cout << "Error de sintaxis en construccion parameters." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	exit(1);
}

///////////////////////////////////////////////////////////
// metodo: shift                                         //
// proposito: parsing de sentencias de desplazamiento.   //
//            ej:                                        //
//            a u>> 1                                    //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::shift(int expc_width)
{
	// gramatica
	// shift := shift >> num |
	//          shift s>> num |
	//			shift << num |
	//          expr
	int i;
	int net;
	int net_low;
	int num_id;
	int times;
	Token op_token, num_token;
	vector<int> bus;
	vector<int> nodes;

	bus = expr(expc_width);

	if (!tok.getNext(op_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Error de sintaxis de un shift." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// shift >> num |
	// shift s>> num |
	// expr
	while (op_token.match(TK_OP, OP_USHFT) ||
			 op_token.match(TK_OP, OP_SSHFT) ||
			 op_token.match(TK_OP, OP_LSHFT))
	{
		if (!tok.getNext(num_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se esperaba una constante." << endl;
			cout << "Error de sintaxis en un shift >>." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// num
		if (!num_token.match(TK_NUM))
		{
			cout << "[ERROR] Token invalido." << endl;
			cout << "Se esperaba una constante." << endl;
			cout << "Error de sintaxis en construccion shift." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		// buffers sobre el bus a replicar
		nodes = graph.insertBuf(bus);

		// rescata identificador de la constante
		num_id = num_token.getN();

		times = tok.getNum(num_id);

		cout << "Shift " << times << " veces" << endl;

		bus.clear();

		// la cantidad de bits desplazados
		// no debe superar la dimension del bus
		if (times > nodes.size())
		{
			cout << "[ERROR] Cantidad de desplazamientos invalida." << endl;
			cout << "No debe superar la dimension del bus." << endl;
			cout << "Error semantico en construccion shift." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		cout << "Times: " << times << endl;

		// replica el bus
		for (i = 0; i < nodes.size(); i++)
		{
			// desplazamiento a la izquierda
			if (op_token.match(TK_OP, OP_LSHFT))
			{
				// relleno con 0
				if (i < times)
				{
					// drive tie low cell
					net_low = graph.drive(0);

					tie_lo_used = true;

					bus.push_back(net_low);
				}
				// bits del resultado que copian
				// bits del operando
				else
				{
					net = graph.drive(nodes[i - times]);
					bus.push_back(net);
				}
			}
			// desplazamiento a la derecha
			else
			{
				// bits del resultado que copian
				// bits del operando
				if (i + times < nodes.size())
				{
					net = graph.drive(nodes[i + times]);
					bus.push_back(net);
				}
				else
				{
					// desplazamiento logico
					if (op_token.match(TK_OP, OP_USHFT))
					{
						// drive tie low cell
						net_low = graph.drive(0);

						tie_lo_used = true;

						bus.push_back(net_low);
					}
					// desplazamiento aritmetico
					else
					{
						// drive msb
						net = graph.drive(nodes[nodes.size() - 1]);

						bus.push_back(net);
					}
				}
			}
		}


		if (!tok.getNext(op_token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera una expr." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: slicing                                       //
// proposito: parsing de un subvector.                   //
//            ej:                                        //
//            a[3:1]                                     //
// argumentos:                                           //
//  bus - bus a indexar.                                 //
//  ix1 - MSb.                                           //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::slicing(vector<int> bus, int ix1)
{
	int i;
	int ix2;
	int net;
	int num_id;
	vector<int> elem;

/*
	if (!tok.getNext(ix2_token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se esperba una constante." << endl;
		cout << "Error de sintaxis en un slicing." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// num
	if (!ix2_token.match(TK_NUM))
	{
		cout << "[ERROR] Token invalido." << endl;
		cout << "Se esperaba una constante." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	num_id = ix2_token.getN();

	// obtiene indice
	ix2 = tok.getNum(num_id);

	// indice fuera de rango
	if (ix1 >= bus.size())
	{
		cout << "[ERROR] Indice fuera de rango." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}*/

	ix2 = this->f_eval_expr();

	// ix1 > ix2
	if (ix1 <= ix2)
	{
		cout << "[ERROR] Indices incorrectos." << endl;
		cout << "El MSb debe ser mayor al LSb." << endl;
		cout << "Error de sintaxis en una indexacion." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	for (i = ix2; i <= ix1; i++)
	{
		net = graph.drive(bus[i]);
		elem.push_back(net);
	}

	return elem;
}

///////////////////////////////////////////////////////////
// metodo: stmt                                          //
// proposito: parsing de una sentencia.                  //
//            ej:                                        //
//            a_next = a_reg + 1                         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::stmt(void)
{
	// if
	if (token.match(TK_KW, KW_IF))
	{
		boolean();
	}
	// for
	else if (token.match(TK_KW, KW_FOR))
	{
		for_generate();
	}
	// case
	else if (token.match(TK_KW, KW_CASE))
	{
		selection();
	}
	else
	{
		assign();
	}
}

///////////////////////////////////////////////////////////
// metodo: stmts                                         //
// proposito: parsing de la lista de sentencias.         //
//            ej:                                        //
//            a_next = a_reg + 1                         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Parser::stmts(void)
{
	tok.retract();

	if (!throw_nl())
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Final abrupto del codigo." << endl;
		cout << "Error de sintaxis." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// agenda puertos hasta que encuentre end
	while (!token.match(TK_KW, KW_END))
	{
		stmt();
	}
}

/**********************************************************
 * metodo: source                                         *
 * proposito: agenda el nombre del archivo fuente.        *
 * argumentos:                                            *
 *  name - nombre del archivo fuente                      *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Parser::source(std::string name)
{
    filename = name;

	/* carga nombre del archivo fuente */
	tok.source(name);
	emt.source(name);
	graph.source(name);
}

///////////////////////////////////////////////////////////
// metodo: term                                          //
// proposito: parsing de sentencias de producto.         //
//            ej:                                        //
//            a * b                                      //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::term(int expc_width)
{
	// gramatica
	// term := term * unary |
	//			unary
	int node;
	vector<int> bus;
	vector<int> op2;

	bus = unary(expc_width);

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un factor o unary o *." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// term * unary
	while (token.match(TK_OP, OP_MULT))
	{
		op2 = unary(expc_width);

		// verifica que las longitudes de palabra
		// de los operandos coincidan
		if (!widthCheck(bus, op2))
		{
			cout << "[ERROR] Las longitudes de palabara no coinciden." << endl;
			cout << "En una multiplicacion." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}

		node = graph.insertMult(bus, op2);

		bus = graph.driveBus(node);

		if (!tok.getNext(token))
		{
			cout << "[ERROR] Insuficientes tokens." << endl;
			cout << "Se espera un factor o unary o *." << endl;
			cout << "Error de sintaxis en una sentencia." << endl;
			cout << "Linea: " << tok.getNLine() << endl;
			exit(1);
		}
	}

	tok.retract();

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: throw_nl                                      //
// proposito: descarta new lines.                        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  true - hay mas tokens despues de los new lines.      //
//  false - no hay mas tokens despues de los new lines.  //
///////////////////////////////////////////////////////////

bool Parser::throw_nl(void)
{
	// descarta new line iniciales
	do
	{
		if (!tok.getNext(token))
		{
			return false;
		}
	}
	while (token.match(TK_NL));

	return true;
}

///////////////////////////////////////////////////////////
// metodo: unary                                         //
// proposito: parsing de operaciones unarias.            //
//            ej:                                        //
//            -a                                         //
// argumentos:                                           //
//  expc_width - longitud de palabra esperada en el      //
//               resultado ( para others ).              //
// devuelve:                                             //
//  bus con el resultado.                                //
///////////////////////////////////////////////////////////

vector<int> Parser::unary(int expc_width)
{
	// gramatica
	// unary := -factor |
	//			+ factor |
	//			not factor |
	//			factor
	int net;
	int node;
	vector<int> bus;
	vector<int> rvalue;

	if (!tok.getNext(token))
	{
		cout << "[ERROR] Insuficientes tokens." << endl;
		cout << "Se espera un factor o unary." << endl;
		cout << "Error de sintaxis en una sentencia." << endl;
		cout << "Linea: " << tok.getNLine() << endl;
		exit(1);
	}

	// not factor
	if (token.match(TK_KW, KW_NOT))
	{
		rvalue = factor(expc_width);

		bus = graph.insertNot(rvalue);
	}
	// + factor
	else if (token.match(TK_OP, OP_ADD))
	{
		bus = factor(expc_width);
	}
	// - factor
	else if (token.match(TK_OP, OP_SUB))
	{
		rvalue = factor(expc_width);

		node = graph.insertNeg(rvalue);

		bus = graph.driveBus(node);
	}
	// factor
	else
	{
		tok.retract();

		bus = factor(expc_width);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: widthCheck                                    //
// proposito: comprueba que las longitudes de palabra    //
//            sean iguales.                              //
// argumentos:                                           //
//  bus_1 - vector 1.                                    //
//  bus_2 - vector 2.                                    //
// devuelve:                                             //
//  true - las longitudes de palabra son iguales.        //
//  false - las longitudes de palabra son distintas.     //
///////////////////////////////////////////////////////////

bool Parser::widthCheck(vector<int> bus_1, vector<int> bus_2)
{
	if (bus_1.size() == bus_2.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
