///////////////////////////////////////////////////////////
// codigo fuente: parser.h                               //
// fecha de inicio: 03/10/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase parser para analizar la sintaxis de  //
//            codigo en lenguaje RTLog.                  //
//                                                       //
// clase implementada:                                   //
//  Parser                                               //
// propiedades:                                          //
//  block_name - identificador del nombre del block.     //
//  m_clouds - cloud logic.                              //
//  m_constants - diccionario de constantes.             //
//  m_i2r_paths - caminos i2r.                           //
//  m_r2o_paths - caminos r2o.                           //
//  m_r2r_paths - caminos r2r.                           //
//  degraph - grafo del circuito desincronizado.         //
//  generate_ids - id de los indices de los generates.   //
//  generate_index - valor de los indices de los         //
//                   generates.                          //
//  generate_rel_flags - indicadores de expresiones      //
//                       booleanas en un when.           //
//  graph - grafo del circuito.                          //
//  meta_graph - meta grafo del circuito.                //
//  local_table - tabla de wires locales.                //
//  port_table - tabla de puertos.                       //
//  tok - implementacion del tokenizer.                  //
//  op_token - token obtenido ( num o op ).              //
//  token - token obtenido ( keywords o id ).            //
// metodos:                                              //
//  assign - parsing de sentencias de asignacion.        //
//  block - parsing de la definicion bloque.             //
//  boolean - parsing de sentencias if.                  //
//  concatenation - parsing de sentencias de             //
//                  concatenacion.                       //
//  decls - parsing de la definicion wire internos.      //
//  desync - desincroniza el grafo.                      //
//  dim - parsing de la dimension de un bus.             //
//  emit - genera el archivo Verilog.                    //
//  expr - parsing de sentencias de suma y resta.        //
//  f_eval_expr - parsing de una expresion evaluada.     //
//  f_eval_factor - proposito: parsing de un factor      //
//      evaluado.                                        //
//  f_eval_logic - parsing de una expresion logica.      //
//  f_eval_rel - parsing de una expresion relacional.    //
//  f_eval_term - parsing de un termino evaluado.        //
//  f_eval_unary - parsing de un unary evaluado.         //
//  factor - parsing de factores.                        //
//  f_find_const - determina si existe una constante.    //
//  f_find_param - determina si existe un parametro.     //
//  for_generate - parsing de un for generate.           //
//  f_generate_condition - parsing de la condicion       //
//      de un when.                                      //
//  f_generate_conditional - parsing de un for generate  //
//      condicionado por whens.                          //
//  f_generate_factor - parsing de un factor de la       //
//      condicion que activa el when.                    //
//  getNodes - obtiene los numeros de nodos de un        //
//            identificador.                             //
//  init - inicializaccion del parser.                   //
//  inputs - parsing de la definicion puertos de         //
//           entrada.                                    //
//  Insert_FC - inserta fork controllers en forma        //
//              recursiva.                               //
//  Insert_JC - inserta join controllers en forma        //
//              recursiva.                               //
//  leftValue - parsing del left value.                  //
//  left_value_offset - parsing de la indexacion de un   //
//                      left value.                      //
//  logical - parsing de sentencias logicas.             //
//  makeTree - completa arbol de multiplexores.          //
//             ( 2 sobrecargas ).                        //
//  offset - parsing de un indice.                       //
//  outputs - parsing de la definicion puertos de        //
//            salida.                                    //
//  parameters - parsing de la definicion de parametros. //
//  ports - parsing de la definicion de puertos.         //
//  rel - parsing de sentencias de comparacion.          //
//  replication - parsing de sentencias de replicacion.  //
//  report - genera informe de compilacion.              //
//  f_report_async_graph - informa el grafo asincronico  //
//      generado.                                        //
//  f_report_cloud_logic - informa la cloud logic.       //
//  f_report_general - informe general                   //
//                     de la compilacion.                //
//  f_report_graph - informa el grafo generado.          //
//  f_report_i2r_paths - informa los caminos i2r.        //
//  f_report_metagraph - informa el metagrafo.           //
//  f_report_r2o_paths - informa los caminos r2o.        //
//  f_report_r2r_paths - informa los caminos r2r.        //
//  run - analiza la sintaxis del archivo fuente         //
//        agendado.                                      //
//  selection - parsing de sentencias case.              //
//  shift - parsing de sentencias de desplazamiento.     //
//  slicing - parsing de un subvector.                   //
//  stmt - parsing de una sentencia.                     //
//  stmts - parsing de la lista de sentencias.           //
//  term - parsing de sentencias de producto.            //
//  throw_nl - descarta new lines.                       //
//  unary - parsing de operaciones unarias.              //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __PARSER_H
#define __PARSER_H

