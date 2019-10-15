///////////////////////////////////////////////////////////
// codigo fuente: net.h                                  //
// fecha de inicio: 17/11/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase virtual Net para representar         //
//            segmentos de grafos.                       //
//            Usada para grafos que representan          //
//            circuitos logicos.                         //
//                                                       //
// clase implementada:                                   //
//  Net                                                  //
// propiedades:                                          //
//  tail - cola del segmento. Indice a la lista de       //
//         nodos.                                        //
//  head - cabeza del segmento. Indice a la lista de     //
//         nodos.                                        //
// metodos:                                              //
//  Net - constructor ( 4 constructores ).               //
//  connect - completa la cabeza de un net.              //
//  print - muestra las puntas del segemento.            //
//  queryHead - devuelve cabeza del segmento.            //
//  queryTail - devuelve cola del segmento.              //
//  ~Net - destructor.                                   //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __NET_H
#define __NET_H

class Net
{
	public:
		Net(void)
		{
			// net desconectado
			// ( asignado a un nodo invalido )
			head = -1;
			tail = -1;
		};
		Net(int t)
		{
			head = -1;
			tail = t;
		};
		Net(int h, int t)
		{
			head = h;
			tail = t;
		};
		Net(Net *w)
		{
			tail = w->tail;			
			head = w->head;
		}
		void connect(int h)
		{
			head = h;
		}
		void print(void)
		{
			std::cout << tail << " -> " << head << std::endl;
		}
		int queryHead(void)
		{
			return head;
		}
		int queryTail(void)
		{
			return tail;
		}
		~Net()
		{
		}
	private:
		int tail;
		int head;
};

#endif
