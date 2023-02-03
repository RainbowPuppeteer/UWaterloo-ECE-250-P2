#include "HashTable.h"

#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

class OpenAddressingHashTable: public HashTable {

private:
    

public:
    OpenAddressingHashTable(int N, int P);
    ~OpenAddressingHashTable();

    void insertPID(unsigned int pid);
    void searchPID(unsigned int pid);
    void writePID(unsigned int pid, int addr, int x);
    void readPID(unsigned int pid, int addr);
    void deletePID(unsigned int pid);
    void print(unsigned int pid);

};

#endif