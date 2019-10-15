///////////////////////////////////////////////////////////
// codigo fuente: meta_node.cc                          //
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

#include "meta_node.h"

///////////////////////////////////////////////////////////
// metodo: Meta_Node                                     //
// proposito: constructor de Meta_Node.                  //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Meta_Node::Meta_Node()
{
}

///////////////////////////////////////////////////////////
// metodo: ~Meta_Node                                    //
// proposito: destructor de Meta_Node.                   //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

Meta_Node::~Meta_Node()
{
}

///////////////////////////////////////////////////////////
// metodo: Find_FC                                       //
// proposito: busca un fork controller que entrega un    //
//            latch.                                     //
// argumentos:                                           //
//  id - identificador del latch.                        //
//  branch - rama del fork controller al cual esta       //
//           conectado el latch ( por referencia ).      //
// devuelve:                                             //
//  busca un fork controller que recibe un latch.        //
///////////////////////////////////////////////////////////

int Meta_Node::Find_FC(int id, int &branch)
{
	int fc;

	fc_tree.Find_C(fc, id, branch);

	return fc;
}

///////////////////////////////////////////////////////////
// metodo: Find_JC                                       //
// proposito: busca un join controller que recibe un     //
//            latch.                                     //
// argumentos:                                           //
//  id - identificador del latch.                        //
//  branch - rama del join controller al cual esta       //
//           conectado el latch ( por referencia ).      //
// devuelve:                                             //
//  busca un join controller que recibe un latch.        //
///////////////////////////////////////////////////////////

int Meta_Node::Find_JC(int id, int &branch)
{
	int jc;

	jc_tree.Find_C(jc, id, branch);

	return jc;
}

///////////////////////////////////////////////////////////
// metodo: Get_Fin_Id                                    //
// proposito: devuelve los identificadores de latches de //
//            fan-in.                                    //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  identificadores de los latches de fan-in.            //
///////////////////////////////////////////////////////////

std::vector<int> Meta_Node::Get_Fin_Id()
{
	return fin_ids;
}

///////////////////////////////////////////////////////////
// metodo: Get_Fout_Id                                   //
// proposito: devuelve los identificadores de latches de //
//            fan-out.                                   //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  identificadores de los latches de fan-out.           //
///////////////////////////////////////////////////////////

std::vector<int> Meta_Node::Get_Fout_Id()
{
	return fout_ids;
}

///////////////////////////////////////////////////////////
// metodo: Get_Id                                        //
// proposito: devuelve identificador del latch.          //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  identificador del latch.                             //
///////////////////////////////////////////////////////////

int Meta_Node::Get_Id()
{
	return id;
}

