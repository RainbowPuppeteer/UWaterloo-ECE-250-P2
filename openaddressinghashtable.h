#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include "HashTable.h"
#include "staticprocess.h"

class OpenAddressingHashTable: public HashTable {

private:
    int hashing_1(unsigned int k);
    int hashing_2(unsigned int k);
    Process* searchProcess(unsigned int pid);

public:
    OpenAddressingHashTable(int N, int P);
    ~OpenAddressingHashTable();

    void insertPID(unsigned int pid);
    void searchPID(unsigned int pid);
    void writePID(unsigned int pid, int addr, int x);
    void readPID(unsigned int pid, int addr);
    void deletePID(unsigned int pid);
    void print(int m) { } 

};

#endif