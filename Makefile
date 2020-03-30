#####################
#   Makefile LZesp  # 
#####################

#Name, headers, sources
TARGET=Spr_LZesp
_DEPS=LZespolona.hh WyrazenieZesp.hh BazaTestu.hh Stats.hh
_OBJ=main.o LZespolona.o WyrazenieZesp.o BazaTestu.o Stats.o

####DIRS###
TRG_DIR=./
OBJ_DIR=./obj
INC_DIR=./inc
SRC_DIR=./src

###COMPILER###
CC = g++
CFLAGS = -Wall -pedantic -std=c++14 -iquote $(INC_DIR)
LFLAGS = -Wall -pedantic -std=c++14 -iquote $(INC_DIR)

###FORMULA###
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

.PHONY: clean

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*

