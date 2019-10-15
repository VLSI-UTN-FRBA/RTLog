///////////////////////////////////////////////////////////
// codigo fuente: gg.h                                   //
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
//                ( 2 sobrecargas )                      //
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

#ifndef __GG_H
#define __GG_H

#include <vector>

#include "node.h"
#include "net.h"

class Gg
{
	public:
		void Annotate(int node, int d, int x);
		void connect(int node, int net);
		void connect(int node, vector<int> bus);
		void connect(int* node, vector<int> bus);
		void connect(int node, int net, int i);
		void connect(vector<int>, vector<int>);
		int drive(int n);
		int drive(int n, int f);
		vector<int> driveBus(int n);
		vector<int> driveBus(vector<int> nodes);
        int get_id_annotation(int cell);
        int get_ix_annotation(int cell);
		int Get_Capture_Reg(vector<int> p);
		vector<Node*>* getCells(void);
        std::string get_cell_type(uint32_t c);
		std::vector<int> Get_Capture_Latch_From_Id(int id);
		std::vector<std::vector<int>> Get_Cloud_Logic(
			vector<vector<int>> r2r_paths);
		bool Get_Input(int &i);
		std::string getFullName(std::string name);
		std::string getMainName(std::string name);
		std::string getPath(std::string name);
		std::vector<std::vector<int>> Get_Input_Logic(
					std::vector<std::vector<int>> i2r_paths);
		std::vector<int> Get_Latch_Fanin_Inputs(int id);
		std::vector<int> Get_Latch_From_Id(int id);
		std::vector<int> Get_Launching_Latch_From_Id(int id);
		std::vector<int> Get_Launching_Latch_Ids(
			std::vector<std::vector<int>> r2r_paths);
		int Get_Launching_Reg(std::vector<int> p);
		int get_n_cells();
		int get_n_nets();
		int get_n_i2r();
		int get_n_inputs();
		int get_n_outputs();
		int get_n_r2o();
		int get_n_r2r();
		int get_n_regs();
		vector<Net*>* getNets(void);
		std::vector<std::vector<int>> get2OPaths(int f);
		vector<vector<int>> get2RPaths(int f);
		std::vector<std::vector<int>> Get_I2R_Paths();
		bool Get_Output(int &o);
		std::vector<std::vector<int>> Get_Output_Logic(
					std::vector<std::vector<int>> r2o_paths);
		std::string Get_Path(std::string name);
		std::vector<std::vector<int>> Get_R2O_Paths();
		vector<vector<int>> getR2RPaths();
		bool getReg(int &r);
		vector<int> Get_Reg_Ids(vector<vector<int>> r2r_paths);
		std::vector<int> Get_Latch_Ids();
        std::string get_type_string(uint32_t cell);
		void initR2RSearch();
		int insertAdder(vector<int> f1, vector<int> f2);
		int insertAdderCout(vector<int> f1, vector<int> f2);
		int insertAnd2(int f1, int f2);
		vector<int> insertAnd2(vector<int> f1_bus, 
							vector<int> f2_bus);
		int insertBuf(void);
		vector<int> insertBuf(vector<int> bus);
		int insertCpEq(vector<int> f1, vector<int> f2);
		int insertCpGr(vector<int> f1, vector<int> f2);
		int insertCpGEq(vector<int> f1, vector<int> f2);
		int insertCpLw(vector<int> f1, vector<int> f2);
		int insertCpLEq(vector<int> f1, vector<int> f2);
		int insertCpNeq(vector<int> f1, vector<int> f2);
		int Insert_FC(int lc);
		void Insert_Handshake(int c, int l);
		int Insert_JC(int lc);
		int Insert_LC(std::vector<int> lb);
		int insertMult(vector<int> f1, vector<int> f2);
		int insertMux2(int fs);
		int insertMux2(int f1, int f2, int fs);
		int insertMuxN(vector<int> fs);
		int insertNeg(vector<int> f);
		int insertNet(int t);
		int insertNet(int h, int t);
		int insertNot(int f);
		vector<int> insertNot(vector<int> nodes);
		int insertOr2(int f1, int f2);
		vector<int> insertOr2(vector<int> f1_bus, 
							vector<int> f2_bus);
		int insertPortIn(void);
		int insertPortOut(void);
		int insertSub(vector<int> f1, vector<int> f2);
		int insertSubBout(vector<int> f1, vector<int> f2);
		int insertTieHi(void);
		int insertTieLo(void);
		int insertXor2(int f1, int f2);
		vector<int> insertXor2(vector<int> f1_bus, 
							vector<int> f2_bus);
		int insertXnor2(int f1, int f2);
		std::vector<int> insertXnor2(std::vector<int> f1_bus, 
							std::vector<int> f2_bus);
		int insertReg(void);
		bool is_Output_Bus(int n);
		void print(void);
		std::vector<std::vector<int>> queryBusFanout(int n);
		std::vector<int> query_Launching_Latch(
			std::vector<int> latch,
			std::vector<std::vector<int>> r2r);
		int queryDriver(int n);
		int queryFanin(int n, int f);
		vector<int> queryFanout(int n);
		std::vector<int> Query_Ids(std::vector<int> bus);
		std::vector<int> queryLatches();
		int queryLoad(int n);
		void Reg2Latch();
        void f_remove_r2r_paths_duplicates(std::vector<std::vector<int>> &paths);
		void Serialize();
		void source(std::string name);
		int wire(int d, int s);

		Gg& operator = (const Gg& g);
	private:
		Node* Clone_Cell(Node* c);

		int cell_index;
		std::string jname;
		std::string path;
		std::vector<Node*> cells;
		std::vector<Net*> nets;
};

#endif
