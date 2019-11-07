///////////////////////////////////////////////////////////
// codigo fuente: emitter.h                              //
// fecha de inicio: 23/12/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase Emitter para generar codigo Verilog. //
//                                                       //
// clase implementada:                                   //
//  Emitter                                              //
// propiedades:                                          //
// metodos:                                              //
//  add - emite driving y asignacion de una suma.        //
//  addcout - emite driving y asignacion de una suma con //
//            carry de salida.                           //
//  and2 - emite driving y asignacion de una and.        //
//  body - cuerpo principal del codigo Verilog.          //
//  buf - emite driving y asignacion de un buffer.       //
//  compose - construye un vector por concatenacion.     //
//  composepp - construye un vector por concatenacion    //
//              con un bit adicional.                    //
//  cpeq - emite driving y asignacion de un              //
//         comparador por igual.                         //
//  cpgr - emite driving y asignacion de un              //
//            comparador por mayor.                      //
//  cpgeq - emite driving y asignacion de un             //
//            comparador por mayor o igual.              //
//  cpleq - emite driving y asignacion de un             //
//            comparador por meno o igual.               //
//  cplw - emite driving y asignacion de un              //
//            comparador por menor.                      //
//  cpneq - emite driving y asignacion de un             //
//            comparador por distinto.                   //
//  create - crea el archivo Verilog.                    //
//  decls - genera la declaracion de wires locales.      //
//  fork_controller - emite driving y asignacion de un   //
//                    fork controller.                   //
//  getFullName - obtiene el nombre completo del         //
//                archivo.                               //
//  getMainName - obtiene el nombre principal del        //
//                archivo.                               //
//  getPath - obtiene la ruta del archivo.               //
//  getPortName - obtiene el nombre de un puerto.        //
//  inv - emite driving y asignacion de un inversor.     //
//  join_controller - emite driving y asignacion de un   //
//                    join controller.                   //
//  latch - emite driving y asignacion de un latch.      //
//  latch_controller - emite driving y asignacion de un  //
//                     latch controller.                 //
//  module - genera la declaracion module.               //
//  mult - emite driving y asignacion de una             //
//         multiplicacion.                               //
//  mux2 - emite driving y asignacion de un              //
//            multiplexor de 2 entradas.                 //
//  neg - emite driving y asignacion de un cambio de     //
//            signo.                                     //
//  or2 - emite driving y asignacion de una or.          //
//  ports - genera la declaracion puertos.               //
//  port_in - emite driving de puerto de entrada.        //
//  port_out - emite asignacion a puerto de salida.      //
//  reg - emite driving y asignacion de un registro.     //
//  source - agenda el nombre del archivo fuente.        //
//  sub - emite driving y asignacion de una resta.       //
//  subboout - emite driving y asignacion de una         //
//            resta con salida de borrow.                //
//  tail - cierra el archivo Verilog.                    //
//  ties - genera tie cells.                             //
//  tie_hi - emite driving de celda tie hi.              //
//  tie_lo - emite driving de celda tie lo.              //
//  xor2 - emite driving y asignacion de una xor.        //
//  xnor2 - emite driving y asignacion de una xnor.      //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __EMITTER_H
#define __EMITTER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "net.h"
#include "node.h"
#include "port.h"

class Emitter
{
	public:
		void body(vector<Node*>* cells,
					vector<Net*>* nets);
		void create(bool is_async);
		void decls(vector<Port> &decl_table);
		void module(string block);
		void ports(vector<Port> &p_tb, bool is_async);
		void source(std::string name);
		void tail(void);
		void ties(bool tie_hi_used, bool tie_lo_used);
	private:
		std::ofstream file;
		std::ostringstream locals;
		std::ostringstream stmts;
		std::string path;
		string vname;
		vector<Port> port_table;

		string getFullName(string name);
		string getMainName(string name);
		string getPath(string name);
		string getPortName(int n);
		void add(Node *node, int n);
		void addcout(Node *node, int n);
		void and2(Node *node, int n);
		void buf(Node *node, int n);
		void compose(int *nodes, int width);
		void composepp(int *nodes, int width);
		void cpeq(Node *node, int n);
		void cpgr(Node *node, int n);
		void cpgeq(Node *node, int n);
		void cpleq(Node *node, int n);
		void cplw(Node *node, int n);
		void cpneq(Node *node, int n);
		void fork_controller(Node *node, int n);
		void inv(Node *node, int n);
		void join_controller(Node *node, int n);
		void latch(Node *node, int n);
		void latch_controller(Node *node, int n);
		void mult(Node *node, int n);
		void mux2(Node *node, int n);
		void neg(Node *node, int n);
		void or2(Node *node, int n);
		void port_in(Node *node, int n);
		void port_out(Node *node, int n);
		void reg(Node *node, int n);
		void sub(Node *node, int n);
		void subbout(Node *node, int n);
		void tie_hi(Node *node);
		void tie_lo(Node *node);
		void xor2(Node *node, int n);
		void xnor2(Node *node, int n);
};

#endif
