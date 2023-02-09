#include <iostream>
#include <string.h>
#include "hashtable.h"
#include "openaddressinghashtable.h"
#include "separatechaininghashtable.h"

using namespace std;

int main()
{
    HashTable* hashtable;

    string type;
    cin >> type;

    string cmd;
    
    while (cin >> cmd)
    {
        if (cmd == "M")
        {
            int N, P;
            cin >> N;
            cin >> P;
            if (type == "OPEN")
                hashtable = new OpenAddressingHashTable(N, P);
            else
                hashtable = new SeparateChainingHashTable(N, P);
        } else if (cmd == "INSERT") 
        {   
            unsigned int PID;
            cin >> PID;
            hashtable->insertPID(PID);
        } else if (cmd == "SEARCH")
        {
            unsigned int PID;
            cin >> PID;
            hashtable->searchPID(PID);
        } else if (cmd == "WRITE")
        {
            unsigned int PID;
            int ADDR, x;
            cin >> PID; cin >> ADDR; cin >> x;
            hashtable->writePID(PID, ADDR, x);
        } else if (cmd == "READ")
        {
            unsigned int PID;
            int ADDR;
            cin >> PID; cin >> ADDR;
            hashtable->readPID(PID, ADDR);
        } else if (cmd == "PRINT")
        {
            int m;
            cin >> m;
            hashtable->print(m);
        } else if (cmd == "DELETE")
        {
            int PID;
            cin >> PID;
            hashtable->deletePID(PID);
        }
        else 
            break;

    }
    
    delete hashtable;
    hashtable = nullptr;
    return 0;
}