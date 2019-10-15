///////////////////////////////////////////////////////////
// codigo fuente: tag.h                                  //
// fecha de inicio: 18/11/2017                           //
// autor/es:                                             //
//         Roberto Geronimo Simone                       //
//                                                       //
// proposito: etiquetas enumeradas globales.             //
//                                                       //
// enumeraciones:                                        //
//  tag_node - id de nodos.                              //
//  tag_port - direccion de un puerto.                   //
//  tag_reg - registracion de un puerto.                 //
//  token_type - tipos de tokens.                        //
//  token_keywords - tipos de keywords.                  //
//  token_operators - tipos de operadores.               //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef __TAG_H
#define __TAG_H

enum tag_node { NODE_ID_VOID, 
				NODE_ID_PORTIN,
				NODE_ID_PORTOUT,
				NODE_ID_TIEHI,
				NODE_ID_TIELO,
				NODE_ID_NOT,
				NODE_ID_BUF,
				NODE_ID_ADD,
				NODE_ID_ADDCOUT,
				NODE_ID_MULT,
				NODE_ID_MUX2,
				NODE_ID_MUXN,
				NODE_ID_NEG,
				NODE_ID_SUB,
				NODE_ID_SUBBOUT,
				NODE_ID_AND2,
				NODE_ID_OR2,
				NODE_ID_REG,
				NODE_ID_XOR2,
				NODE_ID_XNOR2,
				NODE_ID_CPEQ,
				NODE_ID_CPGR,
				NODE_ID_CPGEQ,
				NODE_ID_CPLW,
				NODE_ID_CPLEQ,
				NODE_ID_CPNEQ,
				NODE_ID_LATCH,
				NODE_ID_LC,
				NODE_ID_JC,
				NODE_ID_FC };

enum token_type { TK_VOID, 
					TK_KW, TK_OP, 
					TK_ID, 
					TK_NUM, 
					TK_NL };

enum token_keywords { KW_LOGIC, 
						KW_INPUT, 
						KW_OUTPUT,
						KW_REG, 
						KW_BLOCK, 
						KW_BEGIN, 
						KW_PARAM,
						KW_NATURAL,
						KW_CONSTANT,
						KW_END, 
						KW_PORTS, 
						KW_CAT,
						KW_REP, 
						KW_OTHERS, 
						KW_NOT,
						KW_OR, 
						KW_AND, 
						KW_XOR, 
						KW_XNOR, 
						KW_IF, 
						KW_ELSIF, 
						KW_ELSE,
						KW_CASE,
						KW_FOR,
						KW_IN,
						KW_RANGE,
						KW_WHEN };

enum token_operators { OP_PAR_OP, 
						OP_PAR_CL, 
						OP_IX_OP, 
						OP_IX_CL, 
						OP_ASSGN,
						OP_RANGE, 
						OP_USHFT, 
						OP_SSHFT, 
						OP_LSHFT,
						OP_ADD, 
						OP_ADDC,
						OP_SUB, 
						OP_SUBB,
						OP_MULT,
						OP_DIV,
						OP_CP_EQ,
						OP_CP_NEQ,
						OP_CP_GR,
						OP_CP_GREQ,
						OP_CP_LW,
						OP_CP_LWEQ,
						OP_AND,
						OP_COMMA };

enum tag_port { PORT_IN,
				PORT_OUT
				};

enum tag_reg { PORT_LOGIC,
				PORT_REG
				};

enum tag_fan { FAN_LE,
				FAN_REQ_RIGHT,
				FAN_REQ_LEFT,
				FAN_ACK_LEFT,
				FAN_ACK_RIGHT,
				FAN_D,
				FAN_REQ_LEFT_1,
				FAN_REQ_LEFT_2,
				FAN_ACK_LEFT_1,
				FAN_ACK_LEFT_2,
				FAN_REQ_RIGHT_1,
				FAN_REQ_RIGHT_2,
				FAN_ACK_RIGHT_1,
				FAN_ACK_RIGHT_2 };

enum tag_branch { BRANCH_LEFT,
					BRANCH_CENTER,
					BRANCH_RIGHT };

enum tag_symbol_type { E_TYPE_ID,
						E_TYPE_ITER_INDEX };

#endif
