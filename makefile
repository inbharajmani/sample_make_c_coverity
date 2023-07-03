SRC = ./src/
OBJ = ./obj/
BIN = ./bin/
CC = gcc
INC = ./inc/
CFLAGS = -c -g -Wall
OFLAGS = -o
IFLAGS = -I./inc/
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
EXECS = $(BIN)final


all:$(BIN)final

$(BIN)final :$(OBJ)main.o $(OBJ)function.o
	$(CC) $(OFLAGS)final $(OBJ)main.o $(OBJ)function.o
	mv final $(BIN)

$(OBJ)main.o:$(SRC)main.c $(INC)header.h 
	$(CC) $(CFLAGS) $(SRC)main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)function.o:$(SRC)function.c $(INC)header.h
	$(CC) $(CFLAGS) $(SRC)function.c $(IFLAGS)
	mv function.o $(OBJ)

clean:
	rm -f $(OBJ)*
	rm -f $(BIN)final

valgrind:$(EXECS)
	valgrind $(VFLAGS) $(BIN)final fix input_file1.txt



