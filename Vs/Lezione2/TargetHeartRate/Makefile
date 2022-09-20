testThr: testThr.o THR.o 
	g++ -o testThr testThr.o  THR.o 
testThr.o: testThr.cpp THR.h Date.h
	g++ -c testThr.cpp -std=c++11 -pedantic -Wall
THR.o: THR.cpp THR.h Date.h
	g++ -c THR.cpp -std=c++11 -pedantic -Wall
