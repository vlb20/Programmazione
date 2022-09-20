CC=g++
CFLAGS=-std=c++11
DEPS=Matrix.h
OBJ=Matrix.o driver.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)