testTime: testTime.o Time.o
	g++ -o testTime testTime.o Time.o
testTime.o: Time.h testTime.cpp
	g++ -c testTime.cpp -std=c++11 -Wall -pedantic
Time.o: Time.h Time.cpp
	g++ -c Time.cpp -std=c++11 -Wall -pedantic