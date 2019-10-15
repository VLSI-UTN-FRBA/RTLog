/**********************************************************
 * codigo fuente: compiler.cc                             *
 * fecha de inicio: 01/12/2017                            *
 * autor/es:                                              *
 *          Roberto Geronimo Simone                       *
 *                                                        *
 * proposito: Transcompiler de lenguaje RTLog.            *
 *                                                        *
 * uso: ./compile archivo [-c, --clock=CLOCK ]            *
 *                                                        *
 *********************************************************/

#include <iostream>
#include <string>

#include "parser.h"

/* estructura para configurar el informe de compilacion */
union report_t
{
    struct
    {
        unsigned    m_async_graph : 1;
        unsigned    m_cloud_logic : 1;
        unsigned    m_general : 1;
        unsigned    m_graph : 1;
        unsigned    m_i2r_paths : 1;
        unsigned    m_metagraph : 1;
        unsigned    m_r2o_paths : 1;
        unsigned    m_r2r_paths : 1;
    }
    m_bits;

    uint32_t        m_word;
};

/* prototipo de funciones */
bool args_check(int argc,
                char *argv[],
                std::string& filename,
                report_t &report_field);
bool async_check(int argc, char *argv[]);
void usage_print(void);

int main(int argc, char *argv[])
{
	std::string     v_filename;
	class Parser    v_parse;
    report_t        report_field;

    report_field.m_word = 0;

	v_parse.setSync();

	/* mensaje de modo de uso del programa */
	if (argc == 1)
	{
		usage_print();

		return 1;
	}
	/* debe ingresar el nombre del archivo fuente */
	else if (!args_check(argc, argv, v_filename, report_field))
	{
		return 1;
	}
	/* chequeo si es sincronico o no *//*FIXME*/
	else if (async_check(argc, argv))
	{
		v_parse.setAsync();
	}

	v_parse.source(v_filename);

	v_parse.run();

//	v_parse.report(Parser::E_REPORT_GENERAL);
//	v_parse.report(Parser::E_REPORT_GRAPH);

//	v_parse.desync();

	if(v_parse.getClock())/*FIXME*/
	{
		v_parse.desync();
	}

	v_parse.emit();

//	v_parse.desync();

//	v_parse.emit();

    /* informe general */
    if (report_field.m_bits.m_general)
    {
        v_parse.report(Parser::E_REPORT_GENERAL);
    }

    /* informa el grafo */
    if (report_field.m_bits.m_graph)
    {
        v_parse.report(Parser::E_REPORT_GRAPH);
    }

    /* informa el grafo asincronico */
    if (report_field.m_bits.m_async_graph)
    {
        v_parse.report(Parser::E_REPORT_ASYNC_GRAPH);
    }

    /* informa la cloud logic */
    if (report_field.m_bits.m_cloud_logic)
    {
        v_parse.report(Parser::E_REPORT_CLOUD_LOGIC);
    }

    /* informa los caminos i2r */
    if (report_field.m_bits.m_i2r_paths)
    {
        v_parse.report(Parser::E_REPORT_I2R_PATHS);
    }

    /* informa el metagrafo */
    if (report_field.m_bits.m_metagraph)
    {
        v_parse.report(Parser::E_REPORT_METAGRAPH);
    }

    /* informa los caminos r2o */
    if (report_field.m_bits.m_r2o_paths)
    {
        v_parse.report(Parser::E_REPORT_R2O_PATHS);
    }

    /* informa los caminos r2r */
    if (report_field.m_bits.m_r2r_paths)
    {
        v_parse.report(Parser::E_REPORT_R2R_PATHS);
    }
    
	return 0;
}

/**********************************************************
 * funcion: args_check                                    *
 * proposito: interpreta los argumentos ingresados por    *
 *            linea de comandos.                          *
 * argumentos:                                            *
 *  argc - cantidad de argumentos.                        *
 *  *argv[] - vector de argumentos.                       *
 *  filename - archivo fuente rtlog (.rtl)                *
 *  report_field - campo de bits para configurar el       *
 *      informe de compilacion ( por referencia ).        *
 * devuelve:                                              *
 *  true - no hubo errores.                               *
 *  false - hubo errores.                                 *
 *********************************************************/

