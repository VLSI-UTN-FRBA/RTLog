///////////////////////////////////////////////////////////
// codigo fuente: btree.h                               //
// fecha de inicio: 15/09/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase btree para construir arboles         //
//            binarios.                                  //
//                                                       //
// clase implementada:                                   //
//  BTree                                                //
// propiedades:                                          //
//  cell - numero de celda del nodo.                     //
//  left - rama izquierda del arbol.                     //
//  right - rama derecha del arbol.                      //
//  node - atributo de nodo.                             //
// metodos:                                              //
//  BTree - constructor de BTree.                        //
//          ( 2 sobrecargas )                            //
//  ~BTree - destructor de BTree.                        //
//  Count - cuenta los elementos del arbol.              //
//  Find_C - busca un controller.                        //
//  Get_Cell - devuelve el numero de celda del           //
//             controlador.                              //
//  Get_Left - devuelve rama izquierda.                  //
//             ( por referencia )                        //
//  Get_Right - devuelve rama derecha.                   //
//              ( por referencia )                       //
//  Get_Node - devuelve el atributo del nodo.            //
//  Insert_Node - inserta un nodo en el arbol.           //
//  Print - muestra el arbol.                            //
//  Set_Cell - asigna el numero del celda en el grafo.   //
//  f_ident - imprime espacios de identacion.            //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __BTREE_H
#define __BTREE_H

#include "tag.h"

class BTree
{
	private:
		int cell;
		int node;
		BTree* left;
		BTree* right;

		int Count(BTree *b);
        void f_ident(int ident);
	public:
		BTree();
		BTree(int id);
		~BTree();
		bool Find_C(int &c, int id, int &branch);
		int Get_Cell();
		BTree* Get_Left();
		BTree* Get_Right();
		int Get_Node();
		void Insert_Node(BTree n);
		void Print(int ident);
		void Set_Cell(int n);
};

#endif
