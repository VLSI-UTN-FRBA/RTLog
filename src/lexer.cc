///////////////////////////////////////////////////////////
// codigo fuente: lexer.cc                               //
// fecha de inicio: 08/10/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase lexer para extraer lexemas de        //
//            codigo RTLog del archivo fuente.           //
//                                                       //
// clase implementada:                                   //
//  Lexer                                                //
// propiedades:                                          //
//  file - handler de archivo fuente.                    //
//  filename - nombre del archivo fuente.                //
//  m_old_pos - lista de posiciones previas.             //
//  m_recovery_points - lista con posiciones de          //
//                      retroceso.                       //
// metodos:                                              //
//  Lexer - constructor.                                 //
//  getNext - devuelve el proximo lexema.                //
//  readChar - lee un caracter del archivo fuente.       //
//  readCpChar - lee y compara un caracter del archivo   //
//            fuente.                                    //
//  recovery_point - establece un punto de retroceso.    //
//  restore - retrocede.                                 //
//  retract - retrocede un lexema.                       //
//  retreat - retrocede la posicion de lectura del       //
//            archivo.                                   //
//  source - agenda nombre de archivo.                   //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <fstream>

#include "lexer.h"
#include "lexeme.h"

///////////////////////////////////////////////////////////
// metodo: getNext                                       //
// proposito: devuelve el proximo lexema.                //
// argumentos:                                           //
//  lexeme - lexema obtenido ( por referencia ).         //
// devuelve:                                             //
//  true - no hubo errores.                              //
//  false - hubo errores.                                //
///////////////////////////////////////////////////////////

bool Lexer::getNext(class Lexeme &lexeme)
{
	lexeme.str = "";

	// descarta espacios delanteros
	while (1)
	{
		readChar();

		// fin del archivo fuente
		if (peek == 0)
		{
			return false;
		}

		// descarta espacios
		if (peek == ' ' || peek == '\t')
		{
			continue;
		}

		// new line
		// vale como lexema
		// pues RTLog solo admite una sentencia por linea
		if (peek == '\n')
		{
			oldPos = file.tellg();
			oldPos--;
			lexeme.str = '\n';
			lexeme.nline = nline;
			nline++;
			return true;
		}

		// encontro un caracter valido
		break;
	}

	oldPos = file.tellg();
	oldPos--;

	switch (peek)
	{
		case '(':
			// lexema (
			lexeme.str = "(";
			lexeme.nline = nline;
			return true;
		break;
		case ')':
			// lexema )
			lexeme.str = ")";
			lexeme.nline = nline;
			return true;
		break;
		case '[':
			// lexema [
			lexeme.str = "[";
			lexeme.nline = nline;
			return true;
		break;
		case ']':
			// lexema ]
			lexeme.str = "]";
			lexeme.nline = nline;
			return true;
		break;
		case '=':
			// lexema ==
			if (readCpChar('='))
			{
				lexeme.str = "==";
				lexeme.nline = nline;
				return true;
			}
			// lexema =
			else
			{
				lexeme.str = "=";
				lexeme.nline = nline;
				return true;
			}
		break;
		case '!':
			// lexema !=
			if (readCpChar('='))
			{
				lexeme.str = "!=";
				lexeme.nline = nline;
				return true;
			}
			// lexema !
			else
			{
				lexeme.str = "!";
				lexeme.nline = nline;
				return true;
			}
		break;
		case '>':
			// lexema >=
			if (readCpChar('='))
			{
				lexeme.str = ">=";
				lexeme.nline = nline;
				return true;
			}
			// lexema >>
			else if (readCpChar('>'))
			{
				lexeme.str = ">>";
				lexeme.nline = nline;
				return true;
			}
			// lexema >
			else
			{
				lexeme.str = ">";
				lexeme.nline = nline;
				return true;
			}
		break;
		case '<':
			// lexema <=
			if (readCpChar('='))
			{
				lexeme.str = "<=";
				lexeme.nline = nline;
				return true;
			}
			// lexema <<
			else if (readCpChar('<'))
			{
				lexeme.str = "<<";
				lexeme.nline = nline;
				return true;
			}
			// lexema <
			else
			{
				lexeme.str = "<";
				lexeme.nline = nline;
				return true;
			}
		break;
		case ':':
			// lexema :
			lexeme.str = ":";
			lexeme.nline = nline;
			return true;
		break;
		case '+':
			// lexema +x
			if (readCpChar('x'))
			{
				lexeme.str = "+x";
				lexeme.nline = nline;
				return true;
			}
			// lexema +
			else
			{
				lexeme.str = "+";
				lexeme.nline = nline;
				return true;
			}
		break;
		case '-':
			// lexema -x
			if (readCpChar('x'))
			{
				lexeme.str = "-x";
				lexeme.nline = nline;
				return true;
			}
			// lexema -
			else
			{
				lexeme.str = "-";
				lexeme.nline = nline;
				return true;
			}
		break;
		case '*':
			lexeme.str = "*";
			lexeme.nline = nline;
			return true;
		break;
		case '/':
			lexeme.str = "/";
			lexeme.nline = nline;
			return true;
		break;
		case ',':
			lexeme.str = ",";
			lexeme.nline = nline;
			return true;
		break;
		case '&':
			// lexema &d
			if (readCpChar('d'))
			{
				lexeme.str = "&d";
				lexeme.nline = nline;

				readChar();

				do
				{
					if (peek == 0)
					{
						break;
					}

					lexeme.str += peek;
					lexeme.nline = nline;
					readChar();
				}
				while (isdigit(peek));

				if (peek)
				{
					retreat();
				}

				return true;		
			}
			// lexema &b
			else if (readCpChar('b'))
			{
				lexeme.str = "&b";
				lexeme.nline = nline;

				readChar();

				do
				{
					if (peek == 0)
					{
						break;
					}

					lexeme.str += peek;
					lexeme.nline = nline;
					readChar();
				}
				while (peek == '1' || peek == '0');

				if (peek)
				{
					retreat();
				}

				return true;		
			}
			// lexema &h
			else if (readCpChar('h'))
			{
				lexeme.str = "&h";
				lexeme.nline = nline;

				readChar();

				do
				{
					if (peek == 0)
					{
						break;
					}

					lexeme.str += peek;
					lexeme.nline = nline;
					readChar();
				}
				while (isdigit(peek) || (peek >= 'a' && peek <= 'f'));

				if (peek)
				{
					retreat();
				}

				return true;		
			}

		break;
	}

	// es un digito
	if (isdigit(peek))
	{
		do
		{
			lexeme.str += peek;
			lexeme.nline = nline;
			readChar();
		}
		while (isdigit(peek));

		retreat();

		return true;
	}

	// es un identificador o u>> o s>>
	if (isalpha(peek))
	{
		lexeme.str += peek;
		lexeme.nline = nline;

		// posible s>>
		if (peek == 's')
		{
			// s>
			if (readCpChar('>'))
			{
				// s>>
				if (readCpChar('>'))
				{
					lexeme.str = "s>>";
					lexeme.nline = nline;

					return true;
				}
				// no cumple con las reglas de identificador
				// es s>
				else if (!(isalpha(peek) || isdigit(peek) || peek == '_'))
				{
					lexeme.str = "s>";
					lexeme.nline = nline;

					return true;
				}
			}
			// no cumple con las reglas de identificador
			// es s
			else if (!(isalpha(peek) || isdigit(peek) || peek == '_'))
			{
				lexeme.str = "s";
				lexeme.nline = nline;

				return true;
			}
		}

		// es un identificador
		readChar();

		while (isalpha(peek) || isdigit(peek) || peek == '_')
		{
			lexeme.str += peek;
			readChar();
		}

		retreat();

		return true;
	}

	// no es un identificador valido
	return false;
}

