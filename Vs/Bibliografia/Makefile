CC=g++
CFLAGS=-std=c++11
DEPS=Publication.h Book.h quickSort.h JournalPaper.h ConfPaper.h
OBJ= driver.o Publication.o Book.o  JournalPaper.o ConfPaper.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)