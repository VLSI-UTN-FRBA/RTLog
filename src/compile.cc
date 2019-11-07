 /**
  * @file    compile.cc
  * @author  Roberto Geronimo Simone
  * @version 1.0
  *
  * @section License
  *
  * to do
  *
  * @section Description
  *
  * Transcompiler of the RTLog Lenguage
  *
  * use: ./compile archivo [-c, --clock=CLOCK ]
  *
  * @date 01/12/2017
  */

#include <iostream>
#include <string>

#include "parser.h"

/*
 * Structure to configure the compilation report
 */
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

/*
 * Functions prototypes
 */
bool args_check(int argc,
                char *argv[],
                std::string& filename,
                report_t &report_field);
bool async_check(int argc, char *argv[]);
void usage_print(void);

/*
 * Main
 */
int main(int argc, char *argv[])
{
	std::string     v_filename;
	class Parser    v_parse;
    report_t        report_field;

    report_field.m_word = 0;

	v_parse.setSync();

	/*
   * Message about program use
   */
	if (argc == 1)
	{
		usage_print();

		return 1;
	}
	/*
   * Must include source file
   */
	else if (!args_check(argc, argv, v_filename, report_field))
	{
		return 1;
	}
	/*
   * Check if is async or sync
   */
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

    /*
     * General report
     */
    if (report_field.m_bits.m_general)
    {
        v_parse.report(Parser::E_REPORT_GENERAL);
    }

    /*
     * Graph report
     */
    if (report_field.m_bits.m_graph)
    {
        v_parse.report(Parser::E_REPORT_GRAPH);
    }

    /*
     * Async graph report
     */
    if (report_field.m_bits.m_async_graph)
    {
        v_parse.report(Parser::E_REPORT_ASYNC_GRAPH);
    }

    /*
     * Cloud logic report
     */
    if (report_field.m_bits.m_cloud_logic)
    {
        v_parse.report(Parser::E_REPORT_CLOUD_LOGIC);
    }

    /*
     * I2R paths report
     */
    if (report_field.m_bits.m_i2r_paths)
    {
        v_parse.report(Parser::E_REPORT_I2R_PATHS);
    }

    /*
     * Metagraph report
     */
    if (report_field.m_bits.m_metagraph)
    {
        v_parse.report(Parser::E_REPORT_METAGRAPH);
    }

    /*
     * R2O paths report
     */
    if (report_field.m_bits.m_r2o_paths)
    {
        v_parse.report(Parser::E_REPORT_R2O_PATHS);
    }

    /*
     * R2R paths report
     */
    if (report_field.m_bits.m_r2r_paths)
    {
        v_parse.report(Parser::E_REPORT_R2R_PATHS);
    }

	return 0;
}

/**
 * Interpreter of command-line arguments
 * @param  argc         amount of arguments
 * @param  argv         vector of arguments
 * @param  filename     rtl sourcefile
 * @param  report_field bitfield to configure report
 * @return              true for error free or false
 */
bool args_check(int argc,
                char *argv[],
                std::string& filename,
                report_t &report_field)
{
	std::string v_str;

  /*
   * Go trough every arguments
   */
	for (int i = 1; i < argc; i++)
	{
		v_str = std::string(argv[i]);

		/*
     *  --report=
     */
		if (v_str == "-R")
		{
			i++;

			/*
       * Report type is missing
       */
			if (i >= argc)
			{
				std::cerr << "switch -R without arguments";
				std::cerr << std::endl;

				return false;
			}
			else
			{
        		v_str = std::string(argv[i]);

                /*
                 * no report
                 */
                if (v_str == "off")
                {
                    report_field.m_word = 0;
                }
                /*
                 * general report
                 */
                else if (v_str == "general")
                {
                    report_field.m_bits.m_general = 1;
                }
                /*
                 * graph report
                 */
                else if (v_str == "graph")
                {
                    report_field.m_bits.m_graph = 1;
                }
                /*
                 * async graph report
                 */
                else if (v_str == "async-graph")
                {
                    report_field.m_bits.m_async_graph = 1;
                }
                /*
                 * metagraph report
                 */
                else if (v_str == "meta-graph")
                {
                    report_field.m_bits.m_metagraph = 1;
                }
                /*
                 * cloud logic report
                 */
                else if (v_str == "cloud-logic")
                {
                    report_field.m_bits.m_cloud_logic = 1;
                }
                /*
                 * I2R paths report
                 */
                else if (v_str == "i2r-paths")
                {
                    report_field.m_bits.m_i2r_paths = 1;
                }
                /*
                 * R2O paths report
                 */
                else if (v_str == "r2o-paths")
                {
                    report_field.m_bits.m_r2o_paths = 1;
                }
                /*
                 * R2R paths report
                 */
                else if (v_str == "r2r-paths")
                {
                    report_field.m_bits.m_r2r_paths = 1;
                }
			}
		}
		/*
     * source file
     */
		else if (filename == "")
		{
			filename = v_str;
		}
	}

	/*
   * source file is missing
   */
	if (filename == "")
	{
		return false;
	}

	return true;
}

/**
 * Shows in terminal the options of the program
 */
void usage_print(void)
{
	std::cout << "How to use: ./compile ";
	std::cout << "RTLOG_FILE [OPTIONS]";
	std::cout << std::endl;
	std::cout << "Converts a hdl file codified in rtlog (.rtl) ";
	std::cout << "in a Verilog file (.v) ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "  -c, --clock=CLOCK      ";
	std::cout << "Specifies the sincronization metodology ";
	std::cout << std::endl;
	std::cout << "                         ";
  std::cout <<  "CLOCK: global, local.";
	std::cout << std::endl;
	std::cout << "  -R, --report=REPORT    ";
	std::cout << "Specifies the type of compilation report with ";
	std::cout << std::endl;
	std::cout << "                         ";
  std::cout << "REPORT: general, graph, async-graph, meta-graph, ";
	std::cout << std::endl;
	std::cout << "                         ";
  std::cout << "        cloud-logic, i2r-paths, r2o-paths, r2r-paths,.";
	std::cout << std::endl;
	std::cout << std::endl;
  std::cout <<  "Output result:";
	std::cout << std::endl;
	std::cout << "  0  if everything went right";
	std::cout << std::endl;
	std::cout << "  1  if it didn't do anything (for example, it run this help),";
	std::cout << std::endl;
}


 /**
  * Interpreter of command-line arguments for clock type
  * @param  argc amount of arguments
  * @param  argv vector of arguments
  * @return      true for async circuit or false for sync
  */
bool async_check(int argc, char *argv[])
{
	std::string v_str;

	/*
   * Go trough every arguments
   */
	for (int i = 1; i < argc; i++)
	{
		v_str = std::string(argv[i]);

		/*
     * --clock=
     */
		if (v_str == "-c")
		{
			i++;
			v_str = std::string(argv[i]);
			//std::cout << v_str;
			/*
       * clock type is missing
       */
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
	/*
   * by default, synchronous circuit
   */
	return false;
}
