///////////////////////////////////////////////////////////
// codigo fuente: symbol.h                               //
// fecha de inicio: 6/12/2017                            //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase symbol para representar elementos de //
//            la tabla de simbolos.                      //
//                                                       //
// clase implementada:                                   //
//  Symbol                                               //
// propiedades:                                          //
//  name - nombre del simbolo.                           //
//  used - simbolo en uso o libre.                       //
//  nets - nets que representa el simbolo.               //
//  nodes - nodos del bus.                               //
//  type - tipo de simbolo.                              //
// metodos:                                              //
// clases amigas:                                        //
//  Tokenizer                                            //
///////////////////////////////////////////////////////////

#ifndef __SYMBOL_H
#define __SYMBOL_H

using namespace std;

#include "tag.h"

class Symbol
{
	private:
		string name;
		bool used;
		int type;
		vector<int> nodes;
	public:
		friend class Tokenizer;
};

#endif