bool args_check(int argc,
                char *argv[],
                std::string& filename,
                report_t &report_field)
{
	std::string v_str;

	/* recorre todos los argumentos */
	for (int i = 1; i < argc; i++)
	{	
		v_str = std::string(argv[i]);	

		/* --report= */
		if (v_str == "-R")
		{
			i++;

			/* falta tipo de informe */
			if (i >= argc)
			{
				std::cerr << "switch -R sin argumentos";
				std::cerr << std::endl;

				return false;
			}
			else
			{
        		v_str = std::string(argv[i]);

                /* informe anulado */
                if (v_str == "off")
                {
                    report_field.m_word = 0;
                }
                /* informe general */
                else if (v_str == "general")
                {
                    report_field.m_bits.m_general = 1;
                }
                /* informa el grafo */
                else if (v_str == "graph")
                {
                    report_field.m_bits.m_graph = 1;
                }
                /* informa el grafo asincronico */
                else if (v_str == "async-graph")
                {
                    report_field.m_bits.m_async_graph = 1;
                }
                /* informa el metagrafo */
                else if (v_str == "meta-graph")
                {
                    report_field.m_bits.m_metagraph = 1;
                }
                /* informa la cloud logic */
                else if (v_str == "cloud-logic")
                {
                    report_field.m_bits.m_cloud_logic = 1;
                }
                /* informa los caminos i2r */
                else if (v_str == "i2r-paths")
                {
                    report_field.m_bits.m_i2r_paths = 1;
                }
                /* informa los caminos r2o */
                else if (v_str == "r2o-paths")
                {
                    report_field.m_bits.m_r2o_paths = 1;
                }
                /* informa los caminos r2r */
                else if (v_str == "r2r-paths")
                {
                    report_field.m_bits.m_r2r_paths = 1;
                }
			}
		}
		/* archivo fuente */
		else if (filename == "")
		{
			filename = v_str;
		}
	}

	/* no especifico archivo fuente */
	if (filename == "")
	{
		return false;
	}

	return true;
}

/**********************************************************
 * funcion: usage_print                                   *
 * proposito: mostrar mensaje de modo de uso del          *
 *            programa.                                   *
 * argumentos:                                            *
 *  ninguno.                                              *
 * devuelve:                                              *
 *  nada                                                  *
 *********************************************************/

void usage_print(void)
{
	std::cout << "Modo de uso: ./compile ";
	std::cout << "ARCHIVO_RTLOG [OPCIONES]";
	std::cout << std::endl;
	std::cout << "Convierte un archivo hdl codificado en rtlog (.rtl) ";
	std::cout << "en un archivo Verilog (.v) ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "  -c, --clock=CLOCK      ";
	std::cout << "Especifica la metodologia de sincronizacion con ";
	std::cout << std::endl;
	std::cout << "                         ";
    std::cout <<  "CLOCK: global, local.";
	std::cout << std::endl;
	std::cout << "  -R, --report=REPORT    ";
	std::cout << "Especifica el tipo de informe de compilacion con ";
	std::cout << std::endl;
	std::cout << "                         ";
    std::cout << "REPORT: general, graph, async-graph, meta-graph, ";
	std::cout << std::endl;
	std::cout << "                         ";
    std::cout << "        cloud-logic, i2r-paths, r2o-paths, r2r-paths,.";
	std::cout << std::endl;
	std::cout << std::endl;
    std::cout <<  "Estado de salida:";
	std::cout << std::endl;
	std::cout << "  0  si todo fue bien";
	std::cout << std::endl;
	std::cout << "  1  si no hizo nada (p. ej., corrio esta ayuda),";
	std::cout << std::endl;
}

/**********************************************************
 * funcion: args_check                                    *
 * proposito: interpreta los argumentos ingresados por    *
 *            linea de comandos para el tipo de clock     *
 * argumentos:                                            *
 *  argc - cantidad de argumentos.                        *
 *  *argv[] - vector de argumentos.                       *
 * devuelve:                                              *
 *  true - circuito asincronico.                          *
 *  false - circuito sincronico.                          *
 *********************************************************/
bool async_check(int argc, char *argv[])
{
	std::string v_str;

	/* recorre todos los argumentos */
	for (int i = 1; i < argc; i++)
	{
		v_str = std::string(argv[i]);

		/* --clock= */
		if (v_str == "-c")
		{
			i++;
			v_str = std::string(argv[i]);
			std::cout << v_str;
			/* falta tipo de clock */
			if ((!(v_str == "local")) && (!(v_str == "global")))
			{
				std::cerr << "switch -c erroneo";
				std::cerr << std::endl;
				exit(1);
				//return false;
			}
			else if (v_str == "local")  return true;
			else if (v_str == "global")	return false;
		}
		else if (v_str == "--clock=local") return true;
		else if (v_str == "--clock=global")return false;
	}
	/*por default, es sincronico*/
	return false;
}
