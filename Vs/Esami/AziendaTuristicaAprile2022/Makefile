CC=g++
CFLAGS=-std=c++11
DEPS=Date.h Prenotazione.h  Albergo.h
OBJ=Date.o Prenotazione.o  Albergo.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)