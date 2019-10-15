///////////////////////////////////////////////////////////
// codigo fuente: tokenizer.h                            //
// fecha de inicio: 12/10/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase tokenizer para extraer tokens de     //
//            codigo RTLog del archivo fuente.           //
//                                                       //
// clase implementada:                                   //
//  Tokenizer                                            //
// propiedades:                                          //
//  lex - implementacion del Lexer.                      //
//  lexeme - lexema obtenido.                            //
//  symbol_table - tabla de simbolos.                    //
// metodos:                                              //
//  Tokenizer - constructor.                             //
//  annotateSymbolNodes - asocia nodos a un simbolo.     //
//  bin2Dec - convierte un binario a decimal.            //
//  dec2Bin - convierte un numero de decimal a binario.  //
//  isSymbolUsed - determina si un simbolo esta usado.   //
//  getNext - devuelve el proximo token.                 //
//  getNodes - obtiene el vector de nodos asociado a un  //
//            identificador.                             //
//  getNLine - devuelve numero de linea de codigo        //
//            analizado.                                 //
//  getNum - devuelve un int de la tabla de constantes.  //
//  getSymbol - devuelve un string de la tabla de        //
//            simbolos.                                  //
//  lockSymbol - cataloga un simbolo como usado.         //
//  numFindPush - busca un numero en la tabla de         //
//                constantes o lo agrega si no lo        //
//                encuentra.                             //
//  print_symbol_table: muestra la tabla de simbolos.    //
//  recovery_point - establece un punto de retroceso.    //
//  restore - retrocede.                                 //
//  retract - retrocede un token.                        //
//  set_type - asigna un tipo a un simbolo.              //
//  source - agenda nombre de archivo.                   //
//  symbolFindPush - busca un simbolo en la tabla de     //
//                   simbolos o lo agrega si no lo       //
//                   encuentra.                          //
//  unlock_symbol - cataloga un simbolo como no usado.   //
// clases amigas:                                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __TOKENIZER_H
#define __TOKENIZER_H

using namespace std;

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "lexer.h"
#include "lexeme.h"
#include "symbol.h"

class Tokenizer
{
	private:
		int nline = 1;
		class Lexer lex;
		class Lexeme lexeme;
		std::vector<Symbol> symbol_table;
		std::vector<int> num_table;

		int bin2Dec(string b);
		int hex2Dec(string h);
	public:
		void annotateSymbolNodes(int id, vector<int> nodes);
		vector<int> dec2Bin(unsigned int d, 
								unsigned int expc_width);
		bool isSymbolUsed(int id);
		bool getNext(class Token &token);
		vector<int> getNodes(int id);
		int getNLine(void);
		void lockSymbol(int id);
		int numFindPush(int c);
		int getNum(int id);
		std::string getSymbol(int id);
		void print_symbol_table(void);
		void recovery_point();
		void restore();
		void retract(void);
		void set_type(int id, int t);
		void source(std::string name);
		int symbolFindPush(std::string str);
		void unlock_symbol(int id);
};

#endif
