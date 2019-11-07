///////////////////////////////////////////////////////////
// codigo fuente: emitter.cc                             //
// fecha de inicio: 23/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase Emitter para generar codigo Verilog. //
//                                                       //
// clase implementada:                                   //
//  Emitter                                              //
// propiedades:                                          //
// metodos:                                              //
//  add - emite driving y asignacion de una suma.        //
//  addcout - emite driving y asignacion de una suma con //
//            carry de salida.                           //
//  and2 - emite driving y asignacion de una and.        //
//  body - cuerpo principal del codigo Verilog.          //
//  buf - emite driving y asignacion de un buffer.       //
//  compose - construye un vector por concatenacion.     //
//  composepp - construye un vector por concatenacion    //
//              con un bit adicional.                    //
//  cpeq - emite driving y asignacion de un              //
//         comparador por igual.                         //
//  cpgr - emite driving y asignacion de un              //
//            comparador por mayor.                      //
//  cpgeq - emite driving y asignacion de un             //
//            comparador por mayor o igual.              //
//  cpleq - emite driving y asignacion de un             //
//            comparador por meno o igual.               //
//  cplw - emite driving y asignacion de un              //
//            comparador por menor.                      //
//  cpneq - emite driving y asignacion de un             //
//            comparador por distinto.                   //
//  create - crea el archivo Verilog.                    //
//  decls - genera la declaracion de wires locales.      //
//  fork_controller - emite driving y asignacion de un   //
//                    fork controller.                   //
//  getFullName - obtiene el nombre completo del         //
//                archivo.                               //
//  getMainName - obtiene el nombre principal del        //
//                archivo.                               //
//  getPath - obtiene la ruta del archivo.               //
//  getPortName - obtiene el nombre de un puerto.        //
//  inv - emite driving y asignacion de un inversor.     //
//  join_controller - emite driving y asignacion de un   //
//                    join controller.                   //
//  latch - emite driving y asignacion de un latch.      //
//  latch_controller - emite driving y asignacion de un  //
//                     latch controller.                 //
//  module - genera la declaracion module.               //
//  mult - emite driving y asignacion de una             //
//         multiplicacion.                               //
//  mux2 - emite driving y asignacion de un              //
//            multiplexor de 2 entradas.                 //
//  neg - emite driving y asignacion de un cambio de     //
//            signo.                                     //
//  or2 - emite driving y asignacion de una or.          //
//  ports - genera la declaracion puertos.               //
//  port_in - emite driving de puerto de entrada.        //
//  port_out - emite asignacion a puerto de salida.      //
//  reg - emite driving y asignacion de un registro.     //
//  source - agenda el nombre del archivo fuente.        //
//  sub - emite driving y asignacion de una resta.       //
//  subboout - emite driving y asignacion de una         //
//            resta con salida de borrow.                //
//  tail - cierra el archivo Verilog.                    //
//  ties - genera tie cells.                             //
//  tie_hi - emite driving de celda tie hi.              //
//  tie_lo - emite driving de celda tie lo.              //
//  xor2 - emite driving y asignacion de una xor.        //
//  xnor2 - emite driving y asignacion de una xnor.      //
//                                                       //
///////////////////////////////////////////////////////////

using namespace std;

#include "emitter.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "port.h"

