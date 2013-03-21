CC = g++
FLAGS = -Wall -WError

SRCDIR = ../src
BINDIR = ../bin
TESTDIR = $(BINDIR)/tests
OBJECTS = Process.o

all: test.cpp $(OBJECTS)
	$(CC) -o $(TESTDIR)/all $(OBJECTS) test.cpp

Process.o: $(SRCDIR)/Process.cpp
	$(CC) -c $(SRCDIR)/Process.cpp

clean:
	rm *.o
