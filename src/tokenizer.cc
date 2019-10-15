///////////////////////////////////////////////////////////
// codigo fuente: tokenizer.cc                           //
// fecha de inicio: 12/10/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase tokenizer para extraer tokens de     //
//            codigo RTLog del archivo fuente.           //
//                                                       //
// clase implementada:                                   //
//  Tokenizer                                            //
// propiedades:                                          //
//  lex - implementacion del Lexer.                      //
//  lexeme - lexema obtenido.                            //
//  symbol_table - tabla de simbolos.                    //
// metodos:                                              //
//  Tokenizer - constructor.                             //
//  annotateSymbolNodes - asocia nodos a un simbolo.     //
//  bin2Dec - convierte un binario a decimal.            //
//  dec2Bin - convierte un numero de decimal a binario.  //
//  isSymbolUsed - determina si un simbolo esta usado.   //
//  getNext - devuelve el proximo token.                 //
//  getNodes - obtiene el vector de nodos asociado a un  //
//            identificador.                             //
//  getNLine - devuelve numero de linea de codigo        //
//            analizado.                                 //
//  getNum - devuelve un int de la tabla de constantes.  //
//  getSymbol - devuelve un string de la tabla de        //
//            simbolos.                                  //
//  lockSymbol - cataloga un simbolo como usado.         //
//  numFindPush - busca un numero en la tabla de         //
//                constantes o lo agrega si no lo        //
//                encuentra.                             //
//  print_symbol_table: muestra la tabla de simbolos.    //
//  recovery_point - establece un punto de retroceso.    //
//  restore - retrocede.                                 //
//  retract - retrocede un token.                        //
//  set_type - asigna un tipo a un simbolo.              //
//  source - agenda nombre de archivo.                   //
//  symbolFindPush - busca un simbolo en la tabla de     //
//                   simbolos o lo agrega si no lo       //
//                   encuentra.                          //
//  unlock_symbol - cataloga un simbolo como no usado.   //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

using namespace std;

#include <algorithm>
#include <iostream>
#include <fstream>

#include "lexer.h"
#include "tag.h"
#include "token.h"
#include "tokenizer.h"

///////////////////////////////////////////////////////////
// metodo: annotateSymbolNodes                           //
// proposito: asocia nodos a un simbolo.                 //
// argumentos:                                           //
//  id - numero de simbolo.                              //
//  nodes - vector con varios nodes.                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::annotateSymbolNodes(int id, vector<int> nodes)
{
	symbol_table[id].nodes = nodes;
}

///////////////////////////////////////////////////////////
// metodo: bin2Dec                                       //
// proposito: convierte un binario a decimal.            //
// argumentos:                                           //
//  b - numero binario.                                  //
// devuelve:                                             //
//  numero decimal.                                      //
///////////////////////////////////////////////////////////

int Tokenizer::bin2Dec(string b)
{
	int d = 0;

	for (auto c : b)
	{
		d *= 2;

		if (c == '1')
		{
			d++;
		}
	}

	return d;
}

///////////////////////////////////////////////////////////
// metodo: dec2Bin                                       //
// proposito: convierte un numero de decimal a binario.  //
// argumentos:                                           //
//  d - numero en decimal.                               //
//  expc_width - longitud de palabra esperada en el      //
//               resultado.                              //
// devuelve:                                             //
//  vector con los bits en binario.                      //
///////////////////////////////////////////////////////////

vector<int> Tokenizer::dec2Bin(unsigned int d, 
								unsigned int expc_width)
{
	int c = 0;
	int i;
	vector<int> bin;

	// es un 0
	if (d == 0)
	{
		bin.push_back(0);

		c++;

		// completa con 0
		// para darle generalidad a las constantes
		if (c < expc_width)
		{	
			for (i = c; i < expc_width; i++)
			{
				bin.push_back(0);
			}
		}

		return bin;
	}

	// obtiene todos los bits
	while (d != 0)
	{
		bin.push_back(d % 2);
		d = d / 2;
		c++;
	}

	// completa con 0
	// para darle generalidad a las constantes
	if (c < expc_width)
	{	
		for (i = c; i < expc_width; i++)
		{
			bin.push_back(0);
		}
	}

	return bin;
}

///////////////////////////////////////////////////////////
// metodo: hex2Dec                                       //
// proposito: convierte un hexadecimal a decimal.        //
// argumentos:                                           //
//  h - numero hexadecimal.                              //
// devuelve:                                             //
//  numero decimal.                                      //
///////////////////////////////////////////////////////////

int Tokenizer::hex2Dec(string h)
{
	int d = 0;

	for (auto c : h)
	{
		d *= 16;

		if (isdigit(c))
		{
			d += (c - '0');
		}
		else
		{
			d += (c - 'a' + 10);
		}
	}

	return d;
}

