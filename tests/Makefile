CC = g++
FLAGS = -Wall -WError
DEBUGFLAGS = -g

SRCDIR = ../src
BINDIR = ../bin
TESTDIR = $(BINDIR)/tests
OBJECTS = Process.o Sys.o Ape.o

all: test.cpp $(OBJECTS)
	$(CC) -o $(TESTDIR)/all $(OBJECTS) test.cpp

Process.o: $(SRCDIR)/Process.cpp
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)/Process.cpp

Sys.o: $(SRCDIR)/Sys.cpp
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)/Sys.cpp

Ape.o: $(SRCDIR)/Ape.cpp
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)/Ape.cpp

clean:
	rm *.o
