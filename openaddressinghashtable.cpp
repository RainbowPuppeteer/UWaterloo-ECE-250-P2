#include "openaddressinghashtable.h"


OpenAddressingHashTable::OpenAddressingHashTable(int N, int P): HashTable(N, P) { }

OpenAddressingHashTable::~OpenAddressingHashTable() { }

int OpenAddressingHashTable::hashing_1(unsigned int k)
{
    return k % table_size;
}

int OpenAddressingHashTable::hashing_2(unsigned int k)
{
    int h2 = (k / table_size) % table_size;
    return h2 % 2 == 0 ? h2 + 1 : h2;
}

Process* OpenAddressingHashTable::searchProcess(unsigned int pid)
{
    int probe = hashing_1(pid);
    int offset = hashing_2(pid);   

    int i = 0;

    while (process_table[probe] != nullptr)
    {   
        StaticProcess* process = (StaticProcess*) process_table[probe];
        // Found key
        if (!process->deleted && process_table[probe]->pid == pid)
            return process_table[probe];

        // Searched all table.
        if (++i == table_size)
            break;

        probe = (probe + offset) % table_size;
    }
    // No key found
    return nullptr;
}


void OpenAddressingHashTable::insertPID(unsigned int pid)
{
    if (current_table_size == table_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    int probe = hashing_1(pid);
    int offset = hashing_2(pid);   

    int first_deleted = -1;
    int i = 0;

    while (process_table[probe] != nullptr)
    {   
        StaticProcess* process = (StaticProcess*) process_table[probe];
        // If it's the first deleted, record this.
        if (process->deleted && first_deleted < 0)
            first_deleted = probe;

        // If it's not deleted and exist, then return.
        if (!process->deleted && process_table[probe]->pid == pid)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        // Searched all table.
        if (++i == table_size)
            break;

        probe = (probe + offset) % table_size;
    }

    if (first_deleted >= 0)
    {   // Free the deleted one
        delete process_table[first_deleted];
        probe = first_deleted;
    }
    process_table[probe] = new StaticProcess(pid, probe * page_size);
    current_table_size++;

    std::cout << "success" << std::endl;
}


void OpenAddressingHashTable::searchPID(unsigned int pid)
{
    Process* process = searchProcess(pid);
    if(process)
        std::cout << "found " << pid << " in " << process->head_memory / page_size << std::endl;
    else
        std::cout << "not found" << std::endl;
}


void OpenAddressingHashTable::writePID(unsigned int pid, int addr, int x)
{
    if (addr >= page_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    Process* process = searchProcess(pid);
    if(process)
    {
        virtual_memory[process->head_memory + addr] = x;
        std::cout << "success" << std::endl;
    }
    else
        std::cout << "failure" << std::endl;
}

void OpenAddressingHashTable::readPID(unsigned int pid, int addr)
{
    if (addr >= page_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    Process* process = searchProcess(pid);
    if(process)
        std::cout << addr << " " << virtual_memory[process->head_memory + addr] << std::endl;
    else
        std::cout << "failure" << std::endl;
}

void OpenAddressingHashTable::deletePID(unsigned int pid)
{
    StaticProcess* process = (StaticProcess*) searchProcess(pid);
    if(process)
    {
        process->deleted = true;
        std::cout << "success" << std::endl;
        current_table_size--;
        // Reinitialize memory
        for (int i=0; i<page_size; i++)
            virtual_memory[process->head_memory + i] = 0;
    }
    else
        std::cout << "failure" << std::endl;
}