///////////////////////////////////////////////////////////
// metodo: readChar                                      //
// proposito: lee un caracter del archivo fuente.        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  ascii del caracter, 0 indica fin del archivo fuente. //
///////////////////////////////////////////////////////////

void Lexer::readChar(void)
{
	// si es el fin del archivo devuelve 0
	if (file.eof())
	{
		peek = 0;
	}
	else
	{
		peek = file.get();
	}
}

///////////////////////////////////////////////////////////
// metodo: readCpChar                                    //
// proposito: lee y compara un caracter del archivo      // 
//            fuente.                                    //
// argumentos:                                           //
//  c - caracter contra el cual compara.                 //
// devuelve:                                             //
//  true - el caracter leido es igual al propuesto.      //
//  false - el caracter leido es distinto al propuesto.  //
///////////////////////////////////////////////////////////

bool Lexer::readCpChar(char c)
{
	readChar();

	if (peek != c)
	{
		retreat();

		return false;
	}
	else
	{
		return true;
	}
}

///////////////////////////////////////////////////////////
// metodo: recovery_point                                //
// proposito: establece un punto de retroceso.           //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Lexer::recovery_point()
{
	int i;

	m_recovery_points.push_back(i = file.tellg());
	m_old_pos.push_back(oldPos);

	std::cout << "-remember " << i;
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////
// metodo: restore                                       //
// proposito: retrocede.                                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Lexer::restore()
{
	int i;

	std::cout << "-restore ";
	std::cout << this->m_recovery_points.back();
	std::cout << std::endl;

	this->file.seekg(this->m_recovery_points.back(),
						this->file.beg);

	this->m_recovery_points.pop_back();

	oldPos = this->m_old_pos.back();
	this->m_old_pos.pop_back();
}

///////////////////////////////////////////////////////////
// metodo: retract                                       //
// proposito: retrocede un lexema.                       //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Lexer::retract(void)
{
	// oldPos conserva la posicion del lexema previo
	file.seekg(oldPos, file.beg);
}

///////////////////////////////////////////////////////////
// metodo: retreat                                       //
// proposito: retrocede la posicion de lectura del       //
//            archivo.                                   //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Lexer::retreat(void)
{
	// retrocede la posicion de lectura del archivo
	// ya que es un punto de division
	// entre lexemas
	file.seekg(-1, file.cur);
}

///////////////////////////////////////////////////////////
// metodo: source                                        //
// proposito: agenda el nombre del archivo fuente.       //
// argumentos:                                           //
//  name - nombre del archivo fuente                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Lexer::source(std::string name)
{
	filename = name;
	file.open(name, ios::binary);
	nline = 1;
}

