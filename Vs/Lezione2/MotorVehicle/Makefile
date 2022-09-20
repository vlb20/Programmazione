GCC=g++
CFLAGS= -std=c++11 -Wall -pedantic

Motor: Motor.o testMotor.o
	${GCC} -o Motor Motor.o testMotor.o ${CFLAGS}
testMotor.o: testMotor.cpp Motor.h
	${GCC} -c testMotor.cpp ${CFLAGS}
Motor.o: Motor.cpp Motor.h
	${GCC} -c Motor.cpp ${CFLAGS}