CC=g++
CFLAGS=-std=c++11
DEPS=Insegnamento.h Segreteria.h Studente.h
OBJ= main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)