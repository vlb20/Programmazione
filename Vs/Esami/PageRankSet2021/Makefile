CC=g++
CFLAGS=-std=c++11
DEPS=WWW.h
OBJ=main.o WWW.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)