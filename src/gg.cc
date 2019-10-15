///////////////////////////////////////////////////////////
// codigo fuente: gg.cc                                  //
// fecha de inicio: 17/11/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase Graph Generator para representar     //
//            grafos.                                    //
//                                                       //
// clase implementada:                                   //
//  Gg                                                   //
// propiedades:                                          //
//  cell_index - indice para la busqueda de registros.   //
//  cells - lista de nodos en el grafo.                  //
//  jname - nombre del archivo json.                     //
//  nets - lista de segmentos en el grafo.               //
// metodos:                                              //
//  Anottate - anota celda.                              //
//  Clone_Cell - clona una celda.                        //
//  connect - completa el fanin de un nodo.              //
//            ( 5 sobrecargas ).                         //
//  drive - agrega fanouts a un nodo.                    //
//  driveBus - agrega fanouts vectorial a un nodo.       //
//             ( 2 sobrecargas ).                        //
//  Get_Capture_Latch_From_Id - devuelve el bus de       //
//      capture correspondiente a un identificador.      //
//  Get_Capture_Reg - devuelve el registro de capture de //
//                    un camino r2r.                     //
//  getCells - devuelve lista de nodos.                  //
//  get_cell_type - devuelve un string con el tipo de    //
//                  celda.                               //
//  Get_Cloud_Logic - identifica las nubes               //
//                    combinacionales.                   //
//  getFullName - obtiene el nombre completo del         //
//                archivo.                               //
//  getMainName - obtiene el nombre principal del        //
//                archivo.                               //
//  getPath - obtiene la ruta del archivo.               //
//  Get_Input - devuelve un puerto de entrada de la      //
//              lista.                                   //
//  Get_Input_Logic - identifica las nubes               //
//                    combinacionales de entrada.        //
//  Get_Latch_Fanin_Inputs - devuelve los                //
//      identificadores de los latches del grafo.        //
//  Get_Lacthes_From_Id - devuelve los latche que tiene  //
//      un determinado identificador.                    //
//  Get_Latch_Ids - devuelve los identificadores de los  //
//                  latches del grafo.                   //
//  Get_Launching_Latch_From_Id - devuelve el bus de     //
//      launching correspondiente a un identificador.    //
//  Get_Launching_Latch_Ids - devuelve los               //
//      identificadores de los registros de launching.   //
//  Get_Launching_Reg - devuelve el registro de          //
//      launching de un camino r2o.                      //
//  get_n_cells - devuelve la cantidad de celdas.        //
//  get_n_i2r - devuelve la cantidad de caminos I2R.     //
//  get_n_inputs - devuelve la cantidad de entradas.     //
//  get_n_nets - devuelve la cantidad de nets.           //
//  get_n_outputs - devuelve la cantidad de salidas.     //
//  get_n_r2o - devuelve la cantidad de caminos R2O.     //
//  get_n_r2r - devuelve la cantidad de caminos R2R.     //
//  get_n_regs - devuelve la cantidad de registros.      //
//  getNets - devuelve lista de nets.                    //
//  get2OPaths - devuelve caminos hasta una salida.      //
//  get2RPaths - devuelve caminos hasta un registro.     //
//  Get_I2R_Paths - devuelve lista de los caminos i2r.   //
//  Get_Output - devuelve un puerto de salida de la      //
//               lista.                                  //
//  Get_Output_Logic - identifica las nubes              //
//                     combinacionales de salida.        //
//  Get_R2O_Paths - devuelve lista de los caminos r2o.   //
//  getR2RPaths - devuelve lista de los caminos r2r.     //
//  getReg - devuelve un registro de la lista.           //
//  Get_Reg_Ids - devuelve los identificadores de los    //
//                registros de capture.                  //
//  get_string_type - devuelve un string con el tipo de  //
//      celda.                                           //
//  initR2RSearch - inicia la busqueda de registros.     //
//  insertAdder - agrega un sumador.                     //
//  insertAdderCout - agrega un sumador con carry out.   //
//  insertAnd2 -  agrega una compuerta and2 al grafo.    //
//                ( 2 sobrecargas ).                     //
//  insertBuf - agrega una compuerta Buf al grafo.       //
//              ( 2 sobrecargas ).                       //
//  insertCpEq -  agrega un comparador por igualdad.     //
//  insertCpGr - agrega un comparador por mayor.         //
//  insertCpGEq - agrega un comparador por mayor o       //
//                igual.                                 //
//  insertCpLw - agrega un comparador por menor.         //
//  insertCpLEq  - agrega un comparador por menor o      //
//                 igual.                                //
//  insertCpNeq - agrega un comparador por desigualdad.  //
//  Insert_FC - agrega un fork controller.               //
//  Insert_Handshake - establece handshake entre 2 latch //
//                     controllers.                      //
//  Insert_JC - agrega un join controller.               //
//  Insert_LC - agrega un latch controller.              //
//  insertMult - agrega un multiplicador.                //
//  insertMux2 - agrega un mux2 al grafo.                //
//               ( 2 sobrecargas ).                      //
//  insertMuxN - agrega un muxN al grafo.                //
//  insertNeg - agrega un cambio de signo.               //
//  insertNet - agrega un segmento al grafo.             //
//              ( 2 sobrecargas ).                       //
//  insertNot - agrega una compuerta Not al grafo.       //
//              ( 2 sobrecargas ).                       //
//  insertOr2 - agrega una compuerta or2 al grafo.       //
//              ( 2 sobrecargas ).                       //
//  insertPortIn - agrega un puerto de entrada al grafo. //
//  insertPortOut - agrega un puerto de salida al grafo. //
//  insertReg - agrega un elemento de memoria al grafo.  //
//  insertSub -  agrega un restador.                     //
//  insertSubBout agrega un restador con borrow out.     //
//  insertTieHi -  agrega un tie hi al grafo.            //
//  insertTieLo -  agrega un tie lo al grafo.            //
//  insertXor2 - agrega una compuerta xor2 al grafo.     //
//               ( 2 sobrecargas ).                      //
//  insertXnor2 - agrega una compuerta xor2 al grafo.    //
//                ( 2 sobrecargas ).                     //
//  is_Output_Bus - determina si la salida de la celda   //
//                  es un bus.                           //
//  print - muestra el grafo.                            //
//  queryBusFanout - consulta los fanout buses de un     //
//                   nodo.                               //
//  Query_Ids - devuelve los identificadores de un bus.  //
//  query_Launching_Latch - consulta los fanin de        //
//                          latches.                     //
//  queryDriver - consulta la cola de un net.            //
//  queryFanin - consulta el net de fanin de un nodo.    //
//  queryFanout - consulta los fanouts de un nodo.       //
//  queryLatches - consulta los latches.                 //
//  queryLoad - consulta la cabeza de un net.            //
//  Reg2Latch - reemplaza registros por latches.         //
//  f_remove_r2r_paths_duplicates - elimina caminos r2r  //
//      duplicados.                                      //
//  Serialize - guarda el grafo en un archivo json.      //
//  source - agenda el nombre del archivo fuente.        //
//  wire - conecta 2 nodos.                              //
// operadores:                                           //
//  = - operador de asignacion.                          //
//                                                       //
///////////////////////////////////////////////////////////

#include <algorithm>

#include "gg.h"
#include "tag.h"

