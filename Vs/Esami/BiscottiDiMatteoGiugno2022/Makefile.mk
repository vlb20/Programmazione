CC=g++
CFLAGS=-std=c++11
DEPS= Azienda.h Biscotto.h
OBJ= Driver.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)