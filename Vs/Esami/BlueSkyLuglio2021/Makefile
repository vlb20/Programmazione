CC=g++
CFLAGS=-std=c++11
DEPS= Date.h Sensor.h BlueSky.h
OBJ= Sensor.o BlueSky.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
