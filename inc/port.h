///////////////////////////////////////////////////////////
// codigo fuente: port.h                                 //
// fecha de inicio: 23/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase port para representar puertos en la  //
//            la tabla de puertos.                       //
//                                                       //
// clase implementada:                                   //
//  Port                                                 //
// propiedades:                                          //
//  name - nombre del puerto.                            //
//  dir - direccion del puerto.                          //
//  dim - dimension del puerto.                          //
//  nodes - nodos del bus.                               //
// metodos:                                              //
// clases amigas:                                        //
//  Parser                                               //
///////////////////////////////////////////////////////////

#ifndef __PORT_H
#define __PORT_H

using namespace std;

#include "tag.h"

class Port
{
	private:
		string name;
		tag_port dir;
		tag_reg	reg;
		int dim;
		vector<int> nodes;
	public:
		friend class Parser;
		friend class Emitter;
};

#endif
