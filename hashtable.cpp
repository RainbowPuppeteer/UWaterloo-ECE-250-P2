#include "hashtable.h"

HashTable::HashTable(int N, int P):
    mem_size{N}, page_size{P}, table_size{N / P}
{
    virtual_memory = new int[mem_size]();
    process = new Process*[table_size]();
}

HashTable::~HashTable()
{
    delete virtual_memory;
    for (int i=0; i<table_size; i++)
    {
        if (process[i])
            delete process[i];
    }
    delete process;
}