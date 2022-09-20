CC=g++
CFLAGS=-std=c++11
DEPS=Insegnamenti.h Studenti.h
OBJ=driver.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)