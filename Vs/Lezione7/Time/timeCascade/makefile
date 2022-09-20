#Makefile for cascade 
cascade: cascade.o Time.o
		g++ -o cascade cascade.o Time.o
cascade.o: cascade.cpp Time.h
		g++ -c cascade.cpp -Wall -pedantic -std=c++11
Time.o: Time.cpp Time.h
		g++ -c Time.cpp -Wall -pedantic -std=c++11
