CC=g++
CFLAGS=-std=c++11
DEPS=Book.h Borrow.h Date.h Libreria.h
OBJ= driver.o Book.o Borrow.o Date.o Libreria.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)