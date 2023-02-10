#include "hashtable.h"

HashTable::HashTable(int N, int P):
    mem_size{N}, page_size{P}, table_size{N / P}, current_table_size{0}
{
    virtual_memory = new int[mem_size]();
    process_table = new Process*[table_size]();

    std::cout << "success" << std::endl;
}

HashTable::~HashTable()
{
    delete[] virtual_memory;
    for (int i=0; i<table_size; i++)
    {
        if (process_table[i])
            delete process_table[i];
    }
    delete[] process_table;
}