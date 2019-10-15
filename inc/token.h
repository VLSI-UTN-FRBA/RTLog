///////////////////////////////////////////////////////////
// codigo fuente: token.h                                //
// fecha de inicio: 3/12/2017                            //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase tokens para representar tokens de    //
//            codigo RTLog.                              //
//                                                       //
// clase implementada:                                   //
//  Token                                                //
// propiedades:                                          //
//  type - tipo de token.                                //
//  n - clasificacion de token o numero.                 //
// metodos:                                              //
//  Token - constructores ( 2 ).                         //
//  getN - devuelve el atributo.                         //
//  match - comprueba si un token es tiene el id         //
//            solicitado ( 2 sobrecargas ).              //
//  print - muestra un token.                            //
// operadores:                                           //
//  == - compara ( por igual ) 2 tokens.                 //
// clases amigas:                                        //
//  Tokenizer                                            //
///////////////////////////////////////////////////////////

#ifndef __TOKEN_H
#define __TOKEN_H

using namespace std;

#include "tag.h"

class Token
{
	private:
		token_type type;
		int	n;
	public:
		friend class Tokenizer;
		int getN(void);
		Token(void);
		Token(token_type t, int a);
		bool match(token_type t);
		bool match(token_type t, int a);
		void print(void);

		inline bool operator ==(const Token& t)
		{
			if (type != t.type)
			{
				return false;
			}

			// don't care
			if (t.n == -1)
			{
				return true;
			}

			if (n != t.n)
			{
				return false;
			}

			return true;
		}
};

#endif
