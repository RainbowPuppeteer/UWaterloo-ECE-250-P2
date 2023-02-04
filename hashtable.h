#include <iostream>
#include "process.h"

#ifndef HASHTABLE_H
#define HASHTABLE_h

class HashTable {

protected:
    int mem_size;
    int page_size;
    int table_size;
    int current_table_size;
    int* virtual_memory;
    Process** process_table;

    virtual Process* searchProcess(unsigned int pid);

public:
    HashTable(int N, int P);
    ~HashTable();

    virtual void insertPID(unsigned int pid);
    virtual void searchPID(unsigned int pid);
    virtual void writePID(unsigned int pid, int addr, int x);
    virtual void readPID(unsigned int pid, int addr);
    virtual void deletePID(unsigned int pid);
    virtual void print(int m);

};

#endif
