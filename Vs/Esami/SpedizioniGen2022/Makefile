CC=g++
CFLAGS=-std=c++11
DEPS=Date1.h Pacco.h PaccoExtra.h Spedizioni.h
OBJ=Date1.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)