CC=g++
CFLAGS=-std=c++11
DEPS= TicTacToe.h
OBJ= TicTacToe.o driver.o 

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)