/**********************************************************
 * metodo: Annotate                                       *
 * proposito: anota celda.                                *
 * argumentos:                                            *
 *  node - numero de nodo en la lista.                    *
 *  d - anotacion del nombre de bus.                      *
 *  x - anotacion del indice de bus.                      *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Gg::Annotate(int node, int d, int x)
{
	(cells[node])->Annotate(d, x);
}

///////////////////////////////////////////////////////////
// metodo: Clone_Cell                                    //
// proposito: clona una celda.                           //
// argumentos:                                           //
//  *c - puntero a la celda.                             // 
// devuelve:                                             //
//  puntero al clon.                                     //
///////////////////////////////////////////////////////////

Node* Gg::Clone_Cell(Node* c)
{
	Node *p;

	switch (c->getTypeID())
	{
		case NODE_ID_PORTIN:
			p = new PortIn(c);
			break;
		case NODE_ID_PORTOUT:
			p = new PortOut(c);
			break;
		case NODE_ID_TIEHI:
			p = new TieHi(c);
			break;
		case NODE_ID_TIELO:
			p =	new TieLo(c);
			break;
		case NODE_ID_NOT:
			p = new Not(c);
			break;
		case NODE_ID_BUF:
			p = new Buf(c);
			break;
		case NODE_ID_ADD:
			p = new Adder(c);
			break;
		case NODE_ID_ADDCOUT:
			p = new AdderCout(c);
			break;
		case NODE_ID_MULT:
			p = new Mult(c);
			break;
		case NODE_ID_MUX2:
			p = new Mux2(c);
			break;
		case NODE_ID_MUXN:
			p = new MuxN(c);
			break;
		case NODE_ID_NEG:
			p = new Neg(c);
			break;
		case NODE_ID_SUB:
			p = new Sub(c);
			break;
		case NODE_ID_SUBBOUT:
			p = new SubBout(c);
			break;
		case NODE_ID_AND2:
			p = new And2(c);
			break;
		case NODE_ID_OR2:
			p = new Or2(c);
			break;
		case NODE_ID_REG:
			p = new Reg(c);
			break;
		case NODE_ID_XOR2:
			p = new Xor2(c);
			break;
		case NODE_ID_XNOR2:
			p = new Xnor2(c);
			break;
		case NODE_ID_CPEQ:
			p = new CpEq(c);
			break;
		case NODE_ID_CPGR:
			p = new CpGr(c);
			break;
		case NODE_ID_CPGEQ:
			p = new CpGEq(c);
			break;
		case NODE_ID_CPLW:
			p = new CpLw(c);
			break;
		case NODE_ID_CPLEQ:
			p = new CpLEq(c);
			break;
		case NODE_ID_CPNEQ:
			p = new CpNeq(c);
			break;
	}

	return p;
}

///////////////////////////////////////////////////////////
// metodo: connect                                       //
// proposito: completa el fanin de un nodo.              //
// argumentos:                                           //
//  node - numero de nodo en la lista.                   //
//  net - numero de net en la lista.                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::connect(int node, int net)
{
	(cells[node])->insertFanin(net);
	(nets[net])->connect(node);
}

///////////////////////////////////////////////////////////
// metodo: connect                                       //
// proposito: completa el fanin ( bus ) de un nodo.      //
//            El fanin es una lista de ints.             //
//            Ej. Entrada de un comparador.              //
// argumentos:                                           //
//  node - numero de nodo en la lista.                   //
//  bus - lista con nets ( bus ).                        //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::connect(int node, vector<int> bus)
{
	(cells[node])->insertFanin(bus);

	for (auto &net : bus)
	{
		(nets[net])->connect(node);
	}
}

///////////////////////////////////////////////////////////
// metodo: connect                                       //
// proposito: completa el fanin ( bus ) de un nodo.      //
//            El fanin es un vector de ints.             //
//            Ej. Bus port de salida.                    //
// argumentos:                                           //
//  node - numero de nodo en la lista.                   //
//  bus - lista con nets ( bus ).                        //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::connect(int* node, vector<int> bus)
{
	int i = 0;

	for (auto &net : bus)
	{
		(cells[node[i]])->insertFanin(net);
		(nets[net])->connect(node[i]);
		i++;
	}
}

///////////////////////////////////////////////////////////
// metodo: connect                                       //
// proposito: completa el fanin de un nodo.              //
//            El fanin viene indizado.                   //
//            Ej. Entrada de datos de un muxN.           //
// argumentos:                                           //
//  node - numero de nodo en la lista.                   //
//  net - numero de net en la lista.                     //
//  i - indice que referencia la entrada.                //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::connect(int node, int net, int i)
{
	(cells[node])->insertFanin(net, i);
	(nets[net])->connect(node);
}

///////////////////////////////////////////////////////////
// metodo: connect                                       //
// proposito: completa el fanin ( bus ) de un nodo       // 
//            ( bus ).                                   //
// argumentos:                                           //
//  node - vector de nodos.                              //
//  bus - lista con nets ( bus ).                        //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::connect(vector<int> nodes, vector<int> nets)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		connect(nodes[i], nets[i]);
	}
}

///////////////////////////////////////////////////////////
// metodo: drive                                         //
// proposito: agrega fanouts a un nodo.                  //
// argumentos:                                           //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  numero de net en la lista.                           //
///////////////////////////////////////////////////////////

int Gg::drive(int n)
{
	return insertNet(n);
}

///////////////////////////////////////////////////////////
// metodo: drive                                         //
// proposito: agrega fanouts a un nodo.                  //
//            Indica que salida utilizar.                //
// argumentos:                                           //
//  n - numero de nodo.                                  //
//  f - salida a utilizar.                               //
// devuelve:                                             //
//  numero de net en la lista.                           //
///////////////////////////////////////////////////////////

int Gg::drive(int n, int f)
{
	int w;

	Net* net = new Net(n);

	// agrega net a la lista
	nets.push_back(net);

	w = nets.size() - 1;

	// suma fanout al source device
	(cells[n])->insertFanout(w, f);

	return w;
}

///////////////////////////////////////////////////////////
// metodo: driveBus                                      //
// proposito: agrega fanouts vectorial a un nodo.        //
// argumentos:                                           //
//  n - numero de nodo.                                  //
// devuelve:                                             //
//  lista de nets que forman el bus.                     //
///////////////////////////////////////////////////////////

vector<int> Gg::driveBus(int n)
{
	int i;
	int w;
	int w1;
	vector<int> bus;

	w = (cells[n])->getWidth();

	for (i = 0; i < w; i++)
	{
		w1 = insertNet(n);
		bus.push_back(w1);
	}

	(cells[n])->insertFanout(bus);

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: driveBus                                      //
// proposito: agrega fanouts a un bus.                   //
// argumentos:                                           //
//  nodes - vector de nodos.                             //
// devuelve:                                             //
//  lista de nets que forman el bus.                     //
///////////////////////////////////////////////////////////

vector<int> Gg::driveBus(vector<int> nodes)
{
	int i;
	int w;
	int w1;
	vector<int> bus;

	for (i = 0; i < nodes.size(); i++)
	{
		w = drive(nodes[i]);
		bus.push_back(w);
	}

	return bus;
}

/*********************************************************
 * metodo: get_id_annotation                             *
 * proposito: devuelve el id anotado para determinada    *
 *            celda.                                     *
 * parametros:                                           *
 *  cell - numero de celda.                              *
 * devuelve:                                             *
 *  id.                                                  *
 *********************************************************/

int Gg::get_id_annotation(int cell)
{
    this->cells[cell]->Get_Id_Annotation();
}

/*********************************************************
 * metodo: get_ix_annotation                             *
 * proposito: devuelve el ix anotado para determinada    *
 *            celda.                                     *
 * parametros:                                           *
 *  cell - numero de celda.                              *
 * devuelve:                                             *
 *  ix.                                                  *
 *********************************************************/

int Gg::get_ix_annotation(int cell)
{
    this->cells[cell]->Get_Ix_Annotation();
}

