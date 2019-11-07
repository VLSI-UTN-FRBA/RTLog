using namespace std;

#include "constrainer.hpp"

int main(int argc, char *argv[])
{

        class Constrainer constrainer;
        bool retorno;

        //Primero, tratemos a esto como un programa aparte que lo llama el otro
        //Nos pasa un archivo que contiene pares de registros
        if (argc != 4)
        {
                usage_constrainer_print();
                return 1; //error, mejorar
        }

        //Creamos el archivo que nos pasaron por linea de comandos
        retorno = constrainer.files(argv[1],argv[2]);
        if (retorno == false)
        {
                cout << "Failed: file creation" << "\n";
                return 1;
        }
        cout << "File opened" << "\n";

        //este metodo me devuelve una lista de caminos R2R
        //que es un miembro de la clase Constrainer
        //por ahora son strings, despues vemos
        retorno = constrainer.analize();
        if (retorno == false)
        {
                cout << "Failed: R2R paths analysis" << "\n";
                return 1;
        }

// vamos con otro metodo, que agarre la lista y haga todas las constraints
        constrainer.make(argv[3]);

  return 0;
}

///////////////////////////////////////////////////////////
// funcion: usage_constrainer_print                      //
// proposito: mostrar mensaje de modo de uso del         //
//            programa.                                  //
// argumentos:                                           //
//  ninguno.                                             //
// devuelve:                                             //
//  nada                                                 //
///////////////////////////////////////////////////////////

void usage_constrainer_print(void)
{
	cout << "Use: ./constrainer file_r2r file_const top_name" << endl;
}

//Metodos de constrainer
bool Constrainer::files(std::string filename_r2r,std::string filename_const)
{
        r2rFile.open(filename_r2r.c_str());
        if(r2rFile.is_open())
        {
                constFile.open(filename_const.c_str(), ios::trunc);
                if(constFile.is_open()) return true;
                else return false;
        }
        else return false;
}

bool Constrainer::analize(void)
{
        //TODO: cargar en r2r_paths lo que tenga el archivo r2rFile
        string path;
        while (getline (r2rFile,path))
        {
          r2r_paths.push_back(path);
        }
        r2rFile.close();
        //mostrar los caminos levantados
        for (it=r2r_paths.begin(); it!=r2r_paths.end(); ++it)
                cout << *it << "\n";
        cout << '\n';

        return true;
}

bool Constrainer::make(string top_name)
{
        //no recibo nada porque trabajo sobre la lista que es private de la Clase

        //Aca van las constraints que van siempre
        constFile << "####Constraints que van siempre####" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30440]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30441]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30442]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30443]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30444]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30445]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30446]" << "\n";
        constFile << "set_size_only -all_instances [find -hier cell C300R30447]" << "\n";
        constFile << "set_disable_timing -from A2 -to Y [find -hier cell C300R30440]" << "\n";
        constFile << "set_disable_timing -from B1 -to Y [find -hier cell C300R30440]" << "\n";
        constFile << "set_disable_timing -from A1 -to Y [find -hier cell C300R30442]" << "\n";
        constFile << "set_disable_timing -from A2 -to Y [find -hier cell C300R30442]" << "\n";
        constFile << "set_disable_timing -from B0 -to Y [find -hier cell C300R30442]" << "\n";
        constFile << "set_disable_timing -from B1 -to Y [find -hier cell C300R30442]" << "\n";
        constFile << "\n\n";

        constFile << "####Constraints que dependen de R2R####" << "\n";
        string r2r;
        string startpoint;
        string endpoint;
        string set_max = "set_max_delay ";
        string set_min = "set_min_delay ";
        string f = " -from ";
        string t = " -to ";
        string enable_latch = "/G";
        string q_latch = "/Q";
        string d_latch = "/D";
        string nombre_latch = "/LATCH*";
        string max_delay = "0.500"; //primer approach
        string min_delay = "0.150"; //primer approach

        //Aca van las constraints asociadas a los R2R
        for (it=r2r_paths.begin(); it!=r2r_paths.end(); ++it)
        {
          //cout << *it << "\n";
          r2r = *it;

          size_t separador,salto;
          separador = r2r.find(",");
          salto = r2r.find("\n");
          startpoint=r2r.substr(0,separador);
          endpoint=r2r.substr(separador+1,salto);


          //cout << "primer pos " << r2r[0] << "\n";
          //startpoint = r2r[0];
          //cout << "segunda pos " << r2r[2] << "\n";
          //endpoint = r2r[2];

          constFile << "##Constraints for " << startpoint << " ##" << "\n";
          //vamos con los de max:
          //1
          constFile << "#Constraints for " << startpoint << " to itself#" << "\n";
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30442/B1" << "\n";
          //2
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30444/B" << "\n";
          //3
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30440/A0";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30440/B1" << "\n";
          //4
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30440/A0";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30444/A" << "\n";
          //5
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30444/A";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30440/A2" << "\n";
          //6
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30444/A";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30442/A2" << "\n";
          //7
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30444/B";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30440/A2" << "\n";
          //8
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30444/B";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30442/A2" << "\n";

          //vamos con los de min:
          //1
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30444/A";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30440/A2" << "\n";
          //2
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30444/A";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30442/A2" << "\n";
          //3
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30444/B";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30440/A2" << "\n";
          //4
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30444/B";
          constFile << t << top_name << "/lc" << startpoint << "/C300R30442/A2" << "\n\n";

          //hacia el clk
          constFile << "#Constraints for " << startpoint << " to their latchs#" << "\n";
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30440/A0";
          constFile << t << top_name << "/reg" << startpoint << nombre_latch << enable_latch << "\n\n";

          //entre registros
          constFile << "#Constraints for " << startpoint << " to " << endpoint << "#" << "\n";
          //Q a D
          constFile << set_max << max_delay << f << top_name << "/reg" << startpoint << nombre_latch;
          constFile << q_latch << t << top_name << "/reg" << endpoint << nombre_latch << d_latch << "\n\n";

          //1
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A0" << "\n";
          //2
          constFile << set_max << max_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A0" << "\n";

          //1
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A0" << "\n";
          //2
          constFile << set_min << min_delay << f << top_name << "/lc" << startpoint << "/C300R30442/A0";
          constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A0" << "\n\n\n";
        }

        //para el ultimo registro
        constFile << "##Constraints for " << endpoint << " ##" << "\n";
        constFile << "#Constraints for " << endpoint << " to itself#" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30442/A0";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30442/B1" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30442/A0";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30444/B" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30440/A0";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30440/B1" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30440/A0";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30444/A" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30444/A";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A2" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30444/A";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A2" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30444/B";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A2" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30444/B";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A2" << "\n";
        constFile << set_min << min_delay << f << top_name << "/lc" << endpoint << "/C300R30444/A";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A2" << "\n";
        constFile << set_min << min_delay << f << top_name << "/lc" << endpoint << "/C300R30444/A";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A2" << "\n";
        constFile << set_min << min_delay << f << top_name << "/lc" << endpoint << "/C300R30444/B";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30440/A2" << "\n";
        constFile << set_min << min_delay << f << top_name << "/lc" << endpoint << "/C300R30444/B";
        constFile << t << top_name << "/lc" << endpoint << "/C300R30442/A2" << "\n\n";
        constFile << "#Constraints for " << endpoint << " to their latchs#" << "\n";
        constFile << set_max << max_delay << f << top_name << "/lc" << endpoint << "/C300R30440/A0";
        constFile << t << top_name << "/reg" << endpoint << nombre_latch << enable_latch << "\n\n";

        //cierro el archivo
        constFile.close();

	return true;
}
