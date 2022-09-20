CC=g++
CFLAGS=-std=c++11
DEPS = point.h Rectangle.h
OBJ = point.o Rectangle.o driver.o 

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)