///////////////////////////////////////////////////////////
// metodo: Make_Fork_Tree                                //
// proposito: construye los arboles de fork controllers. //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Make_Fork_Tree()
{
	// no hay latches de fan-out
	// no existe arbol de fork-controllers
	if (fout_ids.size() == 0)
	{
		return;
	}
/*
	std::cout << "Making fork tree";
	std::cout << std::endl;
	std::cout << std::endl;*/

	// un solo latch de fan-out
	// no existe arbol de fork-controllers
	// conecta los latch controllers directamente
	if (fout_ids.size() == 1)
	{
		BTree lc_node(fout_ids[0]);

		fc_tree.Insert_Node(lc_node);

		return;
	}

	for (auto f : fout_ids)
	{
		BTree lc_node(f);
/*
		std::cout << "Inserting Id: ";
		std::cout << f;
		std::cout << std::endl;		*/

		fc_tree.Insert_Node(lc_node);
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

void Meta_Node::Make_Join_Tree()
{
	// no hay latches de fan-in
	// no existe arbol de join-controllers
	if (fin_ids.size() == 0)
	{
		return;
	}
/*
	std::cout << "Making join tree";
	std::cout << std::endl;
	std::cout << std::endl;*/

	// un solo latch de fan-in
	// no existe arbol de join-controllers
	// conecta los latch controllers directamente
	if (fin_ids.size() == 1)
	{
		BTree lc_node(fin_ids[0]);

		jc_tree.Insert_Node(lc_node);

		return;
	}

	for (auto f : fin_ids)
	{
		BTree lc_node(f);
/*
		std::cout << "Inserting Id: ";
		std::cout << f;
		std::cout << std::endl;		*/

		jc_tree.Insert_Node(lc_node);
	}
}

///////////////////////////////////////////////////////////
// metodo: Print                                         //
// proposito: muestra el meta nodo.                      //
// argumentos:                                           //
//  ident - nivel de identacion.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Print(int ident)
{
    this->f_ident(ident);
	std::cout << "Logic Controller: ";
	std::cout << lc;
	std::cout << std::endl;

    this->f_ident(ident);
	std::cout << "Id: ";
	std::cout << id;
	std::cout << std::endl;

    this->f_ident(ident);
	std::cout << "Fanin Ids: ";
	std::cout << std::endl;

	for (auto f : fin_ids)
	{
		std::cout << f << " ";
	}

	std::cout << std::endl;

    this->f_ident(ident);
	std::cout << "Fanout Ids: ";
	std::cout << std::endl;

	for (auto f : fout_ids)
	{
		std::cout << f << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

    this->f_ident(ident);
	std::cout << "Join Tree:";
	std::cout << std::endl;
	std::cout << std::endl;

	jc_tree.Print(ident + 2);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Fork Tree:";
	std::cout << std::endl;
	std::cout << std::endl;

	fc_tree.Print(ident + 2);
}

///////////////////////////////////////////////////////////
// metodo: Query_Fork_Tree                               //
// proposito: obtiene el arbol de fork controllers.      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  arbol de fork controllers ( por referencia ).        //
///////////////////////////////////////////////////////////

BTree* Meta_Node::Query_Fork_Tree()
{
	return &fc_tree;
}

///////////////////////////////////////////////////////////
// metodo: Query_Join_Tree                               //
// proposito: obtiene el arbol de join controllers.      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  arbol de join controllers ( por referencia ).        //
///////////////////////////////////////////////////////////

BTree* Meta_Node::Query_Join_Tree()
{
	return &jc_tree;
}

///////////////////////////////////////////////////////////
// metodo: Query_LC                                      //
// proposito: obtiene latch controller.                  //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  latch controller.                                    //
///////////////////////////////////////////////////////////

int Meta_Node::Query_LC()
{
	return lc;
}

///////////////////////////////////////////////////////////
// metodo: Set_Fin_Id                                    //
// proposito: carga los identificadores de latches de    //
//            fan-in.                                    //
// argumentos:                                           //
//  fin - identificadores de los latches de fan-in.      //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Set_Fin_Id(std::vector<int> fin)
{
	fin_ids = fin;
}

///////////////////////////////////////////////////////////
// metodo: Set_Fout_Id                                   //
// proposito: carga los identificadores de latches de    //
//            fan-out.                                   //
// argumentos:                                           //
//  fout - identificadores de los latches de fan-out.    //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Set_Fout_Id(std::vector<int> fout)
{
	fout_ids = fout;
}

///////////////////////////////////////////////////////////
// metodo: Set_Id                                        //
// proposito: carga el identificador del latch.          //
// argumentos:                                           //
//  i - identificador del latch.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Set_Id(int i)
{
	id = i;
}

///////////////////////////////////////////////////////////
// metodo: Set_LC                                        //
// proposito: carga el numero de nodo del latch          //
//            controller.                                //
// argumentos:                                           //
//  l - numero de nodo del latch controller.             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Meta_Node::Set_LC(int l)
{
	lc = l;
}

/**********************************************************
 * metodo: f_ident                                        *
 * proposito: imprime espacios de identacion.             *
 * parametros:                                            *
 *  ident - nivel de identacion.                          *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Meta_Node::f_ident(int ident)
{
    for (int _i = 0; _i < ident; ++_i)
    {
        std::cout << " ";
    }
}
