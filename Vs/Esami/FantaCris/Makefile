CC=g++
CFLAGS=-std=c++11
DEPS=Book.h Borrow.h Date.h Biblioteca.h
OBJ=Driver.o Book.o Borrow.o Date.o Biblioteca.o  

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Driver:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)