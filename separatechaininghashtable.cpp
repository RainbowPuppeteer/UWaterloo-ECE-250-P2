#include "separatechaininghashtable.h"

SeparateChainingHashTable::SeparateChainingHashTable(int N, int P): HashTable(N, P), deleted_process{nullptr} { }

SeparateChainingHashTable::~SeparateChainingHashTable()
{
    LinkedProcess* c = nullptr;
    LinkedProcess* n = nullptr;
    // Free all table processes
    for (int i=0; i<table_size; i++)
    {
        c = (LinkedProcess*) process_table[i];
        while (c)
        {
            n = c->next;
            delete c;
            c = n;
        }
        c = nullptr; n = nullptr;
        process_table[i] = nullptr;
    }
    // Free all deleted processes
    c = deleted_process;
    while (c)
    {
        n = c->next;
        delete c;
        c = n;
    }
    c = nullptr; n = nullptr;
    deleted_process = nullptr;
}

int SeparateChainingHashTable::hashing(unsigned int k)
{
    return k % table_size;
}

int SeparateChainingHashTable::getHeadMem()
{
    if (deleted_process)
    {
        int res = deleted_process->head_memory;
        LinkedProcess* tmp = deleted_process;
        deleted_process = deleted_process->next;
        delete tmp;
        tmp = nullptr;
        return res;
    }

    return current_table_size;
}

LinkedProcess* SeparateChainingHashTable::searchProcess(unsigned int pid)
{
    int probe = hashing(pid);

    LinkedProcess* head = (LinkedProcess*) process_table[probe];

    while (head)
    {
        if (head->pid != pid)
            head = head->next;
        else
            return head;
    }
    return nullptr;
}

void SeparateChainingHashTable::insertPID(unsigned int pid)
{
    if (current_table_size == table_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    int probe = hashing(pid);

    LinkedProcess* head = (LinkedProcess*) process_table[probe];

    if (!head)
    {   // If the head is null
        process_table[probe] = new LinkedProcess(pid, getHeadMem());
        std::cout << "success" << std::endl;
        current_table_size++;
        return;
    }


    do {
        if (head->pid == pid) // pid exist
        {
            std::cout << "failure" << std::endl;
            return;
        }
        else if (head->pid < pid) // insert to the left of the head.
        {
            LinkedProcess* tmp = new LinkedProcess(pid, getHeadMem());
            tmp->previous = head->previous;
            tmp->next = head;

            if (head->previous)
                head->previous->next = tmp;
            else
                process_table[probe] = tmp;

            head->previous = tmp;


            std::cout << "success" << std::endl;
            current_table_size++;
            return;
        }
        else
            head = head->next;
    } while (head->next);
    // new node is at the end
    LinkedProcess* tmp = new LinkedProcess(pid, getHeadMem());
    tmp->previous = head;
    head->next = tmp;

    std::cout << "success" << std::endl;
    current_table_size++;
    return;
}

void SeparateChainingHashTable::searchPID(unsigned int pid)
{
    LinkedProcess* process = searchProcess(pid);
    if(process)
        std::cout << "found " << pid << " in " << process->head_memory / page_size << std::endl;
    else
        std::cout << "not found" << std::endl;
}

void SeparateChainingHashTable::writePID(unsigned int pid, int addr, int x)
{
    if (addr >= page_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    LinkedProcess* process = searchProcess(pid);
    if(process)
    {
        virtual_memory[process->head_memory + addr] = x;
        std::cout << "success" << std::endl;
    }
    else
        std::cout << "failure" << std::endl;
}

void SeparateChainingHashTable::readPID(unsigned int pid, int addr)
{
    if (addr >= page_size)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    LinkedProcess* process = searchProcess(pid);
    if(process)
        std::cout << addr << " " << virtual_memory[process->head_memory + addr] << std::endl;
    else
        std::cout << "failure" << std::endl;
}

void SeparateChainingHashTable::deletePID(unsigned int pid)
{
    int probe = hashing(pid);

    LinkedProcess* head = (LinkedProcess*) process_table[probe];

    while (head)
    {
        if (head->pid != pid)
            head = head->next;
        else
        {
            // connect the nodes
            if (head->previous)
                head->previous->next = head->next;
            else
                process_table[probe] = head->next;
            
            if (head->next)
                head->next->previous = head->previous;

            // connect the head to the deleted process
            head->previous = nullptr;
            head->next = deleted_process;
            deleted_process = head;
            // Reinitialize memory
            for (int i=0; i<page_size; i++)
                virtual_memory[head->head_memory + i] = 0;
            std::cout << "success" << std::endl;
            current_table_size--;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}

void SeparateChainingHashTable::print(int m)
{
    LinkedProcess* head = (LinkedProcess*) process_table[m];
    if (!head)
        std::cout << "chain is empty"  << std::endl;
    else 
    {
        while (1) {
            std::cout << head->pid;
            if (head->next)
            {
                std::cout << " ";
                head = head->next;
            }
            else
            {
                std::cout << std::endl;
                break;
            }
        }
    }

}