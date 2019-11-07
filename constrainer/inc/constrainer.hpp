#ifndef __CONSTRAINER_H
#define __CONSTRAINER_H

#include <stdlib.h>
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

//Clase Constrainer
class Constrainer
{
        private:
                ifstream r2rFile;
                ofstream constFile;
                list<string> r2r_paths;
                list<string>::iterator it;
        public:
                bool files(string,string);
                bool analize();
                bool make(string);
};

//Prototipos de funciones
void usage_constrainer_print(void);

#endif
