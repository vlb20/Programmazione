all: Helloworld Helloworldn

Helloworld: Helloworld.o
	g++ -o Helloworld Helloworld.o
Helloworld.o: Helloworld.cpp
	g++ -c -std=c++11 Helloworld.cpp	
Helloworldn: Helloworldn.o
	g++ -o Helloworldn Helloworldn.o
Helloworldn.o: Helloworldn.cpp
	g++ -c -std=c++11 Helloworldn.cpp 		