///////////////////////////////////////////////////////////
// metodo: isSymbolUsed                                  //
// proposito: determina si un simbolo esta usado.        //
// argumentos:                                           //
//  id - numero de simbolo.                              //
// devuelve:                                             //
//  true - esta usado.                                   //
//  false - no esta usado.                               //
///////////////////////////////////////////////////////////

bool Tokenizer::isSymbolUsed(int id)
{
	return symbol_table[id].used;
}

///////////////////////////////////////////////////////////
// metodo: getNext                                       //
// proposito: devuelve el proximo token.                 //
// argumentos:                                           //
//  token - toekn obtenido ( por referencia ).           //
// devuelve:                                             //
//  true - no hubo errores.                              //
//  false - hubo errores.                                //
///////////////////////////////////////////////////////////

bool Tokenizer::getNext(class Token &token)
{
	bool ret;
	string str;

	token.type = TK_VOID;
	token.n = 0;

	// solicita un lexema
	ret = lex.getNext(lexeme);

	// fin del archivo fuente
	if (!ret)
	{
		return false;
	}

	str = lexeme.getStr();
	nline = lexeme.getNLine();

	// keywords	

	// logic
	if (str == "logic")
	{
		token.type = TK_KW;
		token.n = KW_LOGIC;
	}
	// input
	else if (str == "input")
	{
		token.type = TK_KW;
		token.n = KW_INPUT;
	}
	// output
	else if (str == "output")
	{
		token.type = TK_KW;
		token.n = KW_OUTPUT;
	}
	// reg
	else if (str == "reg")
	{
		token.type = TK_KW;
		token.n = KW_REG;
	}
	// block
	else if (str == "block")
	{
		token.type = TK_KW;
		token.n = KW_BLOCK;
	}
	// begin
	else if (str == "begin")
	{
		token.type = TK_KW;
		token.n = KW_BEGIN;
	}
	// parameters
	else if (str == "parameters")
	{
		token.type = TK_KW;
		token.n = KW_PARAM;
	}
	// natural
	else if (str == "natural")
	{
		token.type = TK_KW;
		token.n = KW_NATURAL;
	}
	/* constant */
	else if (str == "constant")
	{
		token.type = TK_KW;
		token.n = KW_CONSTANT;
	}
	// ports
	else if (str == "ports")
	{
		token.type = TK_KW;
		token.n = KW_PORTS;
	}
	// end
	else if (str == "end")
	{
		token.type = TK_KW;
		token.n = KW_END;
	}
	// cat
	else if (str == "cat")
	{
		token.type = TK_KW;
		token.n = KW_CAT;
	}
	// rep
	else if (str == "rep")
	{
		token.type = TK_KW;
		token.n = KW_REP;
	}
	// others
	else if (str == "others")
	{
		token.type = TK_KW;
		token.n = KW_OTHERS;
	}
	// not
	else if (str == "not")
	{
		token.type = TK_KW;
		token.n = KW_NOT;
	}
	// or
	else if (str == "or")
	{
		token.type = TK_KW;
		token.n = KW_OR;
	}
	// and
	else if (str == "and")
	{
		token.type = TK_KW;
		token.n = KW_AND;
	}
	// xor
	else if (str == "xor")
	{
		token.type = TK_KW;
		token.n = KW_XOR;
	}
	// xnor
	else if (str == "xnor")
	{
		token.type = TK_KW;
		token.n = KW_XNOR;
	}
	// if
	else if (str == "if")
	{
		token.type = TK_KW;
		token.n = KW_IF;
	}
	// elsif
	else if (str == "elsif")
	{
		token.type = TK_KW;
		token.n = KW_ELSIF;
	}
	// else
	else if (str == "else")
	{
		token.type = TK_KW;
		token.n = KW_ELSE;
	}
	// case
	else if (str == "case")
	{
		token.type = TK_KW;
		token.n = KW_CASE;
	}
	// for
	else if (str == "for")
	{
		token.type = TK_KW;
		token.n = KW_FOR;
	}
	// in
	else if (str == "in")
	{
		token.type = TK_KW;
		token.n = KW_IN;
	}
	// range
	else if (str == "range")
	{
		token.type = TK_KW;
		token.n = KW_RANGE;
	}
	// when
	else if (str == "when")
	{
		token.type = TK_KW;
		token.n = KW_WHEN;
	}
	// operadores
	// (
	else if (str == "(")
	{
		token.type = TK_OP;
		token.n = OP_PAR_OP;
	}
	// )
	else if (str == ")")
	{
		token.type = TK_OP;
		token.n = OP_PAR_CL;
	}
	// [
	else if (str == "[")
	{
		token.type = TK_OP;
		token.n = OP_IX_OP;
	}
	// ]
	else if (str == "]")
	{
		token.type = TK_OP;
		token.n = OP_IX_CL;
	}
	// =
	else if (str == "=")
	{
		token.type = TK_OP;
		token.n = OP_ASSGN;
	}
	// :
	else if (str == ":")
	{
		token.type = TK_OP;
		token.n = OP_RANGE;
	}
	// u>>
	else if (str == "u>>")
	{
		token.type = TK_OP;
		token.n = OP_USHFT;
	}
	// s>>
	else if (str == "s>>")
	{
		token.type = TK_OP;
		token.n = OP_SSHFT;
	}
	// <<
	else if (str == "<<")
	{
		token.type = TK_OP;
		token.n = OP_LSHFT;
	}
	// +
	else if (str == "+")
	{
		token.type = TK_OP;
		token.n = OP_ADD;
	}
	// +x
	else if (str == "+x")
	{
		token.type = TK_OP;
		token.n = OP_ADDC;
	}
	// -
	else if (str == "-")
	{
		token.type = TK_OP;
		token.n = OP_SUB;
	}
	// -x
	else if (str == "-x")
	{
		token.type = TK_OP;
		token.n = OP_SUBB;
	}
	// *
	else if (str == "*")
	{
		token.type = TK_OP;
		token.n = OP_MULT;
	}
	/* / */
	else if (str == "/")
	{
		token.type = TK_OP;
		token.n = OP_DIV;
	}
	// ,
	else if (str == ",")
	{
		token.type = TK_OP;
		token.n = OP_COMMA;
	}
	// ==
	else if (str == "==")
	{
		token.type = TK_OP;
		token.n = OP_CP_EQ;
	}
	// !=
	else if (str == "!=")
	{
		token.type = TK_OP;
		token.n = OP_CP_NEQ;
	}
	// >
	else if (str == ">")
	{
		token.type = TK_OP;
		token.n = OP_CP_GR;
	}

	// >=
	else if (str == ">=")
	{
		token.type = TK_OP;
		token.n = OP_CP_GREQ;
	}
	// <
	else if (str == "<")
	{
		token.type = TK_OP;
		token.n = OP_CP_LW;
	}
	// <=
	else if (str == "<=")
	{
		token.type = TK_OP;
		token.n = OP_CP_LWEQ;
	}
	// >>
	else if (str == ">>")
	{
		token.type = TK_OP;
		token.n = OP_USHFT;
	}
	// new line
	else if (str == "\n")
	{
		token.type = TK_NL;
		token.n = 0;
	}
	// constants
	else if (isdigit(str[0]))
	{
		token.type = TK_NUM;

		// busca si el identificador ya esta
		// en la tabla de constantes
		token.n = numFindPush(std::stoi(str));
	}
	// identifier
	else if (isalpha(str[0]))
	{
		token.type = TK_ID;

		// busca si el identificador ya esta
		// en la tabla de simbolos
		token.n = symbolFindPush(str);
	}
	// constants ( &d, &h )
	else if(str[0] == '&')
	{
		switch (str[1])
		{
			case 'd':
				token.type = TK_NUM;

				// busca si el identificador ya esta
				// en la tabla de constantes
				token.n = numFindPush(std::stoi(str.substr(2)));
			break;
			case 'b':
				token.type = TK_NUM;

				// busca si el identificador ya esta
				// en la tabla de constantes
				token.n = numFindPush(bin2Dec(str.substr(2)));
			break;
			case 'h':
				token.type = TK_NUM;

				// busca si el identificador ya esta
				// en la tabla de constantes
				token.n = numFindPush(hex2Dec(str.substr(2)));
			break;
			default:
				;
		}
	}

	return true;
}

