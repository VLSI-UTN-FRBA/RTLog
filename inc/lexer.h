///////////////////////////////////////////////////////////
// codigo fuente: lexer.h                                //
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

#ifndef __LEXER_H
#define __LEXER_H

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>

class Lexer
{
	private:
		char peek;
		unsigned int nline;
		int oldPos;
		std::string filename;
		std::ifstream file;
		vector<int> m_recovery_points;
		vector<int> m_old_pos;

		void readChar(void);
		bool readCpChar(char c);
		void retreat(void);

	public:
		bool getNext(class Lexeme &lexeme);
		void recovery_point();
		void restore();
		void retract(void);
		void source(std::string name);
};

#endif
