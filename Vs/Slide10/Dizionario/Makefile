CC=g++
CFLAGS=-std=c++11
DEPS=Dict.h
OBJ= Dict.o Dizionario.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Dizionario: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)