///////////////////////////////////////////////////////////
// codigo fuente: meta_node.h                            //
// fecha de inicio: 17/09/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase Meta_Node para construir nodos en el //
//            meta grafo.                                //
//                                                       //
// clase implementada:                                   //
//  Meta_Node                                            //
// propiedades:                                          //
//  fin_ids - identificadores de los latches de fan-in.  //
//  fout_ids - identificadores de los latches de         //
//             fan-out.                                  //
//  fc_tree - arbol de fork controllers.                 //
//  id - identificador del latch.                        //
//  jc_tree - arbol de join controllers.                 //
//  lc - numero de nodo del latch controller.            //
// metodos:                                              //
//  Meta_Node - constructor de Meta_Node.                //
//  ~Meta_Node - destructor de Meta_Node.                //
//  Find_FC - busca un fork controller que entrega un    //
//            latch.                                     //
//  Find_JC - busca un join controller que recibe un     //
//            latch.                                     //
//  Get_Fin_Id - devuelve los identificadores de latches //
//               de fan-in.                              //
//  Get_Fout_Id - devuelve los identificadores de        //
//                latches de fan-out.                    //
//  Get_Id - devuelve identificador del latch.           //
//  Make_Fork_Tree - construye los arboles de fork       //
//                   controllers.                        //
//  Make_Join_Tree - construye los arboles de join       //
//                   controllers.                        //
//  Print - muestra el meta nodo.                        //
//  Query_Fork_Tree - obtiene el arbol de fork           //
//                    controllers.                       //
//  Query_Join_Tree - obtiene el arbol de join           //
//                    controllers.                       //
//  Query_LC - obtiene latch controller.                 //
//  Set_Fin_Id - carga los identificadores de latches de //
//               fan-in.                                 //
//  Set_Fout_Id - carga los identificadores de latches   //
//                de fan-in.                             //
//  Set_Id - carga el identificador del latch.           //
//  Set_LC - carga el numero de nodo del latch           //
//           controller.                                 //
//  f_ident - imprime espacios de identacion.            //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __META_NODE_H
#define __META_NODE_H

#include <iostream>
#include <vector>

#include "btree.h"

class Meta_Node
{
	private:
		int id;
		int lc;

		std::vector<int> fin_ids;
		std::vector<int> fout_ids;

		BTree jc_tree;
		BTree fc_tree;

        void f_ident(int ident);
	public:
		Meta_Node();
		~Meta_Node();
		int Find_FC(int id, int &branch);
		int Find_JC(int id, int &branch);
		std::vector<int> Get_Fin_Id();
		std::vector<int> Get_Fout_Id();
		int Get_Id();
		void Make_Fork_Tree();
		void Make_Join_Tree();
		void Print(int ident);
		BTree* Query_Fork_Tree();
		BTree* Query_Join_Tree();
		int Query_LC();
		void Set_Fin_Id(std::vector<int> fin);
		void Set_Fout_Id(std::vector<int> fout);
		void Set_Id(int i);
		void Set_LC(int l);
};

#endif
