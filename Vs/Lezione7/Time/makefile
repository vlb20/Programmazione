Timetester: Timetester.o Time.o
	g++ -o Timetester Timetester.o Time.o
Timetester.o: Time.h Timetester.cpp
	g++ -c Timetester.cpp -std=c++11 -Wall -pedantic
Time.o: Time.h Time.cpp
	g++ -c Time.cpp -std=c++11 -Wall -pedantic