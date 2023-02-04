#ifndef SEPARATECHAININGGHASHTABLE_H
#define SEPARATECHAININGGHASHTABLE_H
#include "HashTable.h"
#include "linkedprocess.h"

class SeparateChainingHashTable: public HashTable {

private:
    LinkedProcess* deleted_process;

    int hashing(unsigned int k);
    int getHeadMem();
    LinkedProcess* searchProcess(unsigned int pid);

public:
    SeparateChainingHashTable(int N, int P);
    ~SeparateChainingHashTable();

    void insertPID(unsigned int pid);
    void searchPID(unsigned int pid);
    void writePID(unsigned int pid, int addr, int x);
    void readPID(unsigned int pid, int addr);
    void deletePID(unsigned int pid);
    void print(int m);

};

#endif