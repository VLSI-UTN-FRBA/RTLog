# Makefile
# Version: 2.0
# Año: 2019










# ******************************************************************** #
# *************************** User defines *************************** #
# ******************************************************************** #
CC=g++

PROGRAM = compile

MAIN_DIR = ./src
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj
PROG_DIR = ./bin
EXAMPLE_DIR = ./rtl

CFLAGS += -Wall -g
LDLIBS += -lm










# ******************************************************************** #
# ************************* Constant defines ************************* #
# ******************************************************************** #
OUTPUT = $(PROGRAM)

CXXFLAGS=-std=c++11

CFLAGS += -I$(INC_DIR)
CFLAGS += $(foreach dir,$(INC_DIR),-I$(dir))

SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cc) $(wildcard $(dir)/*/*.cc))
SRC_MAIN = $(wildcard $(MAIN_DIR)/$(PROGRAM).cc)
OBJ = $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
OBJ_DIRS = $(OBJ:%.o=%)
OBJ_MAIN = $(SRC_MAIN:$(MAIN_DIR)/%.cc=$(OBJ_DIR)/%.o)
EXAMPLE = $(firstword $(wildcard $(EXAMPLE_DIR)/*.rtl))

define COMPILAR
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	'-----> Compilando: '$(2)
	@echo	''

	$(CC) $(CXXFLAGS) $(CFLAGS) -c $(firstword $(2)) -o $(1)
endef










# ******************************************************************** #
# ****************************** Reglas ****************************** #
# ******************************************************************** #
.PHONY: all
all: create_output_dir $(OUTPUT) ejecutar

$(OUTPUT): $(OBJ) $(OBJ_MAIN)
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	'-----> Linkeando: '$(OBJ)
	@echo	''
	$(CC) $(OBJ) $(LDLIBS) -o $@
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	'READY'	
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	''





.PHONY: ejecutar
ejecutar:
	@echo	'Ejecutando...'
	./$(PROGRAM) ./rtl/join_fork.rtl


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INC_DIR)/%.h
	$(call COMPILAR, $@, $^)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(call COMPILAR, $@, $^)

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cc $(INC_DIR)/%.h
	$(call COMPILAR, $@, $^)

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cc
	$(call COMPILAR, $@, $^)

.PHONY: create_output_dir
create_output_dir:
	@echo 'src:'
	@echo $(SRC)
	@echo 'obj:'
	@echo $(OBJ)
	mkdir -p $(OBJ_DIRS)

.PHONY: clean
clean:
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	''
	@echo	'-----> Limpiando'
	@echo	''

	$(RM) $(OBJ) $(OBJ_MAIN) $(OUTPUT)

