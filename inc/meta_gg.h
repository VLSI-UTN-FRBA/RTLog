///////////////////////////////////////////////////////////
// codigo fuente: meta_gg.h                              //
// fecha de inicio: 16/09/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase Meta Graph Generator para construir  //
//            un grafo simplificado a nivel de registros //
//            del circuito.                              //
//                                                       //
// clase implementada:                                   //
// propiedades:                                          //
//  nodes - meta nodos.                                  //
//  tmp_tree - arbol para accesos por referencia.        //
// metodos:                                              //
//  Meta_Gg - constructor de Meta_Gg.                    //
//  ~Meta_Gg - destructor de Meta_Gg.                    //
//  Find_FC - busca un fork controller que entrega un    //
//            latch.                                     //
//  Find_From_Id - busca el meta nodo con determinado    //
//                 id.                                   //
//  Find_JC - busca un join controller que recibe un     //
//            latch.                                     //
//  Get_Fout_Id - devuelve la lista de identificadores   //
//                de fan-out.                            //
//  Insert_LC - inserta latch controller en el meta      // 
//              grafo.                                   //
//  Make_Fork_Tree - construye los arboles de fork       //
//                   controllers.                        //
//  Make_Join_Tree - construye los arboles de join       //
//                   controllers.                        //
//  Print - muestra el meta grafo.                       //
//  Query_Fork_Tree - obtiene un arbol de fork           //
//                    controllers.                       //
//  Query_Fork_Tree_Count - obtiene la cantidad de       //
//                          arboles de fork controllers. //
//  Query_Join_Tree - obtiene un arbol de join           //
//                    controllers.                       //
//  Query_Join_Tree_Count - obtiene la cantidad de       //
//                          arboles de join controllers. //
//  Query_LC - obtiene el latch controller de un meta    //
//            nodo.                                      //
//  f_ident - imprime espacios de identacion.            //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __META_GG_H
#define __META_GG_H

#include <iostream>
#include <vector>

#include "meta_node.h"

class Meta_Gg
{
	private:
		std::vector<Meta_Node> nodes;

		BTree* tmp_tree;

        void f_ident(int ident);
	public:
		Meta_Gg();
		~Meta_Gg();
		int Find_FC(int i, int id, int &branch);
		int Find_From_Id(int id);
		int Find_JC(int i, int id, int &branch);
		std::vector<int> Get_Fout_Id(int i);
		void Insert_LC(int lc, int lid,
						std::vector<int> fin_ids,
						std::vector<int> fout_ids);
		void Make_Fork_Tree();
		void Make_Join_Tree();
        void Print(int ident);
		BTree* Query_Fork_Tree(int i);
		int Query_Fork_Tree_Count();
		BTree* Query_Join_Tree(int i);
		int Query_Join_Tree_Count();
		int Query_LC(int i);
};

#endif
