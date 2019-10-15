///////////////////////////////////////////////////////////
// codigo fuente: node.h                                 //
// fecha de inicio: 17/11/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: Clase virtual Node y sus clase heredadas   //
//            para representar nodos de grafos.          //
//            Usada para grafos que representan          //
//            circuitos logicos.                         //
//                                                       //
// clase implementada:                                   //
//  Node                                                 //
// clases derivadas:                                     //
//  Adder                                                //
//  AdderCout                                            //
//  And2                                                 //
//  Buf                                                  //
//  CpEq                                                 //
//  CpGEq                                                //
//  CpGr                                                 //
//  CpLEq                                                //
//  CpLw                                                 //
//  CpNeq                                                //
//  FC                                                   //
//  JC                                                   //
//  Latch                                                //
//  LC                                                   //
//  Mult                                                 //
//  Neg                                                  //
//  Not                                                  //
//  PortIn                                               //
//  PortOut                                              //
//  Reg                                                  //
//  Sub                                                  //
//  SubBout                                              //
//  TieHi                                                //
//  TieLo                                                //
//  Xor2                                                 //
//  Xnor2                                                //
// miembros:                                             //
//  id_annotated - anotacion del nombre de bus.          //
//  ix_annotated - anotacion del indice de bus.          //
// metodos:                                              //
//  fullPrint - imprime informacion detallada del nodo.  //
//  getTypeID ( virtual ) - devuelve tipo de nodo.       //
//  get_type_string ( virtual ) - devuelve un string con //
//      el tipo de celda.                                //
//  insertFain - agrega un net de fanin.                 //
//  insertFanout - agrega un net de fanout.              //
//  print - muestra contenido del nodo.                  //
//  queryFanin - consulta fan in.                        //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __NODE_H
#define __NODE_H

using namespace std;

#include <iostream>

#include "net.h"
#include "tag.h"

class Net;

// nodo abstracto
class Node
{
	public:
		virtual void Annotate(int d, int x)
		{
		}
		virtual void Clone(const Node& node)
		{
		}
		virtual void fullPrint(int d)
		{
		}
		virtual int getWidth()
		{
			return 1;
		}
		virtual int getFaninWidth()
		{
			return 1;
		}
		virtual int getFanIn()
		{
			return -1;
		}
		virtual int Get_Id_Annotation()
		{
			return -1;
		}
		virtual int Get_Ix_Annotation()
		{
			return -1;
		}
		virtual int getTypeID()
		{
			return NODE_ID_VOID;
		}
        virtual std::string get_type_string()
        {
            return "";
        }
		virtual void insertFanin(int f)
		{
		}
		virtual void insertFanin(int f, int i)
		{
		}
		virtual void insertFanin(vector<int> bus)
		{
		}
		virtual void insertFanout(int f)
		{
		}
		virtual void insertFanout(vector<int> bus)
		{
		}
		virtual void insertFanout(int f, int i)
		{
		}
		virtual bool is_Output_Bus()
		{
		}
		virtual void print(void)
		{
		}
		virtual int queryFanin(int f)
		{
		}
		virtual int* queryBusFanin(void)
		{
		}
		virtual int* queryBusFanin(int f)
		{
		}
		virtual vector<int> queryFanouts()
		{
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
		}
		~Node()
		{
		}
	private:
		int width;
};

