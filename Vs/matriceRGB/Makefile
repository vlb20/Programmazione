CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Immagine.h Immagine.cpp
OBJ = Driver.o 

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
Driver: $(OBJ)
	$(CC) -o $@ $^