///////////////////////////////////////////////////////////
// metodo: add                                           //
// proposito: emite driving y asignacion de una          //
//            suma.                                      //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::add(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara sumador
	locals << "\twire add_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "add_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign add_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getWidth());
	stmts << " + ";
	compose(node->queryBusFanin(1), node->getWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: addcout                                       //
// proposito: emite driving y asignacion de una suma con //
//            carry de salida.                           //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::addcout(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara sumador
	locals << "\twire add_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "add_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign add_" << std::to_string(n);
	stmts << " = ";

	composepp(node->queryBusFanin(0), node->getWidth() - 1);
	stmts << " + ";
	composepp(node->queryBusFanin(1), node->getWidth() - 1);
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: and2                                          //
// proposito: emite driving y asignacion de una and.     //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::and2(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara and
	locals << "\twire and_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "and_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign and_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << " & net_" << std::to_string(node->queryFanin(1));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: body                                          //
// proposito: cuerpo principal del codigo Verilog.       //
// argumentos:                                           //
//  cells - lista de celdas ( por referencia ).          //
//  nets - lista de nets ( por referencia ).             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::body(vector<Node*>* cells,
					vector<Net*>* nets)
{
	int i;
	Node *node;

	// recorre todos las celdas
	for (i = 0; i < cells->size(); i++)
	{
		node = (*cells)[i];

		switch(node->getTypeID())
		{
			case NODE_ID_PORTOUT:
				port_out(node, i);
			break;
			case NODE_ID_PORTIN:
				port_in(node, i);
			break;
			case NODE_ID_TIEHI:
				tie_hi(node);
			break;
			case NODE_ID_TIELO:
				tie_lo(node);
			break;
			case NODE_ID_REG:
				reg(node, i);
			break;
			case NODE_ID_LATCH:
				latch(node, i);
			break;
			case NODE_ID_FC:
				fork_controller(node, i);
			break;
			case NODE_ID_JC:
				join_controller(node, i);
			break;
			case NODE_ID_LC:
				latch_controller(node, i);
			break;
			case NODE_ID_MUX2:
				mux2(node, i);
			break;
			case NODE_ID_BUF:
				buf(node, i);
			break;
			case NODE_ID_NOT:
				inv(node, i);
			break;
			case NODE_ID_NEG:
				neg(node, i);
			break;
			case NODE_ID_MULT:
				mult(node, i);
			break;
			case NODE_ID_ADD:
				add(node, i);
			break;
			case NODE_ID_ADDCOUT:
				addcout(node, i);
			break;
			case NODE_ID_SUB:
				sub(node, i);
			break;
			case NODE_ID_SUBBOUT:
				subbout(node, i);
			break;
			case NODE_ID_CPEQ:
				cpeq(node, i);
			break;
			case NODE_ID_CPNEQ:
				cpneq(node, i);
			break;
			case NODE_ID_CPGR:
				cpgr(node, i);
			break;
			case NODE_ID_CPGEQ:
				cpgeq(node, i);
			break;
			case NODE_ID_CPLW:
				cplw(node, i);
			break;
			case NODE_ID_CPLEQ:
				cpleq(node, i);
			break;
			case NODE_ID_AND2:
				and2(node, i);
			break;
			case NODE_ID_OR2:
				or2(node, i);
			break;
			case NODE_ID_XOR2:
				xor2(node, i);
			break;
			case NODE_ID_XNOR2:
				xnor2(node, i);
			break;
		}
	}

	// recorre todos los nets
	for (i = 0; i < nets->size(); i++)
	{
		locals << "\twire net_" << i << ";" << endl;
	}
}

///////////////////////////////////////////////////////////
// metodo: buf                                           //
// proposito: emite driving y asignacion de un buffer.   //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::buf(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara buffer
	locals << "\twire buf_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "buf_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign buf_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: compose                                       //
// proposito: construye un vector por concatenacion.     //
// argumentos:                                           //
//  nodes - vector de nodos.                             //
//  width - longitud de palabra.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::compose(int *nodes, int width)
{
	int i;

	stmts << "{";

	for (i = width - 1; i >= 0; i--)
	{
		stmts << "net_" << std::to_string(nodes[i]);

		if (i)
		{
			stmts << ", ";
		}
	}

	stmts << "}";
}

///////////////////////////////////////////////////////////
// metodo: composepp                                     //
// proposito: construye un vector por concatenacion con  //
//            un bit adicional.                          //
// argumentos:                                           //
//  nodes - vector de nodos.                             //
//  width - longitud de palabra.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::composepp(int *nodes, int width)
{
	int i;

	stmts << "{ 1'b0, ";

	for (i = width - 1; i >= 0; i--)
	{
		stmts << "net_" << std::to_string(nodes[i]);

		if (i)
		{
			stmts << ", ";
		}
	}

	stmts << "}";
}

