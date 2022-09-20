CC=g++
CFLAGS=-std=c++11
DEPS=Prenotazione.h Albergo.h Azienda.h Date.h
OBJ=driver.o Date.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)