// nodo input port
class PortIn : public Node
{
	public:
		PortIn()
		{
		}
		PortIn(const Node* node)
		{
			fanouts = ((PortIn*)node)->fanouts;		
			id_annotated = ((PortIn*)node)->id_annotated;
			ix_annotated = ((PortIn*)node)->ix_annotated;
		}
		virtual void Annotate(int d, int x)
		{
			id_annotated = d;
			ix_annotated = x;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Input Port: " << d << endl;
			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int Get_Id_Annotation()
		{
			return id_annotated;
		}
		virtual int Get_Ix_Annotation()
		{
			return ix_annotated;
		}
		virtual int getTypeID()
		{
			return NODE_ID_PORTIN;
		}
        virtual std::string get_type_string()
        {
            return "Port In";
        }
		virtual void insertFanin(int f)
		{
			cout << "[ERROR] input port cannot be driven by any net."
				 << endl;
			exit(1);
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Input Port " << endl;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~PortIn()
		{
			fanouts.clear();
		}
	private:
		vector<int> fanouts;
		int id_annotated;
		int ix_annotated;
};

// nodo output port
class PortOut : public Node
{
	public:
		PortOut()
		{
		}
		PortOut(const Node* node)
		{
			fanin = ((PortOut*)node)->fanin;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Output Port: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin: " << fanin << endl;

 			cout << endl << endl;
		}
		virtual int getFanIn()
		{
			return fanin;
		}
		virtual int getTypeID()
		{
			return NODE_ID_PORTOUT;
		}
        virtual std::string get_type_string()
        {
            return "Port Out";
        }
		virtual void insertFanin(int f)
		{
			if (fanin == -1)
			{
				fanin = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for output port."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			cout << "[ERROR] Output port can't drive nets."
				 << endl;
			exit(1);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Output Port " << endl;
		}
		virtual int queryFanin(int f)
		{
			return fanin;
		}
		~PortOut()
		{
		}
	private:
		int fanin = -1;
};

// nodo add
class Adder : public Node
{
	public:
		Adder()
		{
		}
		Adder(const Node* node)
		{
			width = ((Adder*)node)->width;

			// deep copy fanin_1
			if (((Adder*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((Adder*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((Adder*)node)->fanin_2)
			{
				fanin_2 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((Adder*)node)->fanin_2)[i];
				}
			}

			fanouts = ((Adder*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Adder: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width;
		}
		virtual int getTypeID()
		{
			return NODE_ID_ADD;
		}
        virtual std::string get_type_string()
        {
            return "Adder";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for adder."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for adder."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return true;
		}
		virtual void print(void)
		{
			cout << "Adder" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~Adder()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		std::vector<std::vector<int>> fanouts;
};

// nodo add cout
class AdderCout : public Node
{
	public:
		AdderCout()
		{
		}
		AdderCout(const Node* node)
		{
			width = ((AdderCout*)node)->width;

			// deep copy fanin_1
			if (((AdderCout*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((AdderCout*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((AdderCout*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((AdderCout*)node)->fanin_2)[i];
				}
			}

			fanouts = ((AdderCout*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Adder Cout: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width + 1;
		}
		virtual int getTypeID()
		{
			return NODE_ID_ADDCOUT;
		}
        virtual std::string get_type_string()
        {
            return "Adder Cout";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for adder cout."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for adder cout."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return true;
		}
		virtual void print(void)
		{
			cout << "Adder Cout" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~AdderCout()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		std::vector<std::vector<int>> fanouts;
};

// nodo and2
class And2 : public Node
{
	public:
		And2()
		{
		}
		And2(const Node* node)
		{
			fanin_1 = ((And2*)node)->fanin_1;
			fanin_2 = ((And2*)node)->fanin_2;
			fanouts = ((And2*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "And2 Gate: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin 1: " << fanin_1 << endl;
			cout << "Fanin 2: " << fanin_2 << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_AND2;
		}
        virtual std::string get_type_string()
        {
            return "And2";
        }
		virtual void insertFanin(int f)
		{
			if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for and gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "And Gate 2 " << endl;
		}
		virtual int queryFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~And2()
		{
			fanouts.clear();
		}
	private:
		int fanin_1 = -1;
		int fanin_2 = -1;
		std::vector<int> fanouts;
};

// nodo buffer
class Buf : public Node
{
	public:
		Buf()
		{
		}
		Buf(const Node* node)
		{
			fanin = ((Buf*)node)->fanin;
			fanouts = ((Buf*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Buffer gate: " << d << endl;

			cout << "Fanin:" << endl;
			cout << "Fanin: " << fanin << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_BUF;
		}
        virtual std::string get_type_string()
        {
            return "Buffer";
        }
		virtual void insertFanin(int f)
		{
			if (fanin == -1)
			{
				fanin = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for buffer gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Buffer " << endl;
		}
		virtual int queryFanin(int f)
		{
			return fanin;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Buf()
		{
			fanouts.clear();
		}
	private:
		int fanin = -1;
		vector<int> fanouts;
};

// nodo cpeq
class CpEq : public Node
{
	public:
		CpEq()
		{
		}
		CpEq(const Node* node)
		{
			width = ((CpEq*)node)->width;

			// deep copy fanin_1
			if (((CpEq*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpEq*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpEq*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpEq*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpEq*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Equal Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPEQ;
		}
        virtual std::string get_type_string()
        {
            return "CpEq";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for equal comparator inputs."
						 << endl;
					cout << f.size() << " " << width << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for equal comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Comparator Equal" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpEq()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo cpgeq
class CpGEq : public Node
{
	public:
		CpGEq()
		{
		}
		CpGEq(const Node* node)
		{
			width = ((CpGEq*)node)->width;

			// deep copy fanin_1
			if (((CpGEq*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpGEq*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpGEq*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpGEq*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpGEq*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Greater or Equal Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPGEQ;
		}
        virtual std::string get_type_string()
        {
            return "CpGEq";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for greater or equal comparator inputs."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for greater comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Greater or Equal Comparator" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpGEq()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo cpgr
class CpGr : public Node
{
	public:
		CpGr()
		{
		}
		CpGr(const Node* node)
		{
			width = ((CpGr*)node)->width;

			// deep copy fanin_1
			if (((CpGr*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpGr*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpGr*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpGr*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpGr*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Greater Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPGR;
		}
        virtual std::string get_type_string()
        {
            return "CpGr";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for greater comparator inputs."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for greater comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Greater Comparator" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpGr()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo cpLeq
class CpLEq : public Node
{
	public:
		CpLEq()
		{
		}
		CpLEq(const Node* node)
		{
			width = ((CpLEq*)node)->width;

			// deep copy fanin_1
			if (((CpLEq*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpLEq*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpLEq*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpLEq*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpLEq*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Lower or Equal Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPLEQ;
		}
        virtual std::string get_type_string()
        {
            return "CpLEq";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for lower or equal comparator inputs."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for lower or equal comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Lower or Equal Comparator" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpLEq()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo cplw
class CpLw : public Node
{
	public:
		CpLw()
		{
		}
		CpLw(const Node* node)
		{
			width = ((CpLw*)node)->width;

			// deep copy fanin_1
			if (((CpLw*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpLw*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpLw*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpLw*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpLw*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Lower Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPLW;
		}
        virtual std::string get_type_string()
        {
            return "CpLw";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for lower comparator inputs."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for lower comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Lower Comparator" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpLw()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo cpneq
class CpNeq : public Node
{
	public:
		CpNeq()
		{
		}
		CpNeq(const Node* node)
		{
			width = ((CpNeq*)node)->width;

			// deep copy fanin_1
			if (((CpNeq*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((CpNeq*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((CpNeq*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((CpNeq*)node)->fanin_2)[i];
				}
			}

			fanouts = ((CpNeq*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Non Equal Comparator: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}
 			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_CPNEQ;
		}
        virtual std::string get_type_string()
        {
            return "CpNEq";
        }
		virtual int getFaninWidth()
		{
			return width;
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for non equal comparator inputs."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for non equal comparator input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Non Equal Comparator" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~CpNeq()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<int> fanouts;
};

// nodo Fork Controller
class FC : public Node
{
	public:
		FC()
		{
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			std::cout << "Fork Controller: " << d << std::endl;

			std::cout << std::endl;
			std::cout << "Right Request 1: " << r_Req_1;
			std::cout << std::endl;
			std::cout << "Right Acknowledge 1: " << r_Ack_1;
			std::cout << std::endl;
			std::cout << "Right Request 2: " << r_Req_2;
			std::cout << std::endl;
			std::cout << "Right Acknowledge 2: " << r_Ack_2;
			std::cout << std::endl;
			std::cout << "Left Request: " << l_Req;
			std::cout << std::endl;
			std::cout << "Left Acknowledge: " << l_Ack;
			std::cout << std::endl;

			std::cout << std::endl << std::endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_FC;
		}
        virtual std::string get_type_string()
        {
            return "ForkCtr";
        }
		virtual void insertFanin(int f, int i)
		{
			switch (i)
			{
				case FAN_REQ_LEFT:
					l_Req = f;
					break;
				case FAN_ACK_LEFT:
					break;
				case FAN_REQ_LEFT_2:
					break;
				case FAN_ACK_RIGHT_1:
					r_Ack_1 = f;
					break;
				case FAN_REQ_RIGHT:
					break;
				case FAN_ACK_RIGHT_2:
					r_Ack_2 = f;
					break;
			}
		}
		virtual void insertFanout(int f, int i)
		{
			switch (i)
			{
				case FAN_REQ_RIGHT_1:
					r_Req_1 = f;
					break;
				case FAN_ACK_LEFT:
					l_Ack = f;
					break;
				case FAN_REQ_RIGHT_2:
					r_Req_2 = f;
					break;
				case FAN_ACK_LEFT_2:
					break;
				case FAN_REQ_RIGHT:
					break;
				case FAN_ACK_RIGHT:
					break;
			}
		}
		virtual void print(void)
		{
			cout << "Fork Controller " << endl;
		}
		virtual int queryFanin(int f)
		{
			switch (f)
			{
				case FAN_REQ_LEFT:
					return l_Req;
					break;
				case FAN_ACK_LEFT:
					return l_Ack;
					break;
				case FAN_REQ_RIGHT_1:
					return r_Req_1;
					break;
				case FAN_ACK_RIGHT_1:
					return r_Ack_1;
					break;
				case FAN_REQ_RIGHT_2:
					return r_Req_2;
					break;
				case FAN_ACK_RIGHT_2:
					return r_Ack_2;
					break;

			}
		}
		~FC()
		{
		}
	private:
		int r_Req_1 = -1;
		int r_Ack_1 = -1;
		int r_Req_2 = -1;
		int r_Ack_2 = -1;
		int l_Req = -1;
		int l_Ack = -1;
};

// nodo Join Controller
class JC : public Node
{
	public:
		JC()
		{
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Join Controller: " << d << endl;

			std::cout << std::endl;
			std::cout << "Left Request 1: " << l_Req_1;
			std::cout << std::endl;
			std::cout << "Left Acknowledge 1: " << l_Ack_1;
			std::cout << std::endl;
			std::cout << "Left Request 2: " << l_Req_2;
			std::cout << std::endl;
			std::cout << "Left Acknowledge 2: " << l_Ack_2;
			std::cout << std::endl;
			std::cout << "Right Request: " << r_Req;
			std::cout << std::endl;
			std::cout << "Right Acknowledge: " << r_Ack;
			std::cout << std::endl;

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_JC;
		}
        virtual std::string get_type_string()
        {
            return "JoinCtr";
        }
		virtual void insertFanin(int f, int i)
		{
			switch (i)
			{
				case FAN_REQ_LEFT_1:
					l_Req_1 = f;
					break;
				case FAN_ACK_LEFT_1:
					break;
				case FAN_REQ_LEFT_2:
					l_Req_2 = f;
					break;
				case FAN_ACK_LEFT_2:
					break;
				case FAN_REQ_RIGHT:
					break;
				case FAN_ACK_RIGHT:
					r_Ack = f;
					break;
			}
		}
		virtual void insertFanout(int f, int i)
		{
			switch (i)
			{
				case FAN_REQ_LEFT_1:
					break;
				case FAN_ACK_LEFT_1:
					l_Ack_1 = f;
					break;
				case FAN_REQ_LEFT_2:
					break;
				case FAN_ACK_LEFT_2:
					l_Ack_2 = f;
					break;
				case FAN_REQ_RIGHT:
					r_Req = f;
					break;
				case FAN_ACK_RIGHT:
					break;
			}
		}
		virtual void print(void)
		{
			cout << "Join Controller " << endl;
		}
		virtual int queryFanin(int f)
		{
			switch (f)
			{
				case FAN_REQ_LEFT_1:
					return l_Req_1;
				case FAN_ACK_LEFT_1:
					return l_Ack_1;
				case FAN_REQ_LEFT_2:
					return l_Req_2;
				case FAN_ACK_LEFT_2:
					return l_Ack_2;
				case FAN_REQ_RIGHT:
					return r_Req;
				case FAN_ACK_RIGHT:
					return r_Ack;
			}
		}
		~JC()
		{
		}
	private:
		int l_Req_1 = -1;
		int l_Ack_1 = -1;
		int l_Req_2 = -1;
		int l_Ack_2 = -1;
		int r_Req = -1;
		int r_Ack = -1;
};


// nodo latch
class Latch : public Node
{
	public:
		Latch()
		{
		}
		Latch(int fin, std::vector<int> fout, int id, int ix)
		{
			fanin = fin;
			fanouts = fout;
			id_annotated = id;
			ix_annotated = ix;
		}
		virtual void Annotate(int d, int x)
		{
			id_annotated = d;
			ix_annotated = x;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Latch: " << d << endl;

			cout << "Annotations: " << endl;
			cout << "Name id: " << id_annotated << endl;
			cout << "index: " << ix_annotated << endl;

			cout << "Fanin:" << endl;
			cout << "Fanin: " << fanin << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			std::cout << "Latch enable: " << le << std::endl;

			std::cout << std::endl << std::endl;
		}
		virtual int Get_Id_Annotation()
		{
			return id_annotated;
		}
		virtual int Get_Ix_Annotation()
		{
			return ix_annotated;
		}
		virtual int getTypeID()
		{
			return NODE_ID_LATCH;
		}
        virtual std::string get_type_string()
        {
            return "Latch";
        }
		virtual void insertFanin(int f)
		{
			if (fanin == -1)
			{
				fanin = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for register data input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanin(int f, int i)
		{
			// i = 1 => Latch enable
			if (i == 1)
			{
				le = f;
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Latch " << endl;
		}
		virtual int queryFanin(int f)
		{
			switch (f)
			{
				case FAN_LE:
					return le;
				default:
					return fanin;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Latch()
		{
			fanouts.clear();
		}
	private:
		int id_annotated;
		int ix_annotated;
		int fanin = -1;
		int le = -1;
		vector<int> fanouts;
};


// nodo Latch Controller
class LC : public Node
{
	public:
		LC()
		{
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Latch Controller: " << d << endl;

			std::cout << "Latch enable: " << std::endl;

			for (auto &net : le)
			{
				std::cout << i++ << "\t" << "net ";
				std::cout << net << std::endl;
			}

			std::cout << std::endl;
			std::cout << "Left Request: " << l_Req;
			std::cout << std::endl;
			std::cout << "Left Acknowledge: " << l_Ack;
			std::cout << std::endl;
			std::cout << "Right Request: " << r_Req;
			std::cout << std::endl;
			std::cout << "Right Acknowledge: " << r_Ack;
			std::cout << std::endl;

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_LC;
		}
        virtual std::string get_type_string()
        {
            return "LatchCtr";
        }
		virtual void insertFanin(int f, int i)
		{
			// i = FAN_REQ_LEFT => Request left
			// i = FAN_ACK_RIGHT => Acknowledge right
			if (i == FAN_REQ_LEFT)
			{
				l_Req = f;
			}
			else if (i == FAN_ACK_RIGHT)
			{
				r_Ack = f;
			}
		}
		virtual void insertFanout(int f, int i)
		{
			// i = FAN_LE => Latch enable
			// i = FAN_REQ_RIGHT => Request right
			// i = FAN_ACK_LEFT => Acknowledge left
			if (i == FAN_LE)
			{
				le.push_back(f);
			}
			else if (i == FAN_REQ_RIGHT)
			{
				r_Req = f;
			}
			else if (i == FAN_ACK_LEFT)
			{
				l_Ack = f;
			}
		}
		virtual void print(void)
		{
			cout << "Latch Controller " << endl;
		}
		virtual int queryFanin(int f)
		{
			switch (f)
			{
				case FAN_REQ_LEFT:
					return l_Req;
				case FAN_ACK_LEFT:
					return l_Ack;
				case FAN_REQ_RIGHT:
					return r_Req;
				case FAN_ACK_RIGHT:
					return r_Ack;
				default:
					return l_Req;
			}
		}
		virtual std::vector<int> queryFanouts(void)
		{
			return le;
		}
		~LC()
		{
		}
	private:
		std::vector<int> le;
		int l_Req = -1;
		int l_Ack = -1;
		int r_Req = -1;
		int r_Ack = -1;	
};


// nodo neg
class Neg : public Node
{
	public:
		Neg()
		{
		}
		Neg(const Node* node)
		{
			width = ((Neg*)node)->width;

			// deep copy fanin_1
			if (((Neg*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((Neg*)node)->fanin_1)[i];
				}
			}

			fanouts = ((Neg*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Negate " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width;
		}
		virtual int getTypeID()
		{
			return NODE_ID_NEG;
		}
        virtual std::string get_type_string()
        {
            return "Neg";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for negate."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Negate" << endl;
		}
		virtual int* queryBusFanin(void)
		{
			return fanin_1;
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~Neg()
		{
			delete fanin_1;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int width = -1;
		std::vector<std::vector<int>> fanouts;
};

// nodo mult
class Mult : public Node
{
	public:
		Mult()
		{
		}
		Mult(const Node* node)
		{
			width = ((Mult*)node)->width;

			// deep copy fanin_1
			if (((Mult*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((Mult*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((Mult*)node)->fanin_2)
			{
				fanin_2 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((Mult*)node)->fanin_2)[i];
				}
			}

			fanouts = ((Mult*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Multiplier: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width * 2;
		}
		virtual int getTypeID()
		{
			return NODE_ID_MULT;
		}
        virtual std::string get_type_string()
        {
            return "Mult";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for multiplier."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for multiplier."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return true;
		}
		virtual void print(void)
		{
			cout << "Multiplier" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~Mult()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<vector<int>> fanouts;
};

// nodo mux2
class Mux2 : public Node
{
	public:
		Mux2()
		{
		}
		Mux2(const Node* node)
		{
			fanin_1 = ((Mux2*)node)->fanin_1;
			fanin_2 = ((Mux2*)node)->fanin_2;
			fanin_s = ((Mux2*)node)->fanin_s;
			fanouts = ((Mux2*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Mux2: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin 1: " << fanin_1 << endl;
			cout << "Fanin 2: " << fanin_2 << endl;
			cout << "Fanin s: " << fanin_s << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_MUX2;
		}
        virtual std::string get_type_string()
        {
            return "Mux2";
        }
		virtual void insertFanin(int f)
		{
			if (fanin_s == -1)
			{
				fanin_s = f;
			}
			else if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for mux2 input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Mux 2 " << endl;
		}
		virtual int queryFanin(int f)
		{
			if (f == 0)
			{
				return fanin_s;
			}
			else if (f == 1)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Mux2()
		{
			fanouts.clear();
		}
	private:
		int fanin_1 = -1;
		int fanin_2 = -1;
		int fanin_s = -1;
		std::vector<int> fanouts;
};

// nodo muxN
class MuxN : public Node
{
	public:
		MuxN()
		{
		}
		MuxN(const Node* node)
		{
			width = ((MuxN*)node)->width;

			// deep copy fanin
			if (((MuxN*)node)->fanin)
			{
				fanin = new int[pow2(width)];

				for (int i = 0; i < pow2(width); i++)
				{
					fanin[i] = (((MuxN*)node)->fanin)[i];
				}
			}

			// deep copy fanin_s
			if (((MuxN*)node)->fanin_s)
			{
				fanin_s = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_s[i] = (((MuxN*)node)->fanin_s)[i];
				}
			}

			fanouts = ((MuxN*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "MuxN: " << d << endl;

			cout << "Fanins:" << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_s[i] << endl;
			}

			cout << "Fanin d: "<< endl;

			for (i = 0; i < pow2(width); i++)
			{
				cout << i << "\t" << "net " << fanin[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_MUXN;
		}
        virtual std::string get_type_string()
        {
            return "MuxN";
        }
		virtual void insertFanin(int f)
		{
/*			if (fanin_s == -1)
			{
				fanin_s = f;
			}
			else if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for muxN input."
					 << endl;
				exit(1);
			}*/
		}
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_s == NULL)
			{
				fanin_s = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_s[i++] = net;
				}

				fanin = new int[pow2(width)];

				for (i = 0; i < pow2(width); i++)
				{
					fanin[i] = -1;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for MuxN."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanin(int f, int i)
		{
			if (fanin[i] == -1)
			{
				fanin[i] = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for MuxN."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Mux N " << endl;
		}
		~MuxN()
		{
			fanouts.clear();
			delete fanin;
			delete fanin_s;
		}
	private:
		int width;
		int* fanin;
		int* fanin_s;
		std::vector<int> fanouts;
		int pow2(int x) const 
		{
			int i = 0;
			int y = 1;

			for (i = 0; i < x; i++)
			{
				y = y << 1;
			}

			return y;
		};
};

// nodo not
class Not : public Node
{
	public:
		Not()
		{
		}
		Not(const Node* node)
		{
			fanin = ((Not*)node)->fanin;
			fanouts = ((Not*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Not gate: " << d << endl;

			cout << "Fanin:" << endl;
			cout << "Fanin: " << fanin << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_NOT;
		}
        virtual std::string get_type_string()
        {
            return "Not";
        }
		virtual void insertFanin(int f)
		{
			if (fanin == -1)
			{
				fanin = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for not gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Not " << endl;
		}
		virtual int queryFanin(int f)
		{
			return fanin;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Not()
		{
			fanouts.clear();
		}
	private:
		int fanin = -1;
		std::vector<int> fanouts;
};

// nodo or2
class Or2 : public Node
{
	public:
		Or2()
		{
		}
		Or2(const Node* node)
		{
			fanin_1 = ((Or2*)node)->fanin_1;
			fanin_2 = ((Or2*)node)->fanin_2;
			fanouts = ((Or2*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Or2 Gate: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin 1: " << fanin_1 << endl;
			cout << "Fanin 2: " << fanin_2 << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_OR2;
		}
        virtual std::string get_type_string()
        {
            return "Or2";
        }
		virtual void insertFanin(int f)
		{
			if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for or gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Or Gate 2 " << endl;
		}
		virtual int queryFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Or2()
		{
			fanouts.clear();
		}
	private:
		int fanin_1 = -1;
		int fanin_2 = -1;
		vector<int> fanouts;
};

// nodo reg
class Reg : public Node
{
	public:
		Reg()
		{
		}
		Reg(const Node* node)
		{
			fanin = ((Reg*)node)->fanin;
			fanouts = ((Reg*)node)->fanouts;
			id_annotated = ((Reg*)node)->id_annotated;
			ix_annotated = ((Reg*)node)->ix_annotated;
		}
		virtual void Annotate(int d, int x)
		{
			id_annotated = d;
			ix_annotated = x;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Register: " << d << endl;

			cout << "Annotations: " << endl;
			cout << "Name id: " << id_annotated << endl;
			cout << "index: " << ix_annotated << endl;

			cout << "Fanin:" << endl;
			cout << "Fanin: " << fanin << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int Get_Id_Annotation()
		{
			return id_annotated;
		}
		virtual int Get_Ix_Annotation()
		{
			return ix_annotated;
		}
		virtual int getTypeID()
		{
			return NODE_ID_REG;
		}
        virtual std::string get_type_string()
        {
            return "Reg";
        }
		virtual void insertFanin(int f)
		{
			if (fanin == -1)
			{
				fanin = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for register data input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Reg " << endl;
		}
		virtual int queryFanin(int f)
		{
			return fanin;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Reg()
		{
			fanouts.clear();
		}
	private:
		int id_annotated;
		int ix_annotated;
		int fanin = -1;
		vector<int> fanouts;
};

// nodo sub
class Sub : public Node
{
	public:
		Sub()
		{
		}
		Sub(const Node* node)
		{
			width = ((Sub*)node)->width;

			// deep copy fanin_1
			if (((Sub*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((Sub*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((Sub*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((Sub*)node)->fanin_2)[i];
				}
			}

			fanouts = ((Sub*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Substractor: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width;
		}
		virtual int getTypeID()
		{
			return NODE_ID_SUB;
		}
        virtual std::string get_type_string()
        {
            return "Sub";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for substractor."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for substractor."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Substractor" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~Sub()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<vector<int>> fanouts;
};

// nodo sub bout
class SubBout : public Node
{
	public:
		SubBout()
		{
		}
		SubBout(const Node* node)
		{
			width = ((SubBout*)node)->width;

			// deep copy fanin_1
			if (((SubBout*)node)->fanin_1)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_1[i] = (((SubBout*)node)->fanin_1)[i];
				}
			}

			// deep copy fanin_2
			if (((SubBout*)node)->fanin_2)
			{
				fanin_1 = new int[width];

				for (int i = 0; i < width; i++)
				{
					fanin_2[i] = (((SubBout*)node)->fanin_2)[i];
				}
			}

			fanouts = ((SubBout*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Substractor Bout: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin bus 1: " << endl;
			
			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_1[i] << endl;
			}

			i = 0;

			cout << "Fanin bus 2: " << endl;

			for (i = 0; i < width; i++)
			{
				cout << i << "\t" << "net " << fanin_2[i] << endl;
			}

			i = 0;

			cout << "Fanouts:" << endl;

			for (auto &v : fanouts)
			{
				for (auto &net : v)
				{
					cout << i++ << "\t" << "net " << net << endl;
				}
			}
 			cout << endl << endl;
		}
		virtual int getWidth()
		{
			return width + 1;
		}
		virtual int getTypeID()
		{
			return NODE_ID_SUBBOUT;
		}
        virtual std::string get_type_string()
        {
            return "Sub Bout";
        }
		virtual void insertFanin(vector<int> f)
		{
			int i = 0;

			if (fanin_1 == NULL)
			{
				fanin_1 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_1[i++] = net;
				}
			}
			else if (fanin_2 == NULL)
			{
				if (f.size() != width)
				{
					cout << "[ERROR] Width mismatch for substractor bout."
						 << endl;
					exit(1);
				}

				fanin_2 = new int[f.size()];

				fanin_2 = new int[f.size()];
				width = f.size();

				for (auto &net : f)
				{
					fanin_2[i++] = net;
				}
			}
			else
			{
				cout << "[ERROR] Multiple drivers for substractor bout."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(vector<int> f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Substractor Bout" << endl;
		}
		virtual int* queryBusFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<vector<int>> queryBusFanouts(void)
		{
			return fanouts;
		}
		~SubBout()
		{
			delete fanin_1;
			delete fanin_2;
			fanouts.clear();
		}
	private:
		int *fanin_1 = NULL;
		int *fanin_2 = NULL;
		int width = -1;
		vector<vector<int>> fanouts;
};

// nodo tie hi
class TieHi : public Node
{
	public:
		TieHi()
		{
		}
		TieHi(const Node* node)
		{
			fanouts = ((TieHi*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Tie Hi: " << d << endl;
			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_TIEHI;
		}
        virtual std::string get_type_string()
        {
            return "TieHi";
        }
		virtual void insertFanin(int f)
		{
			cout << "[ERROR] Tie Hi cannot be driven by any net."
				 << endl;
			exit(1);
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "TieHi " << endl;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~TieHi()
		{
			fanouts.clear();
		}
	private:
		vector<int> fanouts;
};

// nodo tie lo
class TieLo : public Node
{
	public:
		TieLo()
		{
		}
		TieLo(const Node* node)
		{
			fanouts = ((TieLo*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Tie Lo: " << d << endl;
			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_TIELO;
		}
        virtual std::string get_type_string()
        {
            return "TieLo";
        }
		virtual void insertFanin(int f)
		{
			cout << "[ERROR] Tie Lo cannot be driven by any net."
				 << endl;
			exit(1);
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Tie Lo " << endl;
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~TieLo()
		{
			fanouts.clear();
		}
	private:
		vector<int> fanouts;
};

// nodo xor2
class Xor2 : public Node
{
	public:
		Xor2()
		{
		}
		Xor2(const Node* node)
		{
			fanin_1 = ((Xor2*)node)->fanin_1;
			fanin_2 = ((Xor2*)node)->fanin_2;
			fanouts = ((Xor2*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Xor2 Gate: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin 1: " << fanin_1 << endl;
			cout << "Fanin 2: " << fanin_2 << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_XOR2;
		}
        virtual std::string get_type_string()
        {
            return "Xor2";
        }
		virtual void insertFanin(int f)
		{
			if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for xor gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Xor Gate 2 " << endl;
		}
		virtual int queryFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Xor2()
		{
			fanouts.clear();
		}
	private:
		int fanin_1 = -1;
		int fanin_2 = -1;
		vector<int> fanouts;
};

// nodo xnor2
class Xnor2 : public Node
{
	public:
		Xnor2()
		{
		}
		Xnor2(const Node* node)
		{
			fanin_1 = ((Xnor2*)node)->fanin_1;
			fanin_2 = ((Xnor2*)node)->fanin_2;
			fanouts = ((Xnor2*)node)->fanouts;
		}
		virtual void fullPrint(int d)
		{
			int i = 0;

			cout << "Xnor2 Gate: " << d << endl;

			cout << "Fanins:" << endl;
			cout << "Fanin 1: " << fanin_1 << endl;
			cout << "Fanin 2: " << fanin_2 << endl;

			cout << "Fanouts:" << endl;

			for (auto &net : fanouts)
			{
				cout << i++ << "\t" << "net " << net << endl;
			}

			cout << endl << endl;
		}
		virtual int getTypeID()
		{
			return NODE_ID_XNOR2;
		}
        virtual std::string get_type_string()
        {
            return "Xnor2";
        }
		virtual void insertFanin(int f)
		{
			if (fanin_1 == -1)
			{
				fanin_1 = f;
			}
			else if (fanin_2 == -1)
			{
				fanin_2 = f;
			}
			else
			{
				cout << "[ERROR] Multiple drivers for xnor gate input."
					 << endl;
				exit(1);
			}
		}
		virtual void insertFanout(int f)
		{
			fanouts.push_back(f);
		}
		virtual bool is_Output_Bus()
		{
			return false;
		}
		virtual void print(void)
		{
			cout << "Xnor Gate 2 " << endl;
		}
		virtual int queryFanin(int f)
		{
			if (f == 0)
			{
				return fanin_1;
			}
			else
			{
				return fanin_2;
			}
		}
		virtual vector<int> queryFanouts(void)
		{
			return fanouts;
		}
		~Xnor2()
		{
			fanouts.clear();
		}
	private:
		int fanin_1 = -1;
		int fanin_2 = -1;
		vector<int> fanouts;
};


#endif