///////////////////////////////////////////////////////////
// metodo: Get_Capture_Latch_From_Id                     //
// proposito: devuelve el bus de capture correspondiente //
//            a un identificador.                        //
// argumentos:                                           //
//  id - identificador.                                  //
// devuelve:                                             //
//  bus de capture.                                      //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Capture_Latch_From_Id(int id)
{
	int i = 0;
	std::vector<int> bus;

	// recorre todas las celdas
	for (auto c : cells)
	{
		// busca latches
		if (c->getTypeID() == NODE_ID_LATCH)
		{
			// es parte del bus de captura
			if (c->Get_Id_Annotation() == id)
			{
				bus.push_back(i);	
			}
		}

		i++;
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: Get_Capture_Reg                               //
// proposito: devuelve el registro de capture de un      //
//            camino r2r.                                //
// argumentos:                                           //
//  p - camino registro a registro.                      //
// devuelve:                                             //
//  registro de capture de un camino r2r.                //
///////////////////////////////////////////////////////////

int Gg::Get_Capture_Reg(vector<int> p)
{
	return p[p.size() - 1];
}

///////////////////////////////////////////////////////////
// metodo: getCells                                      //
// proposito: devuelve lista de nodos.                   //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de nodos ( por referencia ).                   //
///////////////////////////////////////////////////////////

vector<Node*>* Gg::getCells(void)
{
	return &cells;
}

/*********************************************************
 * metodo: get_cell_type                                 *
 * proposito: devuelve un string con el tipo de celda.   *
 * parametros:                                           *
 *  c - celda consultada.                                *
 * devuelve:                                             *
 *  string con el tipo de celda.                         *
 *********************************************************/

std::string Gg::get_cell_type(uint32_t c)
{
	return "holis";
}

///////////////////////////////////////////////////////////
// metodo: Get_Cloud_Logic                               //
// proposito: identifica las nubes combinacionales.      //
// argumentos:                                           //
//  r2r_paths - caminos registro a registro.             //
// devuelve:                                             //
//  cloud logic.                                         //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::Get_Cloud_Logic(
					vector<vector<int>> r2r_paths)
{
	int r;
	std::vector<int> ids;
	std::vector<int> cloud;
	std::vector<int>::iterator it;
	std::vector<std::vector<int>> clouds;

	/* busca todos los ids que corresponde a registros de capture */
	ids = Get_Reg_Ids(r2r_paths);


	/* hace una lista de paths r2r para cada id de capture */
	for (auto i : ids)
	{
		cloud.clear();

		cloud.push_back(i);

		for (auto p : r2r_paths)
		{
			r = Get_Capture_Reg(p);

			if (cells[r]->Get_Id_Annotation() == i)
			{
				// pone launching register
				// si no esta en la cloud logic
				it = find_if(cloud.begin(), cloud.end(), 
							[=](int &obj) {return obj == cells[p[0]]->Get_Id_Annotation();});

				// no esta en la tabla de simbolos
				if (it == cloud.end())
				{
					cloud.push_back(cells[p[0]]->Get_Id_Annotation());
				}
			}
		}

		clouds.push_back(cloud);
	}

	return clouds;
}

///////////////////////////////////////////////////////////
// metodo: getFullName                                   //
// proposito: obtiene el nombre completo del archivo.    //
// argumentos:                                           //
//  name - nombre del archivo con su ruta.               //
// devuelve:                                             //
//  nombre del archivo.                                  //
///////////////////////////////////////////////////////////

std::string Gg::getFullName(std::string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != std::string::npos) 
	{
		return (name.substr(i + 1, name.length() - i));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getMainName                                   //
// proposito: obtiene el nombre principal del archivo.   //
// argumentos:                                           //
//  name - nombre del archivo con extension.             //
// devuelve:                                             //
//  nombre del archivo.                                  //
///////////////////////////////////////////////////////////

std::string Gg::getMainName(std::string name)
{
	size_t i = name.rfind('.', name.length());

	if (i != std::string::npos) 
	{
		return (name.substr(0, i));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getPath                                       //
// proposito: obtiene la ruta del archivo.               //
// argumentos:                                           //
//  name - nombre del archivo.                           //
// devuelve:                                             //
//  ruta del archivo.                                    //
///////////////////////////////////////////////////////////

std::string Gg::getPath(std::string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != std::string::npos) 
	{
		return (name.substr(0, i + 1));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: Get_Input_Logic                               //
// proposito: identifica las nubes combinacionales de    //
//            entrada.                                   //
// argumentos:                                           //
//  i2r_paths - caminos entrada a registro.              //
// devuelve:                                             //
//  input logic.                                         //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::Get_Input_Logic(
					std::vector<std::vector<int>> i2r_paths)
{
	int r;
	std::vector<int> ids;
	std::vector<int> input;
	std::vector<int>::iterator it;
	std::vector<std::vector<int>> inputs;

	ids = Get_Reg_Ids(i2r_paths);

/*    std::cout << "Searching Latches..." << std::endl; */

	// busca todos los ids
/*	for (auto i : ids)
	{
		std::cout << "id: " << i << std::endl;
	}

	std::cout << std::endl;*/

/*    std::cout << "Searching input-to-latch paths..." << std::endl; */

	// hace una lista de paths i2r para cada id
	for (auto i : ids)
	{
/*		std::cout << "id: " << i << std::endl << std::endl; */

		input.clear();

		input.push_back(i);

		for (auto p : i2r_paths)
		{
			r = Get_Capture_Reg(p);

			if (cells[r]->Get_Id_Annotation() == i)
			{
				// muestra camino i2r
/*				for (auto c : p)
				{
					std::cout << c << " ";
				}*/

				// pone input port
				// si no esta en la input logic
				it = find_if(input.begin(), input.end(), 
							[=](int &obj) {return obj == cells[p[0]]->Get_Id_Annotation();});

				// no esta en la tabla de simbolos
				if (it == input.end())
				{
					input.push_back(cells[p[0]]->Get_Id_Annotation());
				}

/*				std::cout << std::endl; */

			}
		}

		inputs.push_back(input);
	}

/*	std::cout << std::endl;
	std::cout << std::endl;

	for (auto c : inputs)
	{
		std::cout << "id: " << c[0] << std::endl;

		if (c.size() > 1)
		{
			for (int i = 1; i < c.size(); i++)
			{
				std::cout << c[i] << " ";
			}
		}

		std:cout << std::endl;
	}*/

	return inputs;
}

///////////////////////////////////////////////////////////
// metodo: Get_Launching_Reg                             //
// proposito: devuelve el registro de launching de un    //
//            camino r2o.                                //
// argumentos:                                           //
//  p - camino registro a registro.                      //
// devuelve:                                             //
//  registro de capture de un camino r2o.                //
///////////////////////////////////////////////////////////

int Gg::Get_Launching_Reg(std::vector<int> p)
{
	return p[0];
}

///////////////////////////////////////////////////////////
// metodo: getNets                                       //
// proposito: devuelve lista de nets.                    //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de nets ( por referencia ).                    //
///////////////////////////////////////////////////////////

vector<Net*>* Gg::getNets(void)
{
	return &nets;
}

///////////////////////////////////////////////////////////
// metodo: get2OPaths                                    //
// proposito: devuelve caminos hasta una salida.         //
// argumentos:                                           //
//  f - nodo de inicio.                                  //
// devuelve:                                             //
//  vector de caminos.                                   //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::get2OPaths(int f)
{
	int c;
	std::vector<int> fout;
	std::vector<std::vector<int>> busout;
	std::vector<std::vector<int>> paths;

	// es un latch ( lo descarta como path )
//	if (cells[f]->getTypeID() == NODE_ID_LATCH)
//	{
	if (cells[f]->getTypeID() == NODE_ID_REG ||
        cells[f]->getTypeID() == NODE_ID_LATCH)
	{
//		std::cout << "Reg. Stop" << std::endl;

		return paths;
	}

	// es una salida, completa el camino 2o
	if (cells[f]->getTypeID() == NODE_ID_PORTOUT)
	{
		std::vector<int> path;

		path.push_back(f);
		paths.push_back(path);

		return paths;
	}

	// el nodo tiene un bus de salida
	if (is_Output_Bus(f))
	{
		busout = queryBusFanout(f);

        if (busout.size() == 0)
        {
            std::cout << "fanout bus nulo " << std::endl;

            return paths;
        }

		// recorre todos los fanouts
		for (auto b : busout)
		{
			// explora los fanouts del bus
			for (auto n : b)
			{
				std::vector<std::vector<int>> tails;

				// net abierto
				if (n == -1)
				{
					continue;
				}

				// proximo nodo
				c = queryLoad(n);

				// computa el camino desde un fanout
				tails = get2OPaths(c);

                if (tails.size() == 0)
                {
                    return paths;
                }

				// arma los caminos desde el registro
				// considerado
				for (auto s : tails)
				{
					std::vector<int> path;

					// el camino comienza por f
					path.push_back(f);

					path.insert(path.end(), s.begin(), s.end());

					paths.push_back(path);
				}
			}
		}

		return paths;
	}
	// el nodo tiene un wire de salida
	else
	{
		fout = queryFanout(f);

        if (fout.size() == 0)
        {
            std::cout << "fanout nulo " << std::endl;


            return paths;
        }

		// no es un registro
		// explora los fanouts del nodo
		for (auto n : fout)
		{
			std::vector<std::vector<int>> tails;

			// net abierto
			if (n == -1)
			{
				continue;
			}

			// proximo nodo
			c = queryLoad(n);

			// computa el camino desde un fanout
			tails = get2OPaths(c);

            if (tails.size() == 0)
            {
                return paths;
            }

			// arma los caminos desde el registro
			// considerado
			for (auto s : tails)
			{
				std::vector<int> path;

				// el camino comienza por f
				path.push_back(f);

				path.insert(path.end(), s.begin(), s.end());

				paths.push_back(path);
			}
		}
	}

	return paths;
}

///////////////////////////////////////////////////////////
// metodo: get2RPaths                                    //
// proposito: devuelve caminos hasta un registro.        //
// argumentos:                                           //
//  f - nodo de inicio.                                  //
// devuelve:                                             //
//  vector de caminos.                                   //
///////////////////////////////////////////////////////////

vector<vector<int>> Gg::get2RPaths(int f)
{
	int c;
	vector<int> fout;
	vector<vector<int>> busout;
	vector<vector<int>> paths;

	// es puerto de salida ( lo descarta como path )
	if (cells[f]->getTypeID() == NODE_ID_PORTOUT)
	{
		return paths;
	}

	// es un registro, completa el camino 2r
	if (cells[f]->getTypeID() == NODE_ID_REG ||
        cells[f]->getTypeID() == NODE_ID_LATCH)
	{
		vector<int> path;

		path.push_back(f);
		paths.push_back(path);

		return paths;
	}

	// el nodo tiene un bus de salida
	if (is_Output_Bus(f))
	{
		busout = queryBusFanout(f);

        if (busout.size() == 0)
        {
            return paths;
        }

    	// recorre todos los fanouts
		for (auto b : busout)
		{
			// explora los fanouts del bus
			for (auto n : b)
			{
				vector<vector<int>> tails;

				// net abierto
				if (n == -1)
				{
					continue;
				}

				// proximo nodo
				c = queryLoad(n);

				// computa el camino desde un fanout
				tails = get2RPaths(c);

                if (tails.size() == 0)
                {
                    continue;

//                    return paths;
                }

				// arma los caminos desde el registro
				// considerado
				for (auto s : tails)
				{
					vector<int> path;

					// el camino comienza por f
					path.push_back(f);

					path.insert(path.end(), s.begin(), s.end());

					paths.push_back(path);
				}
			}
		}

		return paths;
	}
	// el nodo tiene un wire de salida
	else
	{
		fout = queryFanout(f);

        if (fout.size() == 0)
        {
            return paths;
        }


		// no es un registro
		// explora los fanouts del nodo
		for (auto n : fout)
		{
			vector<vector<int>> tails;

			// net abierto
			if (n == -1)
			{
				continue;
			}

			// proximo nodo
			c = queryLoad(n);

			// computa el camino desde un fanout
			tails = get2RPaths(c);

            if (tails.size() == 0)
            {
                continue;
  //              return paths;
            }

			// arma los caminos desde el registro
			// considerado
			for (auto s : tails)
			{
				vector<int> path;

				// el camino comienza por f
				path.push_back(f);

				path.insert(path.end(), s.begin(), s.end());

				paths.push_back(path);
			}
		}
	}

	return paths;
}

///////////////////////////////////////////////////////////
// metodo: Get_I2R_Paths                                 //
// proposito: devuelve lista de los caminos i2r.         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de los caminos i2r.                            //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::Get_I2R_Paths()
{
	int i;
	int n;
	std::vector<std::vector<int>> i2r_paths;

/*	cout << "I2R Paths" << endl;
	cout << "--- -----" << endl << endl;*/

	cell_index = 0;

	// busca entradas en la lista de celdas
	while (Get_Input(i))
	{
		// explora los fanouts del registro
		for (auto f : queryFanout(i))
		{
			std::vector<std::vector<int>> tails;

			// net abierto
			if (f == -1)
			{
				continue;
			}

			// proximo nodo
			n = queryLoad(f);

			// computa el camino desde un fanout
			tails = get2RPaths(n);

            if (tails.size() == 0)
            {
                return i2r_paths;
            }

			// arma los caminos desde el registro
			// considerado
			for (auto s : tails)
			{
				std::vector<int> path;

				// el camino comienza por i
				path.push_back(i);

				path.insert(path.end(), s.begin(), s.end());

				// muestra camino r2r
				for (auto c : path)
				{
	//				std::cout << c << " ";
				}

				i2r_paths.push_back(path);

		//		std::cout << endl;
			}
		}
	}

	return i2r_paths;
}

///////////////////////////////////////////////////////////
// metodo: Get_Input                                     //
// proposito: devuelve un puerto de entrada de la lista. //
// argumentos:                                           //
//  i - numero de celda ( por referencia ).              //
// devuelve:                                             //
//  true - encontro un puerto de entrada.                //
//  false - no hay mas puertos de entrada en la lista.   //
///////////////////////////////////////////////////////////

bool Gg::Get_Input(int &i)
{
	// busqueda finalizada
	if (cell_index >= cells.size())
	{
		return false;
	}

	// recorre la lista de celdas
	while (cell_index < cells.size())
	{
		// es un puerto de entrada
		if (cells[cell_index]->getTypeID() == NODE_ID_PORTIN)
		{
			i = cell_index;
			cell_index++;
			return true;
		}

		cell_index++;
	}

	// busqueda finalizada
	return false;
}

///////////////////////////////////////////////////////////
// metodo: Get_Output                                    //
// proposito: devuelve un puerto de salida de la lista.  //
// argumentos:                                           //
//  o - numero de celda ( por referencia ).              //
// devuelve:                                             //
//  true - encontro un puerto de salida.                 //
//  false - no hay mas puertos de salida en la lista.    //
///////////////////////////////////////////////////////////

bool Gg::Get_Output(int &o)
{
	// busqueda finalizada
	if (cell_index >= cells.size())
	{
		return false;
	}

	// recorre la lista de celdas
	while (cell_index < cells.size())
	{
		// es un puerto de entrada
		if (cells[cell_index]->getTypeID() == NODE_ID_PORTOUT)
		{
			o = cell_index;
			cell_index++;
			return true;
		}

		cell_index++;
	}

	// busqueda finalizada
	return false;
}

///////////////////////////////////////////////////////////
// metodo: Get_Output_Logic                              //
// proposito: identifica las nubes combinacionales de    //
//            salida.                                    //
// argumentos:                                           //
//  r2o_paths - caminos registro a salida.               //
// devuelve:                                             //
//  output logic.                                        //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::Get_Output_Logic(
					std::vector<std::vector<int>> r2o_paths)
{
	int r;
	std::vector<int> ids;
	std::vector<int> output;
	std::vector<int>::iterator it;
	std::vector<std::vector<int>> outputs;

	ids = Get_Launching_Latch_Ids(r2o_paths);

	// busca todos los ids
/*	for (auto o : ids)
	{
		std::cout << "id: " << o << std::endl;
	}

	std::cout << std::endl;*/

	// hace una lista de paths r2o para cada id
	for (auto o : ids)
	{
/*		std::cout << "id: " << o << std::endl << std::endl; */

		output.clear();

		output.push_back(o);

		for (auto p : r2o_paths)
		{
			r = Get_Launching_Reg(p);

			if (cells[r]->Get_Id_Annotation() == o)
			{
				// muestra camino r2o
/*				for (auto c : p)
				{
					std::cout << c << " ";
				}*/

				// pone output port
				// si no esta en la output logic
				it = find_if(output.begin(), output.end(), 
							[=](int &obj) {return obj == cells[p[0]]->Get_Id_Annotation();});

				// no esta en la tabla de simbolos
				if (it == output.end())
				{
					output.push_back(cells[p[0]]->Get_Id_Annotation());
				}

/*				std::cout << std::endl; */

			}
		}

		outputs.push_back(output);
	}

/*	std::cout << std::endl;
	std::cout << std::endl;

	for (auto c : outputs)
	{
		std::cout << "id: " << c[0] << std::endl;

		if (c.size() > 1)
		{
			for (int i = 1; i < c.size(); i++)
			{
				std::cout << c[i] << " ";
			}
		}

		std:cout << std::endl;
	}*/

	return outputs;
}

///////////////////////////////////////////////////////////
// metodo: Get_R2O_Paths                                 //
// proposito: devuelve lista de los caminos r2o.         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de los caminos r2o.                            //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::Get_R2O_Paths()
{
	int r;
	int n;
	std::vector<std::vector<int>> r2o_paths;

/*	std::cout << "R2O Paths" << std::endl;
	std::cout << "--- -----" << std::endl << std::endl;*/

	cell_index = 0;

	// busca registros en la lista de celdas
	while (getReg(r))
	{
		// explora los fanouts del registro
		for (auto f : queryFanout(r))
		{
			std::vector<std::vector<int>> tails;

			// net abierto
			if (f == -1)
			{
				continue;
			}

			// proximo nodo
			n = queryLoad(f);

			// computa el camino desde un fanout
			tails = get2OPaths(n);

            if (tails.size() == 0)
            {
                return r2o_paths;
            }

			// arma los caminos desde el registro
			// considerado
			for (auto s : tails)
			{
				std::vector<int> path;

				// el camino comienza por r
				path.push_back(r);

				path.insert(path.end(), s.begin(), s.end());

				// muestra camino r2o
				for (auto c : path)
				{
	//				std::cout << c << " ";
				}

				r2o_paths.push_back(path);

		//		std::cout << std::endl;
			}
		}
	}

	return r2o_paths;
}

///////////////////////////////////////////////////////////
// metodo: getR2RPaths                                   //
// proposito: devuelve lista de los caminos r2r.         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de los caminos r2r.                            //
///////////////////////////////////////////////////////////

vector<vector<int>> Gg::getR2RPaths()
{
	int n;
	int r;
	std::vector<std::vector<int>> r2r_paths;

	initR2RSearch();

	// busca registros en la lista de celdas
	while (getReg(r))
	{
		// explora los fanouts del registro
		for (auto f : queryFanout(r))
		{
			vector<vector<int>> tails;

			// net abierto
			if (f == -1)
			{
				continue;
			}

			// proximo nodo
			n = queryLoad(f);

			// computa el camino desde un fanout
			tails = get2RPaths(n);

			// arma los caminos desde el registro
			// considerado
			for (auto s : tails)
			{
				vector<int> path;

				// el camino comienza por r
				path.push_back(r);

				path.insert(path.end(), s.begin(), s.end());

				// muestra camino r2r
/*				for (auto c : path)
				{
					cout << c << " ";
				}*/

				r2r_paths.push_back(path);

//				cout << endl;
			}
		}
	}

    /* el algoritmo produce caminos duplicados 
     * si existe fanout reconvergente
     */
    this->f_remove_r2r_paths_duplicates(r2r_paths);

	return r2r_paths;
}

///////////////////////////////////////////////////////////
// metodo: Get_Latch_Fanin_Inputs                        //
// proposito: devuelve los identificadores de los        //
//            latches del grafo.                         //
// argumentos:                                           //
//  id - identificador del latch.                        //
// devuelve:                                             //
//  identificadores de los registros del grafo.          //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Latch_Fanin_Inputs(int id)
{
	std::vector<int> inputs;
	std::vector<int> latches;

	latches = Get_Latch_From_Id(id);

	std::cout << "Latch : " << id << std::endl;	

	for (auto l : latches)
	{
		std::cout << "   " << l << std::endl;
	}

	return inputs;
}

///////////////////////////////////////////////////////////
// metodo: Get_Latch_From_Id                             //
// proposito: devuelve los latche que tiene un           //
//            determinado identificador.                 //
// argumentos:                                           //
//  id - identificador.                                  //
// devuelve:                                             //
//  lista de latches.                                    //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Latch_From_Id(int id)
{
	std::vector<int> latches;

	// recorre todas las celdas
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i]->getTypeID() == NODE_ID_LATCH)
		{
			if (cells[i]->Get_Id_Annotation() == id)
			{
				latches.push_back(i);
			}
		}
	}

	return latches;
}

