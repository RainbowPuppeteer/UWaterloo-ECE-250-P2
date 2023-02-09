CC = g++
CPPFLAGS = -Wall -g -std=c++11

all: main.o 
	$(CC) $(CPPFLAGS) main.o openaddressinghashtable.o separatechaininghashtable.o linkedprocess.o staticprocess.o hashtable.o process.o

main.o: main.cpp openaddressinghashtable.o separatechaininghashtable.o hashtable.o
	$(CC) $(CPPFLAGS) -c main.cpp

openaddressinghashtable.o: openaddressinghashtable.h hashtable.o staticprocess.o 

separatechaininghashtable.o: separatechaininghashtable.h hashtable.o linkedprocess.o

staticprocess.o: staticprocess.h process.o

linkedprocess.o: linkedprocess.h process.o

hashtable.o: hashtable.h

process.o: process.h

clean:
	$(RM) *.o

