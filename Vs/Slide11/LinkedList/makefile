#Makefile for testGenericLinkedList
CC = g++
CFLAGS = -std=c++11
DEPS = Node.h LinkedList.h LinkedList.cpp
OBJ = testGenericList.o


testLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
testGenericList.o: testGenericList.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