///////////////////////////////////////////////////////////
// metodo: Get_Latch_Ids                                 //
// proposito: devuelve los identificadores de los        //
//            latches del grafo.                         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  identificadores de los registros del grafo.          //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Latch_Ids()
{
	int i;
	std::vector<int> ids;
	std::vector<int>::iterator it;

	// recorre todas las celdas
	for (auto c : cells)
	{
		if (c->getTypeID() == NODE_ID_LATCH)
		{
			i = c->Get_Id_Annotation();

			it = find_if(ids.begin(), ids.end(), 
						[=](int &var) {return var == i;});

			// no esta en la lista
			if (it == ids.end())
			{
				ids.push_back(i);
			}
		}
	}

	return ids;
}

///////////////////////////////////////////////////////////
// metodo: Get_Launching_Latch_From_Id                   //
// proposito: devuelve el bus de launching               //
//            correspondiente a un identificador.        //
// argumentos:                                           //
//  id - identificador.                                  //
// devuelve:                                             //
//  bus de capture.                                      //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Launching_Latch_From_Id(int id)
{
	int i = 0;
	std::vector<int> bus;

	// recorre todas las celdas
	for (auto c : cells)
	{
		// busca latches
		if (c->getTypeID() == NODE_ID_LATCH)
		{
			// es parte del bus de captura
			if (c->Get_Id_Annotation() == id)
			{
				bus.push_back(i);	
			}
		}

		i++;
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: Get_Launching_Latch_Ids                       //
// proposito: devuelve los identificadores de los        //
//            registros de launching.                    //
// argumentos:                                           //
//  r2r_paths - caminos registro a registro.             //
// devuelve:                                             //
//  identificadores de los registros de launching.       //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Get_Launching_Latch_Ids(
	std::vector<std::vector<int>> r2r_paths)
{
	int id;
	int r;
	std::vector<int> ids;

	// recorre todos los caminos r2r
	for (auto p : r2r_paths)
	{
		r = Get_Launching_Reg(p);

		id = cells[r]->Get_Id_Annotation();

		if (std::find(ids.begin(), ids.end(), id) == ids.end())
		{
			ids.push_back(id);
		}
	}

	return ids;
}

/**********************************************************
 * metodo: get_n_cells                                    *
 * proposito: devuelve la cantidad de celdas.             *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de celdas.                                   *
 *********************************************************/

int Gg::get_n_cells()
{
	return this->cells.size();
}

/**********************************************************
 * metodo: get_n_inputs                                   *
 * proposito: devuelve la cantidad de entradas.           *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de entradas.                                 *
 *********************************************************/

int Gg::get_n_inputs()
{
	int v_n = 0;

	for (auto v_cell : this->cells)
	{
		if (v_cell->getTypeID() == NODE_ID_PORTIN)
		{
			v_n++;
		}
	}

	return v_n;
}

/**********************************************************
 * metodo: get_n_nets                                     *
 * proposito: devuelve la cantidad de nets.               *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de nets.                                     *
 *********************************************************/

int Gg::get_n_nets()
{
	return this->nets.size();
}

/**********************************************************
 * metodo: get_n_i2r                                      *
 * proposito: devuelve la cantidad de caminos I2R.        *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de caminos I2R.                              *
 *********************************************************/

int Gg::get_n_i2r()
{
	std::vector<std::vector<int>> v_i2r_paths;

	v_i2r_paths = this->Get_I2R_Paths();

	return v_i2r_paths.size();
}

/**********************************************************
 * metodo: get_n_outputs                                  *
 * proposito: devuelve la cantidad de salidas.            *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de salidas.                                  *
 *********************************************************/

int Gg::get_n_outputs()
{
	int v_n = 0;

	for (auto v_cell : this->cells)
	{
		if (v_cell->getTypeID() == NODE_ID_PORTOUT)
		{
			v_n++;
		}
	}

	return v_n;
}

/**********************************************************
 * metodo: get_n_r2o                                      *
 * proposito: devuelve la cantidad de caminos R2O.        *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de caminos R2O.                              *
 *********************************************************/

int Gg::get_n_r2o()
{
	std::vector<std::vector<int>> v_r2o_paths;

	v_r2o_paths = this->Get_R2O_Paths();

	return v_r2o_paths.size();
}

/**********************************************************
 * metodo: get_n_r2r                                      *
 * proposito: devuelve la cantidad de caminos R2R.        *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de caminos R2R.                              *
 *********************************************************/

int Gg::get_n_r2r()
{
	std::vector<std::vector<int>> v_r2r_paths;

	v_r2r_paths = this->getR2RPaths();

	return v_r2r_paths.size();
}

/**********************************************************
 * metodo: get_n_regs                                     *
 * proposito: devuelve la cantidad de registros.          *
 * parametros:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  cantidad de registros.                                *
 *********************************************************/

int Gg::get_n_regs()
{
	int v_n = 0;

	for (auto v_cell : this->cells)
	{
		if (v_cell->getTypeID() == NODE_ID_REG)
		{
			v_n++;
		}
	}

	return v_n;
}

///////////////////////////////////////////////////////////
// metodo: Get_Path                                      //
// proposito: obtiene la ruta del archivo.               //
// argumentos:                                           //
//  name - nombre del archivo.                           //
// devuelve:                                             //
//  ruta del archivo.                                    //
///////////////////////////////////////////////////////////

std::string Gg::Get_Path(std::string name)
{
	size_t i = name.rfind('/', name.length());

	if (i != string::npos) 
	{
		return (name.substr(0, i + 1));
	}

	return ("");
}

///////////////////////////////////////////////////////////
// metodo: getReg                                        //
// proposito: devuelve un registro de la lista.          //
// argumentos:                                           //
//  r - numero de celda ( por referencia ).              //
// devuelve:                                             //
//  true - encontro un registro.                         //
//  false - no hay mas registros en la lista.            //
///////////////////////////////////////////////////////////

bool Gg::getReg(int &r)
{
	// busqueda finalizada
	if (cell_index >= cells.size())
	{
		return false;
	}

	// recorre la lista de celdas
	while (cell_index < cells.size())
	{
		// es un registro o un latch
		if (cells[cell_index]->getTypeID() == NODE_ID_REG ||
			cells[cell_index]->getTypeID() == NODE_ID_LATCH)
		{
			r = cell_index;
			cell_index++;
			return true;
		}

		cell_index++;
	}

	// busqueda finalizada
	return false;
}

///////////////////////////////////////////////////////////
// metodo: Get_Reg_Ids                                   //
// proposito: devuelve los identificadores de los        //
//            registros de capture.                      //
// argumentos:                                           //
//  r2r_paths - caminos registro a registro.             //
// devuelve:                                             //
//  identificadores de los registros de capture.         //
///////////////////////////////////////////////////////////

vector<int> Gg::Get_Reg_Ids(vector<vector<int>> r2r_paths)
{
	int id;
	int r;
	vector<int> ids;

	// recorre todos los caminos r2r
	for (auto p : r2r_paths)
	{
		r = Get_Capture_Reg(p);

		id = cells[r]->Get_Id_Annotation();

		if (std::find(ids.begin(), ids.end(), id) == ids.end())
		{
			ids.push_back(id);
		}
	}

	return ids;
}

/**********************************************************
 * metodo: get_type_string                                *
 * proposito: devuelve un string con el tipo de celda.    *
 * parametros:                                            *
 *  cell - numero de celda.                               *
 * devuelve:                                              *
 *  string con el tipo de celda.                          *
 *********************************************************/

std::string Gg::get_type_string(uint32_t cell)
{
    return (this->cells[cell])->get_type_string();
}

///////////////////////////////////////////////////////////
// metodo: initR2RSearch                                 //
// proposito: inicia la busqueda de registros.           //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::initR2RSearch()
{
	cell_index = 0;
}

///////////////////////////////////////////////////////////
// metodo: insertAdder                                   //
// proposito: agrega un sumador.                         //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertAdder(vector<int> f1, vector<int> f2)
{
	int g;
	Adder* dev = new Adder();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertAdderCout                               //
// proposito: agrega un sumador con salida de carry.     //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertAdderCout(vector<int> f1, vector<int> f2)
{
	int g;
	AdderCout* dev = new AdderCout();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertAnd2                                    //
// proposito: agrega una compuerta and2 al grafo.        //
// argumentos:                                           //
//  f1 - fanin 1.                                        //
//  f2 - fanin 2.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertAnd2(int f1, int f2)
{
	int g;
	And2* dev = new And2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertAnd2                                    //
// proposito: agrega compuertas And2 a un bus.           //
// argumentos:                                           //
//  f1_bus - bus de entrada 1.                           //
//  f2_bus - bus de entrada 2.                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertAnd2(vector<int> f1_bus, 
							vector<int> f2_bus)
{
	int g;
	int i;
	int net;
	vector<int> bus;

	for (int i = 0; i < f1_bus.size(); i++)
	{
		g = insertAnd2(f1_bus[i], f2_bus[i]);
		net = drive(g);

		bus.push_back(net);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: insertBuf                                     //
// proposito: agrega una compuerta Buf al grafo.         //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertBuf(void)
{
	int g;
	Buf* dev = new Buf();

	cells.push_back(dev);
	g = cells.size() - 1;

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertBuf                                     //
// proposito: agrega una compuerta Buf a un bus.         //
// argumentos:                                           //
//  bus - bus.                                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertBuf(vector<int> bus)
{
	int i;
	int g;
	vector<int> node;
	Buf* dev;

	for (i = 0; i < bus.size(); i++)
	{
		dev = new Buf();
		cells.push_back(dev);
		g = cells.size() - 1;
		connect(g, bus[i]);
		node.push_back(g);		
	}

	return node;
}

///////////////////////////////////////////////////////////
// metodo: insertCpEq                                    //
// proposito: agrega un comparador por igualdad.         //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpEq(vector<int> f1, vector<int> f2)
{
	int g;
	CpEq* dev = new CpEq();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertCpGr                                    //
// proposito: agrega un comparador por mayor.            //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpGr(vector<int> f1, vector<int> f2)
{
	int g;
	CpGr* dev = new CpGr();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertCpGEq                                   //
// proposito: agrega un comparador por mayor o igual.    //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpGEq(vector<int> f1, vector<int> f2)
{
	int g;
	CpGEq* dev = new CpGEq();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertCpLw                                    //
// proposito: agrega un comparador por menor.            //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpLw(vector<int> f1, vector<int> f2)
{
	int g;
	CpLw* dev = new CpLw();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertCpLEq                                   //
// proposito: agrega un comparador por menor o igual.    //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpLEq(vector<int> f1, vector<int> f2)
{
	int g;
	CpLEq* dev = new CpLEq();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}


///////////////////////////////////////////////////////////
// metodo: insertCpNeq                                   //
// proposito: agrega un comparador por desigualdad.      //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertCpNeq(vector<int> f1, vector<int> f2)
{
	int g;
	CpNeq* dev = new CpNeq();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: Insert_FC                                     //
// proposito: agrega un fork controller.                 //
// argumentos:                                           //
//  lc - latch controller o fork controller.             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::Insert_FC(int lc)
{
	int g;
	int le;
	FC* dev = new FC();

	cells.push_back(dev);
	g = cells.size() - 1;

	return g;
}

///////////////////////////////////////////////////////////
// metodo: Insert_Handshake                              //
// proposito: establece handshake entre 2 latch          //
//            controllers.                               //
// argumentos:                                           //
//  c - capture latch controller.                        //
//  l - launching latch controller.                      //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::Insert_Handshake(int c, int l)
{
	int la;
	int rr;

	// Foward
//	rr = insertNet(c);
	Net* net = new Net(l);

	// agrega net a la lista
	nets.push_back(net);

	rr = nets.size() - 1;


	(cells[l])->insertFanout(rr, FAN_REQ_RIGHT);
	connect(c, rr, FAN_REQ_LEFT);

	// Feedback
//	la = insertNet(l);
	net = new Net(c);

	nets.push_back(net);

	la = nets.size() - 1;


	(cells[c])->insertFanout(la, FAN_ACK_LEFT);
	connect(l, la, FAN_ACK_RIGHT);
}

///////////////////////////////////////////////////////////
// metodo: Insert_JC                                     //
// proposito: agrega un join controller.                 //
// argumentos:                                           //
//  lc - latch controller o join controller.             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::Insert_JC(int lc)
{
	int g;
	int le;
	JC* dev = new JC();

	cells.push_back(dev);
	g = cells.size() - 1;

	return g;
}

///////////////////////////////////////////////////////////
// metodo: Insert_LC                                     //
// proposito: agrega un latch controller.                //
// argumentos:                                           //
//  lb - latch bus.                                      //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::Insert_LC(std::vector<int> lb)
{
	int g;
	int le;
	LC* dev = new LC();

	cells.push_back(dev);
	g = cells.size() - 1;

	for (auto l : lb)
	{
		le = insertNet(g);
		(cells[g])->insertFanout(le, 0);
		connect(l, le, 1);
	}

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertMult                                    //
// proposito: agrega un multiplicador.                   //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertMult(vector<int> f1, vector<int> f2)
{
	int g;
	Mult* dev = new Mult();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertMux2                                    //
// proposito: agrega un mux2 al grafo.                   //
// argumentos:                                           //
//  fs - fanin s.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertMux2(int fs)
{
	int g;
	Mux2* dev = new Mux2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, fs);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertMuxN                                    //
// proposito: agrega un muxN al grafo.                   //
// argumentos:                                           //
//  fs - fanin bus s.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertMuxN(vector<int> fs)
{
	int g;
	MuxN* dev = new MuxN();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, fs);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertMux2                                    //
// proposito: agrega un mux2 al grafo.                   //
// argumentos:                                           //
//  f1 - fanin 1.                                        //
//  f2 - fanin 2.                                        //
//  fs - fanin s.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertMux2(int f1, int f2, int fs)
{
	int g;
	Mux2* dev = new Mux2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, fs);
	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertNeg                                     //
// proposito: agrega un cambio de signo.                 //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertNeg(vector<int> f)
{
	int g;
	Neg* dev = new Neg();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f);

	return g;
}


///////////////////////////////////////////////////////////
// metodo: insertNet                                     //
// proposito: agrega un segmento al grafo.               //
//            Solo conecta la cola ( fanout ).           //
// argumentos:                                           //
//  t - cola del segmento.                               //
// devuelve:                                             //
//  numero de segmento en la lista.                      //
///////////////////////////////////////////////////////////

int Gg::insertNet(int t)
{
	int n;

	Net* net = new Net(t);

	// agrega net a la lista
	nets.push_back(net);

	n = nets.size() - 1;

	// suma fanout al source device
	(cells[t])->insertFanout(n);

	return n;
}

///////////////////////////////////////////////////////////
// metodo: insertNet                                     //
// proposito: agrega un segmento al grafo.               //
// argumentos:                                           //
//  h - cabeza del segmento.                             //
//  t - cola del segmento.                               //
// devuelve:                                             //
//  numero de segmento en la lista.                      //
///////////////////////////////////////////////////////////

int Gg::insertNet(int h, int t)
{
	int n;

	Net* net = new Net(h, t);

	// agrega net a la lista
	nets.push_back(net);

	n = nets.size() - 1;

	// suma fanout al source device
	(cells[t])->insertFanout(n);

	// suministra fanin al sink device
	(cells[h])->insertFanin(n);

	return n;
}

///////////////////////////////////////////////////////////
// metodo: insertNot                                     //
// proposito: agrega una compuerta Not al grafo.         //
// argumentos:                                           //
//  f - fanin.                                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertNot(int f)
{
	int g;
	Not* dev = new Not();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertNot                                     //
// proposito: agrega compuertas Not a un bus.            //
// argumentos:                                           //
//  nodes - vector de nodos.                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertNot(vector<int> nodes)
{
	int g;
	int net;
	vector<int> bus;

	for (int i = 0; i < nodes.size(); i++)
	{
		g = insertNot(nodes[i]);
		net = drive(g);

		bus.push_back(net);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: insertOr2                                     //
// proposito: agrega una compuerta or2 al grafo.         //
// argumentos:                                           //
//  f1 - fanin 1.                                        //
//  f2 - fanin 2.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertOr2(int f1, int f2)
{
	int g;
	Or2* dev = new Or2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertOr2                                     //
// proposito: agrega compuertas Or2 a un bus.            //
// argumentos:                                           //
//  f1_bus - bus de entrada 1.                           //
//  f2_bus - bus de entrada 2.                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertOr2(vector<int> f1_bus, 
							vector<int> f2_bus)
{
	int g;
	int i;
	int net;
	vector<int> bus;

	for (int i = 0; i < f1_bus.size(); i++)
	{
		g = insertOr2(f1_bus[i], f2_bus[i]);
		net = drive(g);

		bus.push_back(net);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: insertPortIn                                  //
// proposito: agrega un puerto de entrada al grafo.      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertPortIn(void)
{
	PortIn* dev = new PortIn();

	cells.push_back(dev);

	return cells.size() - 1;
}

///////////////////////////////////////////////////////////
// metodo: insertPortOut                                 //
// proposito: agrega un puerto de salida al grafo.       //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertPortOut(void)
{
	PortOut* dev = new PortOut();

	cells.push_back(dev);

	return cells.size() - 1;
}

///////////////////////////////////////////////////////////
// metodo: insertReg                                     //
// proposito: agrega un elemento de memoria al grafo.    //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertReg(void)
{
	Reg* dev = new Reg();

	cells.push_back(dev);

	return cells.size() - 1;
}

///////////////////////////////////////////////////////////
// metodo: insertSub                                     //
// proposito: agrega un restador.                        //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertSub(vector<int> f1, vector<int> f2)
{
	int g;
	Sub* dev = new Sub();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertSubBout                                 //
// proposito: agrega un restador con salida de borrow.   //
// argumentos:                                           //
//  f1 - fanin bus 1.                                    //
//  f2 - fanin bus 2.                                    //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertSubBout(vector<int> f1, vector<int> f2)
{
	int g;
	SubBout* dev = new SubBout();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertTieHi                                   //
// proposito: agrega un tie hi al grafo.                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertTieHi(void)
{
	TieHi* dev = new TieHi();

	cells.push_back(dev);

	return cells.size() - 1;
}

///////////////////////////////////////////////////////////
// metodo: insertTieLo                                   //
// proposito: agrega un tie hi al grafo.                 //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertTieLo(void)
{
	TieLo* dev = new TieLo();

	cells.push_back(dev);

	return cells.size() - 1;
}

///////////////////////////////////////////////////////////
// metodo: insertXor2                                    //
// proposito: agrega una compuerta xor2 al grafo.        //
// argumentos:                                           //
//  f1 - fanin 1.                                        //
//  f2 - fanin 2.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertXor2(int f1, int f2)
{
	int g;
	Xor2* dev = new Xor2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertXor2                                    //
// proposito: agrega compuertas Xor2 a un bus.           //
// argumentos:                                           //
//  f1_bus - bus de entrada 1.                           //
//  f2_bus - bus de entrada 2.                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertXor2(vector<int> f1_bus, 
							vector<int> f2_bus)
{
	int g;
	int i;
	int net;
	vector<int> bus;

	for (int i = 0; i < f1_bus.size(); i++)
	{
		g = insertXor2(f1_bus[i], f2_bus[i]);
		net = drive(g);

		bus.push_back(net);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: insertXnor2                                   //
// proposito: agrega una compuerta xnor2 al grafo.       //
// argumentos:                                           //
//  f1 - fanin 1.                                        //
//  f2 - fanin 2.                                        //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

int Gg::insertXnor2(int f1, int f2)
{
	int g;
	Xnor2* dev = new Xnor2();

	cells.push_back(dev);
	g = cells.size() - 1;

	connect(g, f1);
	connect(g, f2);

	return g;
}

///////////////////////////////////////////////////////////
// metodo: insertXnor2                                   //
// proposito: agrega compuertas Xnor2 a un bus.          //
// argumentos:                                           //
//  f1_bus - bus de entrada 1.                           //
//  f2_bus - bus de entrada 2.                           //
// devuelve:                                             //
//  numero de nodo en la lista.                          //
///////////////////////////////////////////////////////////

vector<int> Gg::insertXnor2(vector<int> f1_bus, 
							vector<int> f2_bus)
{
	int g;
	int i;
	int net;
	vector<int> bus;

	for (int i = 0; i < f1_bus.size(); i++)
	{
		g = insertXnor2(f1_bus[i], f2_bus[i]);
		net = drive(g);

		bus.push_back(net);
	}

	return bus;
}

///////////////////////////////////////////////////////////
// metodo: is_Output_Bus                                 //
// proposito: determina si la salida de la celda es un   //
//            bus.                                       //
// argumentos:                                           //
//  n - numero de celda en la lista.                     //
// devuelve:                                             //
//  true - la salida de la celda es un bus.              //
//  false - la salida de la celda es un wire.            //
///////////////////////////////////////////////////////////

bool Gg::is_Output_Bus(int n)
{
	return cells[n]->is_Output_Bus();
}

///////////////////////////////////////////////////////////
// metodo: print                                         //
// proposito: muestra el grafo.                          //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::print(void)
{
	int i = 0;

	cout << "Nodes" << endl;
	cout << "-----" << endl << endl;

	// recorre todos los nodos
	// y los muestra
	for (auto &node : cells)
	{
		cout << i++ << "\t";
		node->print();
	}

	cout << endl << endl;

	i = 0;

	cout << "Nets" << endl;
	cout << "----" << endl << endl;

	// recorre todos los nets
	// y los muestra
	for (auto &net : nets)
	{
		cout << i++ << "\t";
		net->print();
	}

	cout << endl << endl;

	i = 0;

	cout << "Nodes full info" << endl;
	cout << "----- ---- ----" << endl << endl;

	// recorre todos los nodos
	// y muestra informacion detallada
	for (auto &node : cells)
	{
		node->fullPrint(i++);
	}

	cout << endl << endl;

}

///////////////////////////////////////////////////////////
// metodo: queryBusFanout                                //
// proposito: consulta los fanout buses de un nodo.      //
// argumentos:                                           //
//  n - nodo consultado.                                 //
// devuelve:                                             //
//  fanout buses.                                        //
///////////////////////////////////////////////////////////

std::vector<std::vector<int>> Gg::queryBusFanout(int n)
{
	return cells[n]->queryBusFanouts();
}

///////////////////////////////////////////////////////////
// metodo: Query_Ids                                     //
// proposito: devuelve los identificadores de un bus.    //
// argumentos:                                           //
//  bus - lista de nodos con latches.                    //
// devuelve:                                             //
//  lista de identificadores.                            //
///////////////////////////////////////////////////////////

std::vector<int> Gg::Query_Ids(std::vector<int> bus)
{
	std::vector<int>::iterator it;
	std::vector<int> ids;

	for (auto n : bus)
	{
		if ((it = std::find(ids.begin(), ids.end(), 
				cells[n]->Get_Id_Annotation())) == ids.end())
		{
			ids.push_back(cells[n]->Get_Id_Annotation());
		}
	}

	return ids;
}

///////////////////////////////////////////////////////////
// metodo: query_Launching_Latch                         //
// proposito: consulta los fanin de latches.             //
// argumentos:                                           //
//  id - identificador.                                  //
//  r2r - caminos r2r.                                   //
// devuelve:                                             //
//  fanout buses.                                        //
///////////////////////////////////////////////////////////

std::vector<int> Gg::query_Launching_Latch(
	std::vector<int> latch,
	std::vector<std::vector<int>> r2r)
{
	std::vector<int> latch_bus;

	// recorre cada camino r2r
	for (auto p : r2r)
	{
		// recorro todos los latches de capture
		for (auto lc : latch)
		{
			// el camino r2r tiene el latch buscado
			if (lc == p[p.size() - 1])
			{
				latch_bus.push_back(p[0]);
			}
		}
	}

	return latch_bus;
}

///////////////////////////////////////////////////////////
// metodo: queryDriver                                   //
// proposito: consulta la cola de un net.                //
// argumentos:                                           //
//  n - net consultado.                                  //
// devuelve:                                             //
//  cola del net consultado.                             //
///////////////////////////////////////////////////////////

int Gg::queryDriver(int n)
{
	return nets[n]->queryTail();
}

///////////////////////////////////////////////////////////
// metodo: queryFanin                                    //
// proposito: consulta el net de fanin de un nodo.       //
// argumentos:                                           //
//  n - nodo consultado.                                 //
//  f - fanin consultado.                                //
// devuelve:                                             //
//  net de fanin.                                        //
///////////////////////////////////////////////////////////

int Gg::queryFanin(int n, int f)
{
	return cells[n]->queryFanin(f);
}

///////////////////////////////////////////////////////////
// metodo: queryFanout                                   //
// proposito: consulta los fanouts de un nodo.           //
// argumentos:                                           //
//  n - nodo consultado.                                 //
// devuelve:                                             //
//  fanouts.                                             //
///////////////////////////////////////////////////////////

vector<int> Gg::queryFanout(int n)
{
	return cells[n]->queryFanouts();
}

///////////////////////////////////////////////////////////
// metodo: queryLatches                                  //
// proposito: consulta los latches.                      //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  lista de latches.                                    //
///////////////////////////////////////////////////////////

std::vector<int> Gg::queryLatches()
{
	int i = 0;
	std::vector<int> latches;

	for (auto c : cells)
	{
		if (c->getTypeID() == NODE_ID_LATCH)
		{
			latches.push_back(i);
		}
		i++;
	}

	return latches;
}

///////////////////////////////////////////////////////////
// metodo: queryLoad                                     //
// proposito: consulta la cabeza de un net.              //
// argumentos:                                           //
//  n - net consultado.                                  //
// devuelve:                                             //
//  cabeza del net consultado.                           //
///////////////////////////////////////////////////////////

int Gg::queryLoad(int n)
{
	return nets[n]->queryHead();
}

///////////////////////////////////////////////////////////
// metodo: Reg2Latch                                     //
// proposito: reemplaza registros por latches.           //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::Reg2Latch()
{
	Latch* l;

	for (int i = 0; i < cells.size(); i++)
	{
		// encontro un registro
		if (cells[i]->getTypeID() == NODE_ID_REG)
		{
			l = new Latch(((Reg*)cells[i])->queryFanin(0),
						((Reg*)cells[i])->queryFanouts(),
						((Reg*)cells[i])->Get_Id_Annotation(),
						((Reg*)cells[i])->Get_Ix_Annotation());

			delete cells[i];

			cells[i] = l;
		}
	}
}

/**********************************************************
 * metodo: f_remove_r2r_paths_duplicates                  *
 * proposito: elimina caminos r2r duplicados.             *
 * argumentos:                                            *
 *  paths - caminos r2r a analizar ( por referencia ).    *
 * devuelve:                                              *
 *  nada.                                                 *
 *********************************************************/

void Gg::f_remove_r2r_paths_duplicates(std::vector<std::vector<int>> &paths)
{
    int i, j;
    int c_reg_valid, c_reg_doubt;
    int l_reg_valid, l_reg_doubt;

    /* recorre todos los posibles caminos r2r */
    for (i = 0; i < paths.size() - 1; i++)
    {
        /* solo interesan launching y capture register */
        l_reg_valid = paths[i][0];
        c_reg_valid = paths[i][paths[i].size() - 1];

        /* recorre los siguientes caminos r2r */
        for (j = i + 1; j < paths.size(); j++)
        {
            /* camino entre launching y capture register
             * a probar */
            l_reg_doubt = paths[j][0];
            c_reg_doubt = paths[j][paths[j].size() - 1];

            /* elimina registro */
            if (l_reg_valid == l_reg_doubt &&
                c_reg_valid == c_reg_doubt)
            {
                paths.erase(paths.begin() + j);
                i--;
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////
// metodo: Serialize                                     //
// proposito: guarda el grafo en un archivo json.        //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::Serialize()
{
}

///////////////////////////////////////////////////////////
// metodo: source                                        //
// proposito: agenda el nombre del archivo fuente.       //
// argumentos:                                           //
//  name - nombre del archivo fuente                     //
// devuelve:                                             //
//  nada.                                                //
///////////////////////////////////////////////////////////

void Gg::source(std::string name)
{
	jname = getFullName(name);
	jname = getMainName(jname);
	path = getPath(name);
}

///////////////////////////////////////////////////////////
// metodo: wire                                          //
// proposito: conecta 2 nodos.                           //
// argumentos:                                           //
//  d - numero de nodo destino.                          //
//  s - numero de nodo origen.                           //
// devuelve:                                             //
//  numero de net en la lista.                           //
///////////////////////////////////////////////////////////

int Gg::wire(int d, int s)
{
	return insertNet(d, s);
}

///////////////////////////////////////////////////////////
// operador: =                                           //
// proposito: clona un grafico.                          //
// argumentos:                                           //
//  g - grafo original ( por referencia ).               //
// devuelve:                                             //
//  imagen clonada.                                      //
///////////////////////////////////////////////////////////

Gg& Gg::operator = (const Gg& g)
{
	int t;
	Net* w;
	Node* p;

	if (this == &g)
	{
		return *this;
	}

	// clona las celdas
	for (auto c : g.cells)
	{
		t = c->getTypeID();

		p = Clone_Cell(c);

		cells.push_back(p);
	}

	// clona los wires
	for (auto n : g.nets)
	{
		w = new Net(n);

		nets.push_back(w);
	}

	return *this;
}
