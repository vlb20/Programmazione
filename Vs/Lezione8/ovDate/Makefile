CC=g++
CFLAGS= -std=c++11
DEPS = Date.h
OBJ = Date.cpp testDate.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
testDate: ${OBJ}
		$(CC) -o $@ $^ $(CFLAGS)