///////////////////////////////////////////////////////////
// metodo: getNodes                                      //
// proposito: obtiene el vector de nodos asociado a un   //
//            identificador.                             //
// argumentos:                                           //
//  id - numero de identificador.                        //
// devuelve:                                             //
//  numero de nodo.                                      //
///////////////////////////////////////////////////////////

vector<int> Tokenizer::getNodes(int id)
{
	return symbol_table[id].nodes;
}

///////////////////////////////////////////////////////////
// metodo: getNLine                                      //
// proposito: devuelve numero de linea de codigo         //
//            analizado.                                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  constante.                                           //
///////////////////////////////////////////////////////////

int Tokenizer::getNLine(void)
{
	return nline;
}

///////////////////////////////////////////////////////////
// metodo: lockSymbol                                    //
// proposito: cataloga un simbolo como usado.            //
// argumentos:                                           //
//  id - numero de simbolo.                              //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::lockSymbol(int id)
{
	symbol_table[id].used = true;
}

///////////////////////////////////////////////////////////
// metodo: numFindPush                                   //
// proposito: busca un numero en la tabla de constantes  //
//            o lo agrega si no lo encuentra.            //
// argumentos:                                           //
//  c - constante.                                       //
// devuelve:                                             //
//  posicion en la tabla de constantes.                  //
///////////////////////////////////////////////////////////

