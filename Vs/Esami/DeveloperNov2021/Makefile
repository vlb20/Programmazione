CC=g++
CFLAGS=-std=c++11
DEPS=Date.h Progetto.h Programmatori.h Tasks.h
OBJ=Date.o driver.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)