#include "emitter.h"
#include "env.h"
#include "gg.h"
#include "meta_gg.h"
#include "port.h"
#include "token.h"
#include "tokenizer.h"

using namespace std;

class Parser
{
	public:
		enum E_REPORTS
		{
			E_REPORT_ASYNC_GRAPH,
			E_REPORT_CLOUD_LOGIC,
			E_REPORT_GENERAL,
			E_REPORT_GRAPH,
			E_REPORT_METAGRAPH,
            E_REPORT_I2R_PATHS,
            E_REPORT_R2O_PATHS,
            E_REPORT_R2R_PATHS
		};

		void desync(void);
		bool emit(void);
		bool report(int rep_type);
		bool run(void);
		void setAsync(void);
		void setSync(void);
		bool getClock(void);
		void source(std::string name);
	private:
		int block_name;
		bool is_async;
		bool tie_hi_used;
		bool tie_lo_used;
        std::string filename;
		std::vector<int> generate_ids;
		std::vector<int> generate_indices;
		std::vector<bool> m_generate_rel_flags;
		vector<Env> env;
		vector<Port> local_table;
		vector<Port> port_table;
		Emitter emt;
		Gg graph, degraph;
		Meta_Gg meta_graph;
		Tokenizer tok;
		Token ix1_token;
		Token ix2_token;
		Token op_token;
		Token token;
		std::map<int, int> m_constants;
		std::map<int, int> params;
    	std::vector<std::vector<int>> m_cloud;
    	std::vector<std::vector<int>> m_r2r_paths;
        std::vector<std::vector<int>> m_i2r_paths;
    	std::vector<std::vector<int>> m_r2o_paths;
		
		void assign(void);
		void block(void);
		void boolean(void);
		vector<int> concatenation(int expc_width);
		void decls(void);
		int dim(void);
		vector<int> expr(int expc_width);
		int f_eval_expr();
		int f_eval_factor();
        int f_eval_logic();
		int f_eval_rel();
		int f_eval_term();
		int f_eval_unary();
		vector<int> factor(int expc_width);
		bool f_find_const(uint32_t id);
		bool f_find_param(uint32_t id);
		void for_generate(void);
		void f_generate_condition(int index_id, 
                                    int ix1,
									int ix2, 
									std::vector<int> &ix_matches);
		void f_generate_conditional(int index_id, int ix1, int ix2);
		int f_generate_factor();
        std::string getFullName(std::string name);
        std::string getMainName(std::string name);
		vector<int> getNodes(int id);
        std::string getPath(std::string name);
		void init(void);
		void inputs(void);
		int Insert_FC(BTree *fc_tree, int lc, int fout_u2d, 
						int fin_d2u);
		int Insert_JC(BTree *jc_tree, int lc, int fout_u2d, 
						int fin_d2u);
		vector<int> leftValue(void);
		vector<int> left_value_offset(vector<int> bus);
		vector<int> logical(int expc_width);
		void makeTree(int fanin, int node);
		void makeTree(vector<int> fanin, vector<int> node);
		vector<int> offset(vector<int> bus);
		void outputs(void);
		void parameters(void);
		void ports(void);
		vector<int> rel(int expc_width);
		vector<int> replication(int expc_width);
        bool f_report_async_graph();
        bool f_report_cloud_logic();
		bool f_report_general();
		bool f_report_graph();
        bool f_report_i2r_paths();
        bool f_report_metagraph();
        bool f_report_r2o_paths();
        bool f_report_r2r_paths();
		void selection(void);
		vector<int> shift(int expc_width);
		vector<int> slicing(vector<int> bus, int ix1);
		void stmt(void);
		void stmts(void);
		vector<int> term(int expc_width);
		bool throw_nl(void);
		vector<int> unary(int expc_width);
		bool widthCheck(vector<int> bus_1, vector<int> bus_2);
};

#endif
