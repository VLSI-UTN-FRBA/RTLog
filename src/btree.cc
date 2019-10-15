///////////////////////////////////////////////////////////
// codigo fuente: btree.cc                               //
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
//  Get_Node - devuelve el atributo del nodo.            //
//  Get_Right - devuelve rama derecha.                   //
//              ( por referencia )                       //
//  Insert_Node - inserta un nodo en el arbol.           //
//  Print - muestra el arbol.                            //
//  Set_Cell - asigna el numero del celda en el grafo.   //
//  f_ident - imprime espacios de identacion.            //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#include "btree.h"

#include <iostream>

///////////////////////////////////////////////////////////
// metodo: BTree                                         //
// proposito: constructor de BTree.                      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

BTree::BTree()
{
	// nodo libre
	node = -1;
	left = nullptr;
	right = nullptr;
}

///////////////////////////////////////////////////////////
// metodo: BTree                                         //
// proposito: constructor de BTree.                      //
//            Recibe un identificador.                   //
// argumentos:                                           //
//  id - identificador.                                  //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

BTree::BTree(int id)
{
	// nodo libre
	node = id;
	left = nullptr;
	right = nullptr;
}

///////////////////////////////////////////////////////////
// metodo: ~BTree                                        //
// proposito: destructor de BTree.                       //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

BTree::~BTree()
{
	if (left)
	{
		delete left;
	}

	if (right)
	{
		delete right;
	}
}

///////////////////////////////////////////////////////////
// metodo: Count                                         //
// proposito: cuenta los elementos del arbol.            //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  cantidad de elementos del arbol.                     //
///////////////////////////////////////////////////////////

int BTree::Count(BTree *b)
{
	int c;

	c = 0;

	if (b == nullptr)
	{
		return 0;
	}

	if (b->node > -1)
	{
		c++;
	}

	if (b->left)
	{
		c += Count(b->left);
	}

	if (b->right)
	{
		c += Count(b->right);
	}

	return c;
}

///////////////////////////////////////////////////////////
// metodo: Find_C                                        //
// proposito: busca un controller.                       //
// argumentos:                                           //
//  c - numero de celda del controlador                  //
//      ( por referencia ).                              //
//  id - identificador del latch.                        //
//  branch - rama del controller al cual esta conectado  //
//           el latch ( por referencia ).                //
// devuelve:                                             //
//  numero de celda del controlador.                     //
///////////////////////////////////////////////////////////

bool BTree::Find_C(int &c, int id, int &branch)
{
	// encontro el controller
	// puede ser el latch controller
	// si esta rama es la raiz del arbol
	if (node == id)
	{
		c = -1;
		branch = BRANCH_CENTER;

		return true;
	}

	// busca en rama izquierda
	if (left)
	{
		if (left->Find_C(c, id, branch))
		{
			// estamos arriba del id
			// somos el controller
			if (branch == BRANCH_CENTER)
			{
				c = cell;
				branch = BRANCH_LEFT;

				return true;
			}
			// fue encontrado en un
			// nivel mas profundo
			// no hay modificaciones
			else
			{
				return true;
			}
		}
	}

	// busca en la rama derecha
	if (right)
	{
		if (right->Find_C(c, id, branch))
		{
			// estamos arriba del id
			// somos el controller
			if (branch == BRANCH_CENTER)
			{
				c = cell;
				branch = BRANCH_RIGHT;

				return true;
			}
			// fue encontrado en un
			// nivel mas profundo
			// no hay modificaciones
			else
			{
				return true;
			}
		}
	}

	return false;
}

///////////////////////////////////////////////////////////
// metodo: Get_Cell                                      //
// proposito: devuelve el numero de celda del            //
//            controlador.                               //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de celda del controlador.                     //
///////////////////////////////////////////////////////////

int BTree::Get_Cell()
{
	return cell;
}

///////////////////////////////////////////////////////////
// metodo: Get_Left                                      //
// proposito: devuelve rama izquierda.                   //
//            ( por referencia )                         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  rama izquierda ( por referencia ).                   //
///////////////////////////////////////////////////////////

BTree* BTree::Get_Left()
{
	return left;
}

///////////////////////////////////////////////////////////
// metodo: Get_Node                                      //
// proposito: devuelve el atributo del nodo.             //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  atributo del nodo.                                   //
///////////////////////////////////////////////////////////

int BTree::Get_Node()
{
	return node;
}

///////////////////////////////////////////////////////////
// metodo: Get_Right                                     //
// proposito: devuelve rama derecha.                     //
//            ( por referencia )                         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  rama derecha ( por referencia ).                     //
///////////////////////////////////////////////////////////

BTree* BTree::Get_Right()
{
	return right;
}

///////////////////////////////////////////////////////////
// metodo: Insert_Node                                   //
// proposito: inserta un nodo en el arbol.               //
// argumentos:                                           //
//  n - nodo.                                            //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void BTree::Insert_Node(BTree n)
{
	int el, er;

	// nodo libre
	// copia aqui
	if (node == -1)
	{
/*		std::cout << "Insert node " << n.node;
		std::cout << std::endl;*/

		node = n.node;

/*		std::cout << "Node: " << node;
		std::cout << std::endl;*/

		return;
	}
	// ramificacion
	// decide en que rama poner el nodo
	else if (node == -2) 
	{
		el = Count(left);
		er = Count(right);

		if (el > er)
		{
/*			std::cout << "Go right " << n.node;
			std::cout << std::endl;*/

			right->Insert_Node(n);
		}
		else
		{
/*			std::cout << "Go left " << n.node;
			std::cout << std::endl;*/

			left->Insert_Node(n);
		}

		return;
	}

	el = Count(left);
	er = Count(right);

	if (el == 0 && er == 0)
	{
/*		std::cout << "Open branch " << n.node;
		std::cout << std::endl;		*/

		BTree* branch = new BTree(node);
		left = branch;

		node = -2;

		branch = new BTree(n.node);
		right = branch;

		return;
	}
}

///////////////////////////////////////////////////////////
// metodo: Print                                         //
// proposito: muestra el arbol.                          //
// argumentos:                                           //
//  ident - nivel de identacion.                         //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void BTree::Print(int ident)
{
	if (node == -1)
	{
		return;
	}

	if (node != -2)
	{
		std::cout << " id: " << node;
		std::cout << std::endl;

		return;
	}

	std::cout << " cell: " << cell;
	std::cout << std::endl;

	if (left)
	{
		std::cout << "l";

		left->Print(ident + 2);
	}

	if (right)
	{
		std::cout << "r";

		right->Print(ident + 2);
	}
}

///////////////////////////////////////////////////////////
// metodo: Set_Cell                                      //
// proposito: asigna el numero del celda en el grafo.    //
// argumentos:                                           //
//  n - numero de celda en el grafo.                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void BTree::Set_Cell(int n)
{
	cell = n;
}

/**********************************************************
 * metodo: f_ident                                        *
 * proposito: imprime espacios de identacion.             *
 * parametros:                                            *
 *  ident - nivel de identacion.                          *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void BTree::f_ident(int ident)
{
    for (int _i = 0; _i < ident; ++_i)
    {
        std::cout << " ";
    }
}
