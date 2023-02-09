#include <iostream>

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "process.h"

class HashTable {

protected:
    int mem_size;
    int page_size;
    int table_size;
    int current_table_size;
    int* virtual_memory;
    Process** process_table;

    virtual Process* searchProcess(unsigned int pid) = 0;

public:
    HashTable(int N, int P);
    virtual ~HashTable();

    virtual void insertPID(unsigned int pid) = 0;
    virtual void searchPID(unsigned int pid) = 0;
    virtual void writePID(unsigned int pid, int addr, int x) = 0;
    virtual void readPID(unsigned int pid, int addr) = 0;
    virtual void deletePID(unsigned int pid) = 0;
    virtual void print(int m) = 0;

};

#endif