///////////////////////////////////////////////////////////
// metodo: cpeq                                          //
// proposito: emite driving y asignacion de un           //
//            comparador por igual.                      //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cpeq(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cpneq_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cpneq_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cpneq_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " == ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: cpgr                                          //
// proposito: emite driving y asignacion de un           //
//            comparador por mayor.                      //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cpgr(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cpgr_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cpgr_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cpgr_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " > ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: cpgeq                                         //
// proposito: emite driving y asignacion de un           //
//            comparador por mayor o igual.              //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cpgeq(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cpgeq_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cpgeq_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cpgeq_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " >= ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: cplw                                          //
// proposito: emite driving y asignacion de un           //
//            comparador por menor.                      //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cplw(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cplw_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cplw_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cplw_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " < ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: cpleq                                         //
// proposito: emite driving y asignacion de un           //
//            comparador por meno o igual.               //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cpleq(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cpleq_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cpleq_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cpleq_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " <= ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: cpneq                                         //
// proposito: emite driving y asignacion de un           //
//            comparador por distinto.                   //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::cpneq(Node *node, int n)
{
	int i;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara comparador
	locals << "\twire cpeq_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "cpeq_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign cpeq_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getFaninWidth());
	stmts << " != ";
	compose(node->queryBusFanin(1), node->getFaninWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: create                                        //
// proposito: crea el archivo Verilog.                   //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::create(void)
{
	file.open(path + vname + ".v", fstream::out);

	locals.clear();
	stmts.clear();
}

///////////////////////////////////////////////////////////
// metodo: decls                                         //
// proposito: genera la declaracion de wires locales.    //
// argumentos:                                           //
//  decl_table - tabla de wires locales                  //
//               ( por referencia ).                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::decls(vector<Port> &decl_table)
{
	file << endl;

/*	for (auto &p : decl_table)
	{
		// register
		if (p.reg == PORT_REG)
		{
			file << "\treg ";
		}
		// wire
		else
		{
			file << "\twire ";
		}

		// vector
		if (p.dim != 1)
		{
			file << "[" << p.dim - 1 << ":0" << "] ";
		}

		// name
		file << p.name << ";";

		file << endl;
	}*/
}

///////////////////////////////////////////////////////////
// metodo: fork_controller                               //
// proposito: emite driving y asignacion de un fork      //
//            controller.                                //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::fork_controller(Node *node, int n)
{
	stmts << "\tFC fc_" << std::to_string(n) << std::endl;
	stmts << "\t(" << std::endl;
	stmts << "\t\t.rst(rst)," << std::endl;
	stmts << "\t\t.lr(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_LEFT));
	stmts << ")," << std::endl;
	stmts << "\t\t.la(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_LEFT));
	stmts << ")," << std::endl;
	stmts << "\t\t.rr1(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_RIGHT_1));
	stmts << ")," << std::endl;
	stmts << "\t\t.ra1(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_RIGHT_1));
	stmts << ")," << std::endl;
	stmts << "\t\t.rr2(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_RIGHT_2));
	stmts << ")," << std::endl;
	stmts << "\t\t.ra2(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_RIGHT_2));
	stmts << ")" << std::endl;
	stmts << "\t);" << std::endl;
	stmts << std::endl;

//	fanouts = ((JC*)node)->queryFanouts();

	stmts << std::endl;
}

///////////////////////////////////////////////////////////
// metodo: getFullName                                   //
// proposito: obtiene el nombre completo del archivo.    //
// argumentos:                                           //
//  name - nombre del archivo con su ruta.               //
// devuelve:                                             //
//  nombre del archivo.                                  //
///////////////////////////////////////////////////////////

string Emitter::getFullName(string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != string::npos)
	{
		return (name.substr(i + 1, name.length() - i));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getMainName                                   //
// proposito: obtiene el nombre principal del archivo.   //
// argumentos:                                           //
//  name - nombre del archivo con extension.             //
// devuelve:                                             //
//  nombre del archivo.                                  //
///////////////////////////////////////////////////////////

string Emitter::getMainName(string name)
{
	size_t i = name.rfind('.', name.length());

	if (i != string::npos)
	{
		return (name.substr(0, i));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getPath                                       //
// proposito: obtiene la ruta del archivo.               //
// argumentos:                                           //
//  name - nombre del archivo.                           //
// devuelve:                                             //
//  ruta del archivo.                                    //
///////////////////////////////////////////////////////////

string Emitter::getPath(string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != string::npos)
	{
		return (name.substr(0, i + 1));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getPortName                                   //
// proposito: obtiene el nombre de un puerto.            //
// argumentos:                                           //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nombre del puerto.                                   //
///////////////////////////////////////////////////////////

string Emitter::getPortName(int n)
{
	int ix;
	string port_name;

	// recorre la tabla de puertos
	for (auto &p : port_table)
	{
		// rastrea indice del bus
		ix = 0;

		// recorre los nodos del puerto
		for (auto &node : p.nodes)
		{
			// puerto encontrado
			if (node == n)
			{
				// bit
				if (p.dim == 1)
				{
					return p.name;
				}
				// bus indexado
				else
				{
					port_name = p.name + "[";
					port_name += std::to_string(ix);
					port_name += "]";

					return port_name;
				}
			}

			ix++;
		}
	}

	return "";
}

///////////////////////////////////////////////////////////
// metodo: inv                                           //
// proposito: emite driving y asignacion de un inversor. //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::inv(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara buffer
	locals << "\twire inv_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "inv_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign inv_" << std::to_string(n) << " = ~net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: join_controller                               //
// proposito: emite driving y asignacion de un join      //
//            controller.                                //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::join_controller(Node *node, int n)
{
	std::vector<int> fanouts;

	stmts << "\tJC jc_" << std::to_string(n) << std::endl;
	stmts << "\t(" << std::endl;
	stmts << "\t\t.rst(rst)," << std::endl;
	stmts << "\t\t.lr1(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_LEFT_1));
	stmts << ")," << std::endl;
	stmts << "\t\t.la1(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_LEFT_1));
	stmts << ")," << std::endl;
	stmts << "\t\t.lr2(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_LEFT_2));
	stmts << ")," << std::endl;
	stmts << "\t\t.la2(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_LEFT_2));
	stmts << ")," << std::endl;
	stmts << "\t\t.rr(net_" << std::to_string(((JC*)node)->queryFanin(FAN_REQ_RIGHT));
	stmts << ")," << std::endl;
	stmts << "\t\t.ra(net_" << std::to_string(((JC*)node)->queryFanin(FAN_ACK_RIGHT));
	stmts << ")" << std::endl;
	stmts << "\t);" << std::endl;
	stmts << std::endl;

//	fanouts = ((JC*)node)->queryFanouts();

	stmts << std::endl;
}

///////////////////////////////////////////////////////////
// metodo: latch                                         //
// proposito: emite driving y asignacion de un latch.    //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::latch(Node *node, int n)
{
	std::vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara registro
	locals << "\twire q_" << std::to_string(n) << ";" << std::endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "q_" << std::to_string(n) << ";" << std::endl;
	}

	stmts << std::endl;

	stmts << "\tLatch latch_" << std::to_string(n) << std::endl;
	stmts << "\t(" << std::endl;
	stmts << "\t\t.rst(rst)," << std::endl;
	stmts << "\t\t.le(net_" << std::to_string(((Latch*)node)->queryFanin(FAN_LE));
	stmts << ")," << std::endl;
	stmts << "\t\t.d(net_" << std::to_string(node->queryFanin(FAN_D));
	stmts << ")," << std::endl;
	stmts << "\t\t.q(q_" <<  std::to_string(n);
	stmts << ")" << std::endl;
	stmts << "\t);" << std::endl;
	stmts << std::endl;

/*	stmts << "\talways@(posedge rst)" << std::endl;
	stmts << "\tbegin" << std::endl;
	stmts << "\t\tif (rst)" << std::endl;
	stmts << "\t\tbegin" << std::endl;
	stmts << "\t\t\tq_" << std::to_string(n) << " = 1'b0;" << std::endl;
	stmts << "\t\tend" << std::endl;
	stmts << "\t\telse if (" << "net_";
	stmts << std::to_string(((Latch*)node)->queryFanin(FAN_LE));
	stmts << ")" << std::endl;
	stmts << "\t\tbegin" << std::endl;
	stmts << "\t\t\tq_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(FAN_D)) << ";" << std::endl;
	stmts << "\t\tend" << std::endl;
	stmts << "\tend" << std::endl << std::endl;*/
}

///////////////////////////////////////////////////////////
// metodo: latch_controller                              //
// proposito: emite driving y asignacion de un latch     //
//            controller.                                //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::latch_controller(Node *node, int n)
{
	std::vector<int> fanouts;

	// declara latch enable
	locals << "\twire le_lc_" << std::to_string(n) << ";" << std::endl;

	stmts << "\tLC lc_" << std::to_string(n) << std::endl;
	stmts << "\t(" << std::endl;
	stmts << "\t\t.rst(rst)," << std::endl;
	stmts << "\t\t.le(le_lc_" << std::to_string(n);
	stmts << ")," << std::endl;
	stmts << "\t\t.lr(net_" << std::to_string(((LC*)node)->queryFanin(FAN_REQ_LEFT));
	stmts << ")," << std::endl;
	stmts << "\t\t.la(net_" << std::to_string(((LC*)node)->queryFanin(FAN_ACK_LEFT));
	stmts << ")," << std::endl;
	stmts << "\t\t.rr(net_" << std::to_string(((LC*)node)->queryFanin(FAN_REQ_RIGHT));
	stmts << ")," << std::endl;
	stmts << "\t\t.ra(net_" << std::to_string(((LC*)node)->queryFanin(FAN_ACK_RIGHT));
	stmts << ")" << std::endl;
	stmts << "\t);" << std::endl;
	stmts << std::endl;

	fanouts = ((LC*)node)->queryFanouts();

	for (auto &w : fanouts)
	{
		stmts << "\tassign ";
		stmts << "net_" << w;
		stmts << " = le_lc_" << std::to_string(n) << ";";
		stmts << std::endl;
	}

	stmts << std::endl;
}

///////////////////////////////////////////////////////////
// metodo: module                                        //
// proposito: genera la declaracion module.              //
// argumentos:                                           //
//  block - nombre del module.                           //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::module(string block)
{
	file << "module " << block << endl;
	file << "\t(" << endl;
}

///////////////////////////////////////////////////////////
// metodo: mult                                          //
// proposito: emite driving y asignacion de una          //
//            multiplicacion.                            //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::mult(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara multiplicador
	locals << "\twire mult_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "mult_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign mult_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getWidth() / 2);
	stmts << " * ";
	compose(node->queryBusFanin(1), node->getWidth() / 2);
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: mux2                                          //
// proposito: emite driving y asignacion de un           //
//            multiplexor de 2 entradas.                 //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::mux2(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara wire
	locals << "\twire mux_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "mux_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign mux_" << std::to_string(n);
	stmts << " = (net_" << std::to_string(node->queryFanin(0));
	stmts << ") ? net_" << std::to_string(node->queryFanin(1));
	stmts << " : net_" << std::to_string(node->queryFanin(2));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: neg                                           //
// proposito: emite driving y asignacion de un cambio de //
//            signo.                                     //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::neg(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara cambio de signo
	locals << "\twire neg_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "neg_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign neg_" << std::to_string(n);
	stmts << " = -";

	compose(node->queryBusFanin(), node->getWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: or2                                           //
// proposito: emite driving y asignacion de una or.      //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::or2(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara or
	locals << "\twire or_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "or_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign or_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << " | net_" << std::to_string(node->queryFanin(1));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: ports                                         //
// proposito: genera la declaracion puertos.             //
// argumentos:                                           //
//  p_tb - tabla de puertos ( por referencia ).          //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::ports(vector<Port> &p_tb, bool is_async)
{
	file << "\t\tinput wire rst,";
	file << std::endl;

	if (!is_async)
	{
		file << "\t\tinput wire clk,";
		file << std::endl;
	}


	for (auto &p : p_tb)
	{
		port_table.push_back(p);

		// input
		if (p.dir == PORT_IN)
		{
			file << "\t\tinput wire ";
		}
		// output
		else
		{
			file << "\t\toutput ";

			// register
			if (p.reg == PORT_REG)
			{
				file << "reg ";
			}
			// wire
			else
			{
				file << "wire ";
			}
		}

		// vector
		if (p.dim != 1)
		{
			file << "[" << p.dim - 1 << ":0" << "] ";
		}

		// name
		file << p.name << ",";
		file << std::endl;
	}

	file << "\t);" << std::endl;
}

///////////////////////////////////////////////////////////
// metodo: port_in                                       //
// proposito: emite driving de puerto de entrada.        //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::port_in(Node *node, int n)
{
	string pname;
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	pname = getPortName(n);

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << pname << ";" << endl;
	}
}

///////////////////////////////////////////////////////////
// metodo: port_out                                      //
// proposito: emite asignacion a puerto de salida.       //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::port_out(Node *node, int n)
{
	stmts << "\tassign ";

	stmts << getPortName(n);

	stmts << " = net_" << node->getFanIn();

	stmts << ";";

	stmts << endl;
}

///////////////////////////////////////////////////////////
// metodo: reg                                           //
// proposito: emite driving y asignacion de un registro. //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::reg(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara registro
	locals << "\treg q_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "q_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\talways@(posedge clk, posedge rst)" << endl;
	stmts << "\tbegin" << endl;
	stmts << "\t\tif (rst)" << endl;
	stmts << "\t\tbegin" << endl;
	stmts << "\t\t\tq_" << std::to_string(n) << " = 1'b0;" << endl;
	stmts << "\t\tend" << endl;
	stmts << "\t\telse" << endl;
	stmts << "\t\tbegin" << endl;
	stmts << "\t\t\tq_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(0)) << ";" << endl;
	stmts << "\t\tend" << endl;
	stmts << "\tend" << endl << endl;
}

/**********************************************************
 * metodo: source                                         *
 * proposito: agenda el nombre del archivo fuente.        *
 * argumentos:                                            *
 *  name - nombre del archivo fuente                      *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Emitter::source(std::string name)
{
	this->vname = getFullName(name);
	this->vname = getMainName(this->vname);
	this->path = getPath(name);
}

///////////////////////////////////////////////////////////
// metodo: sub                                           //
// proposito: emite driving y asignacion de una          //
//            resta.                                     //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::sub(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara resta
	locals << "\twire sub_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "sub_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign sub_" << std::to_string(n);
	stmts << " = ";

	compose(node->queryBusFanin(0), node->getWidth());
	stmts << " - ";
	compose(node->queryBusFanin(1), node->getWidth());
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: subbout                                       //
// proposito: emite driving y asignacion de una          //
//            resta con salida de borrow.                //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::subbout(Node *node, int n)
{
	int i;
	vector<vector<int>> fanouts;

	fanouts = node->queryBusFanouts();

	// declara resta
	locals << "\twire sub_" << std::to_string(n);
	locals << "[" << std::to_string(node->getWidth() - 1) << ":0]";
	locals << ";" << endl;

	for (auto &bus : fanouts)
	{
		i = 0;

		for (auto &w : bus)
		{
			stmts << "\tassign net_" << w << " = ";
			stmts << "sub_" << std::to_string(n) << "[";
			stmts << std::to_string(i) << "];" << endl;

			i++;
		}
	}

	stmts << endl;

	stmts << "\tassign sub_" << std::to_string(n);
	stmts << " = ";

	composepp(node->queryBusFanin(0), node->getWidth() - 1);
	stmts << " - ";
	composepp(node->queryBusFanin(1), node->getWidth() - 1);
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: tail                                          //
// proposito: final del archivo Verilog.                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::tail(void)
{
	file << locals.str() << endl << stmts.str();

	file << "endmodule" << endl;

	file.close();
}

///////////////////////////////////////////////////////////
// metodo: ties                                          //
// proposito: genera tie cells.                          //
// argumentos:                                           //
//  tie_hi_used - necesita tie hi.                       //
//  tie_lo_used - necesita tie lo.                       //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::ties(bool tie_hi_used, bool tie_lo_used)
{
	// tie hi
	if (tie_hi_used)
	{
		locals << "\twire net_tie_hi;" << endl;
		stmts << "\tassign net_tie_hi = 1'b1;" << endl;
	}

	// tie lo
	if (tie_lo_used)
	{
		locals << "\twire net_ti_lo;" << endl;
		stmts << "\tassign net_ti_lo = 1'b0;" << endl;
	}
}

///////////////////////////////////////////////////////////
// metodo: tie_hi                                        //
// proposito: emite driving de celda tie hi.             //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::tie_hi(Node *node)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "net_tie_hi;" << endl;
	}
}

///////////////////////////////////////////////////////////
// metodo: tie_lo                                        //
// proposito: emite driving de celda tie lo.             //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::tie_lo(Node *node)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "net_tie_lo;" << endl;
	}
}

///////////////////////////////////////////////////////////
// metodo: xor2                                          //
// proposito: emite driving y asignacion de una xor.     //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::xor2(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara xor
	locals << "\twire xor_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "xor_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign xor_" << std::to_string(n) << " = net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << " ^ net_" << std::to_string(node->queryFanin(1));
	stmts << ";" << endl << endl;
}

///////////////////////////////////////////////////////////
// metodo: xnor2                                         //
// proposito: emite driving y asignacion de una xnor.    //
// argumentos:                                           //
//  node - informacion del nodo ( por referencia ).      //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Emitter::xnor2(Node *node, int n)
{
	vector<int> fanouts;

	fanouts = node->queryFanouts();

	// declara xor
	locals << "\twire xnor_" << std::to_string(n) << ";" << endl;

	for (auto &w : fanouts)
	{
		stmts << "\tassign net_" << w << " = ";
		stmts << "xnor_" << std::to_string(n) << ";" << endl;
	}

	stmts << endl;

	stmts << "\tassign xnor_" << std::to_string(n) << " = ~(net_";
	stmts << std::to_string(node->queryFanin(0));
	stmts << " ^ net_" << std::to_string(node->queryFanin(1));
	stmts << ");" << endl << endl;
}
