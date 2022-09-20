CC=g++
CFLAGS=-std=c++11
DEPS=BasePlus.h Commission.h Salaried.h Employee.h
OBJ=Commission.o Salaried.o testEmployee.o BasePlus.o Employee.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testEmployee: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)