int Tokenizer::numFindPush(int c)
{
	int n;
	std::vector<int>::iterator it;

	// no esta en la tabla de constantes
	if ((it = std::find(num_table.begin(), num_table.end(), 
			c)) == num_table.end())
	{
		num_table.push_back(c);

		n = num_table.size() - 1;
	}
	else
	{
		n = it - num_table.begin();
	}

	return n;
}

///////////////////////////////////////////////////////////
// metodo: getNum                                        //
// proposito: devuelve un int de la tabla de constantes. //
// argumentos:                                           //
//  id - id de la constante.                             //
// devuelve:                                             //
//  constante.                                           //
///////////////////////////////////////////////////////////

int Tokenizer::getNum(int id)
{
	return num_table[id];
}

///////////////////////////////////////////////////////////
// metodo: getSymbol                                     //
// proposito: devuelve un string de la tabla de          //
//            simbolos.                                  //
// argumentos:                                           //
//  id - id del simbolo.                                 //
// devuelve:                                             //
//  string del simbolo.                                  //
///////////////////////////////////////////////////////////

std::string Tokenizer::getSymbol(int id)
{
	return symbol_table[id].name;
}

///////////////////////////////////////////////////////////
// metodo: print_symbol_table                            //
// proposito: muestra la tabla de simbolos.              //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::print_symbol_table(void)
{
	int n = 0;

	cout << "Symbol table" << endl;
	cout << "------ -----" << endl;
	cout << "id\t\t\t" << "symbol" << endl;
	cout << "--\t\t\t" << "------" << endl;

	for (auto &s : symbol_table)
	{
		cout << n << "\t\t\t" << s.name << endl;

		n++;
	}

	cout << endl;
}

///////////////////////////////////////////////////////////
// metodo: recovery_point                                //
// proposito: establece un punto de retroceso.           //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::recovery_point()
{
	lex.recovery_point();
}

///////////////////////////////////////////////////////////
// metodo: restore                                       //
// proposito: retrocede.                                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::restore()
{
	lex.restore();
}

///////////////////////////////////////////////////////////
// metodo: retract                                       //
// proposito: retrocede un token.                        //
// argumentos:                                           //
//  name - nombre del archivo fuente                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::retract(void)
{
	lex.retract();
}

///////////////////////////////////////////////////////////
// metodo: set_type                                      //
// proposito: asigna un tipo a un simbolo.               //
// argumentos:                                           //
//  id - numero de simbolo.                              //
//  t - tipo asignado.                                   //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::set_type(int id, int t)
{
	symbol_table[id].type = t;
}

///////////////////////////////////////////////////////////
// metodo: source                                        //
// proposito: agenda el nombre del archivo fuente.       //
// argumentos:                                           //
//  name - nombre del archivo fuente                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Tokenizer::source(std::string name)
{
	// carga nombre del archivo fuente
	lex.source(name);
}

///////////////////////////////////////////////////////////
// metodo: symbolFindPush                                //
// proposito: busca un simbolo en la tabla de simbolos o //
//            lo agrega si no lo encuentra.              //
// argumentos:                                           //
//  str - simbolo.                                       //
// devuelve:                                             //
//  posicion en la tabla de simbolos.                    //
///////////////////////////////////////////////////////////

int Tokenizer::symbolFindPush(std::string str)
{
	int n;
	std::vector<Symbol>::iterator it;
	Symbol s;

	it = find_if(symbol_table.begin(), symbol_table.end(), 
				[=](class Symbol &obj) {return obj.name == str;});

	// no esta en la tabla de simbolos
	if (it == symbol_table.end())
	{
		s.name = str;
		s.type = E_TYPE_ID;
		s.used = false;
		symbol_table.push_back(s);
		n = symbol_table.size() - 1;
	}
	else
	{
		n = it - symbol_table.begin();
	}

	return n;
}

/*********************************************************
 * metodo: unlock_symbol                                 *
 * proposito: cataloga un simbolo como no usado.         *
 * argumentos:                                           *
 *  id - numero de simbolo.                              *
 * devuelve:                                             *
 *  nada.                                                *
 *********************************************************/

void Tokenizer::unlock_symbol(int id)
{
	symbol_table[id].used = false;
}
