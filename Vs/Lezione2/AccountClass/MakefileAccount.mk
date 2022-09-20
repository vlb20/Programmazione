AccountTest: AccountTest.o
		g++ -o AccountTest AccountTest.o
AccountTest.o: AccountTest.cpp Account.h
		g++ -std=c++11 -c AccountTest.cpp
		