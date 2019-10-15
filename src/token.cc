///////////////////////////////////////////////////////////
// codigo fuente: token.cc                               //
// fecha de inicio: 3/12/2017                            //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase tokens para representar tokens de    //
//            codigo RTLog.                              //
//                                                       //
// clase implementada:                                   //
//  Token                                                //
// propiedades:                                          //
//  type - tipo de token.                                //
//  n - clasificacion de token o numero.                 //
// metodos:                                              //
//  Token - constructores ( 2 ).                         //
//  getN - devuelve el atributo.                         //
//  match - comprueba si un token es tiene el id         //
//            solicitado ( 2 sobrecargas ).              //
//  print - muestra un token.                            //
// operadores:                                           //
//  == - compara ( por igual ) 2 tokens.                 //
// clases amigas:                                        //
//  Tokenizer                                            //
///////////////////////////////////////////////////////////

#include <iostream>

#include "token.h"

///////////////////////////////////////////////////////////
// metodo: Token                                         //
// proposito: constructor de Token.                      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Token::Token()
{
}

///////////////////////////////////////////////////////////
// metodo: Token                                         //
// proposito: constructor de Token.                      //
// argumentos:                                           //
//  t - tipo de token.                                   //
//  a - atributo del token.                              //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Token::Token(token_type t, int a)
{
	type = t;
	n = a;	
}

///////////////////////////////////////////////////////////
// metodo: getN                                          //
// proposito: devuelve el atributo.                      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  atributo del token.                                  //
///////////////////////////////////////////////////////////

int Token::getN(void)
{
	return n;
}

///////////////////////////////////////////////////////////
// metodo: match                                         //
// proposito: comprueba si un token es tiene el id       //
//            solicitado.                                //
// argumentos:                                           //
//  t - tipo de token solicitado.                        //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

bool Token::match(token_type t)
{
	if (type == t)
	{
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////
// metodo: match                                         //
// proposito: comprueba si un token es tiene el id y el  //
//            atributo solicitado.                       //
// argumentos:                                           //
//  t - tipo de token solicitado.                        //
//  a - atributo solicitado.                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

bool Token::match(token_type t, int a)
{
	if (type == t && n == a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////
// metodo: print                                         //
// proposito: muestra un token.                          //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Token::print(void)
{
	cout << "<";

	// keyword
	if (type == TK_KW)
	{
		cout << "KW,";

		switch (n)
		{
			case KW_LOGIC:
				cout << "LOGIC";
			break;
			case KW_INPUT:
				cout << "INPUT";
			break;
			case KW_OUTPUT:
				cout << "OUTPUT";
			break;
			case KW_REG:
				cout << "REG";
			break;
			case KW_BLOCK:
				cout << "BLOCK";
			break;
			case KW_BEGIN:
				cout << "BEGIN";
			break;
			case KW_PARAM:
				cout << "PARAM";
			break;
			case KW_NATURAL:
				cout << "NATURAL";
			break;
			case KW_END:
				cout << "END";
			break;
			case KW_PORTS:
				cout << "PORTS";
			break;
			case KW_CAT:
				cout << "CAT";
			break;
			case KW_REP:
				cout << "REP";
			break;
			case KW_OTHERS:
				cout << "OTHERS";
			break;
			case KW_NOT:
				cout << "NOT";
			break;
			case KW_OR:
				cout << "OR";
			break;
			case KW_AND:
				cout << "AND";
			break;
			case KW_XOR:
				cout << "XOR";
			break;
			case KW_XNOR:
				cout << "XNOR";
			break;
			case KW_IF:
				cout << "IF";
			break;
			case KW_ELSIF:
				cout << "ELSIF";
			break;
			case KW_ELSE:
				cout << "ELSE";
			break;
			case KW_CASE:
				cout << "CASE";
			break;
			case KW_FOR:
				cout << "FOR";
			break;
			case KW_IN:
				cout << "IN";
			break;
			case KW_RANGE:
				cout << "RANGE";
			break;
			case KW_WHEN:
				cout << "WHEN";
			break;
		}
	}
	// operadores
	else if (type == TK_OP)
	{
		cout << "OP,";

		switch (n)
		{
			case OP_PAR_OP:
				cout << "(";
			break;
			case OP_PAR_CL:
				cout << ")";
			break;

			case OP_IX_OP:
				cout << "[";
			break;
			case OP_IX_CL:
				cout << "]";
			break;
			case OP_ASSGN:
				cout << "=";
			break;
			case OP_RANGE:
				cout << ":";
			break;
			case OP_USHFT:
				cout << "U>>";
			break;
			case OP_SSHFT:
				cout << "S>>";
			break;
			case OP_LSHFT:
				cout << "<<";
			break;
			case OP_ADD:
				cout << "+";
			break;
			case OP_ADDC:
				cout << "+x";
			break;
			case OP_SUB:
				cout << "-";
			break;
			case OP_SUBB:
				cout << "-x";
			break;
			case OP_MULT:
				cout << "x";
			break;
			case OP_DIV:
				std::cout << "/";
			break;
			case OP_COMMA:
				cout << ",";
			break;
		}
	}
	// new line
	else if (type == TK_NL)
	{
		cout << "NL,";
	}
	// constantes
	else if (type == TK_NUM)
	{
		cout << "NUM, " << n;
	}
	// identificadores
	else if (type == TK_ID)
	{
		cout << "ID, " << n;
	}

	cout << ">" << endl;
}
