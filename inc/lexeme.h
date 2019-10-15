///////////////////////////////////////////////////////////
// codigo fuente: lexeme.h                               //
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

#ifndef __LEXEME_H
#define __LEXEME_H

#include "lexer.h"

class Lexeme
{
	private:
		std::string str;
		int nline = 1;
	public:
		friend class Lexer;
		int getNLine(void);
		std::string getStr(void);
};

#endif
