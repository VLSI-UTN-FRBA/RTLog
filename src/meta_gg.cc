///////////////////////////////////////////////////////////
// codigo fuente: meta_gg.cc                             //
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

#include "meta_gg.h"

///////////////////////////////////////////////////////////
// metodo: Meta_Gg                                       //
// proposito: constructor de Meta_Gg.                    //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Meta_Gg::Meta_Gg()
{
}

///////////////////////////////////////////////////////////
// metodo: ~Meta_Gg                                      //
// proposito: destructor de Meta_Gg.                     //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Meta_Gg::~Meta_Gg()
{
}

///////////////////////////////////////////////////////////
// metodo: Find_FC                                       //
// proposito: busca un fork controller que entrega un    //
//            latch.                                     //
// argumentos:                                           //
//  i - numero de meta nodo.                             //
//  branch - rama del fork controller al cual esta       //
//           conectado el latch ( por referencia ).      //
// devuelve:                                             //
//  busca un fork controller que entrega un latch.       //
///////////////////////////////////////////////////////////

int Meta_Gg::Find_FC(int i, int id, int &branch)
{
	int fc;

	fc = nodes[i].Find_FC(id, branch);

	return fc;
}

///////////////////////////////////////////////////////////
// metodo: Find_From_Id                                  //
// proposito: busca el meta nodo con determinado id.     //
// argumentos:                                           //
//  id - identificador.                                  //
// devuelve:                                             //
//  indice en la lista de meta nodos.                    //
///////////////////////////////////////////////////////////

int Meta_Gg::Find_From_Id(int id)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].Get_Id() == id)
		{
			return i;
		}
	}

	return -1;
}

///////////////////////////////////////////////////////////
// metodo: Find_JC                                       //
// proposito: busca un join controller que recibe un     //
//            latch.                                     //
// argumentos:                                           //
//  i - numero de meta nodo.                             //
//  branch - rama del join controller al cual esta       //
//           conectado el latch ( por referencia ).      //
// devuelve:                                             //
//  busca un join controller que recibe un latch.        //
///////////////////////////////////////////////////////////

int Meta_Gg::Find_JC(int i, int id, int &branch)
{
	int jc;

	jc = nodes[i].Find_JC(id, branch);

	return jc;
}

///////////////////////////////////////////////////////////
// metodo: Get_Fout_Id                                   //
// proposito: devuelve la lista de identificadores de    //
//            fan-out.                                   //
// argumentos:                                           //
//  i - indice en la lisa de meta nodos.                 //
// devuelve:                                             //
//  lista de identificadores de fan-out.                 //
///////////////////////////////////////////////////////////

std::vector<int> Meta_Gg::Get_Fout_Id(int i)
{
	return nodes[i].Get_Fout_Id();
}

///////////////////////////////////////////////////////////
// metodo: Insert_LC                                     //
// proposito: inserta latch controller en el meta grafo. //
// argumentos:                                           //
//  lc - numero de nodo del latch controller.            //
//  lid - identificador del latch.                       //
//  fin_ids - lista de identificadores de los latches de //
//            fan-in.                                    //
//  fout_ids - lista de identificadores de los latches   //
//             de fan-out.                               //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Gg::Insert_LC(int lc, int lid,
						std::vector<int> fin_ids,
						std::vector<int> fout_ids)
{
	Meta_Node node;

	node.Set_LC(lc);
	node.Set_Id(lid);
	node.Set_Fin_Id(fin_ids);
	node.Set_Fout_Id(fout_ids);
	nodes.push_back(node);
}

///////////////////////////////////////////////////////////
// metodo: Make_Fork_Tree                                //
// proposito: construye los arboles de fork controllers. //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Gg::Make_Fork_Tree()
{
	// recorre todos los latch controllers
	for (auto &l : nodes)
	{
		l.Make_Fork_Tree();
	}
}

///////////////////////////////////////////////////////////
// metodo: Make_Join_Tree                                //
// proposito: construye los arboles de join controllers. //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Gg::Make_Join_Tree()
{
	std::vector<int> fin_ids;

	// recorre todos los latch controllers
	for (auto &l : nodes)
	{
		l.Make_Join_Tree();
	}
}

///////////////////////////////////////////////////////////
// metodo: Print                                         //
// proposito: muestra el meta grafo.                     //
// argumentos:                                           //
//  ident - nivel de identacion.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Gg::Print(int ident)
{
	int i = 0;

	for (auto &m : nodes)
	{
        this->f_ident(ident);
		std::cout << "Meta Node Index: " << i;
		std::cout << std::endl;

		m.Print(ident + 2);

		std::cout << std::endl;

		i++;
	}
}

///////////////////////////////////////////////////////////
// metodo: Query_Fork_Tree_Count                         //
// proposito: obtiene la cantidad de arboles de fork     //
//            controllers.                               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  obtiene la cantidad de arboles de fork controllers.  //
///////////////////////////////////////////////////////////

int Meta_Gg::Query_Fork_Tree_Count()
{
	return nodes.size();
}

///////////////////////////////////////////////////////////
// metodo: Query_Fork_Tree                               //
// proposito: obtiene un arbol de fork controllers.      //
// argumentos:                                           //
//  i - numero de arbol.                                 //
// devuelve:                                             //
//  arbol de fork controllers ( por referencia ).        //
///////////////////////////////////////////////////////////

BTree* Meta_Gg::Query_Fork_Tree(int i)
{
	tmp_tree = nodes[i].Query_Fork_Tree();

	return tmp_tree;
}

///////////////////////////////////////////////////////////
// metodo: Query_Join_Tree                               //
// proposito: obtiene un arbol de join controllers.      //
// argumentos:                                           //
//  i - numero de arbol.                                 //
// devuelve:                                             //
//  arbol de join controllers ( por referencia ).        //
///////////////////////////////////////////////////////////

BTree* Meta_Gg::Query_Join_Tree(int i)
{
	tmp_tree = nodes[i].Query_Join_Tree();

	return tmp_tree;
}

///////////////////////////////////////////////////////////
// metodo: Query_Join_Tree_Count                         //
// proposito: obtiene la cantidad de arboles de join     //
//            controllers.                               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  obtiene la cantidad de arboles de join controllers.  //
///////////////////////////////////////////////////////////

int Meta_Gg::Query_Join_Tree_Count()
{
	return nodes.size();
}

///////////////////////////////////////////////////////////
// metodo: Query_LC                                      //
// proposito: obtiene el latch controller de un meta     //
//            nodo.                                      //
// argumentos:                                           //
//  i - numero de arbol.                                 //
// devuelve:                                             //
//  latch controller.                                    //
///////////////////////////////////////////////////////////

int Meta_Gg::Query_LC(int i)
{
	return nodes[i].Query_LC();
}

/**********************************************************
 * metodo: f_ident                                        *
 * proposito: imprime espacios de identacion.             *
 * parametros:                                            *
 *  ident - nivel de identacion.                          *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Meta_Gg::f_ident(int ident)
{
    for (int _i = 0; _i < ident; ++_i)
    {
        std::cout << " ";
    }
}
