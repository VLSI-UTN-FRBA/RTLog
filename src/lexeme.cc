///////////////////////////////////////////////////////////
// codigo fuente: lexeme.cc                              //
// fecha de inicio: 02/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase lexeme para representar lexemas de   //
//            codigo RTLog.                              //
//                                                       //
// clase implementada:                                   //
//  Lexeme                                               //
// propiedades:                                          //
//  str - lexema en si mismo.                            //
//  nline - numero de linea de la que fue extraido.      //
// metodos:                                              //
//  getNLine - devuelve el numero de linea.              //
//  getStr - devuelve el contenido del lexema.           //
// clases amigas:                                        //
//  Lexer - tiene que generar los lexemas.               //
///////////////////////////////////////////////////////////

#include "lexeme.h"

///////////////////////////////////////////////////////////
// metodo: getNLine                                      //
// proposito: devuelve el numero de linea.               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  contenido del lexema.                                //
///////////////////////////////////////////////////////////

int Lexeme::getNLine(void)
{
	return nline;
}

///////////////////////////////////////////////////////////
// metodo: getStr                                        //
// proposito: devuelve el contenido del lexema.          //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  contenido del lexema.                                //
///////////////////////////////////////////////////////////

std::string Lexeme::getStr(void)
{
	return str;
}
