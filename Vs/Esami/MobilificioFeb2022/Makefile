CC=g++
CFLAGS=-std=c++11
DEPS=Mobilificio.h Rettangolari.h Rotondi.h Triangolari.h Tavoli.h
OBJ= main.o Mobilificio.o Rettangolari.o Rotondi.o  Triangolari.o Tavoli.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)