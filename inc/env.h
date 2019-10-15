///////////////////////////////////////////////////////////
// codigo fuente: env.h                                  //
// fecha de inicio: 11/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase enviroment para representar el       //
//            anidamiento de sentencias if.              //
//                                                       //
// clase implementada:                                   //
//  Env                                                  //
// propiedades:                                          //
//  node - net buffereado que determina la condicion en  //
//         un if o vector de seleccion en un case.       //
//  data_in - entrada de datos del multiplexor.          //
//  is_case - es un if o un case.                        //
// metodos:                                              //
// clases amigas:                                        //
//  Parser                                               //
///////////////////////////////////////////////////////////

#ifndef __ENV_H
#define __ENV_H

#include <vector>

class Env
{
	private:
		vector<int> node;
		int data_in;
		bool is_case;
	public:
		friend class Parser;
};

#endif
