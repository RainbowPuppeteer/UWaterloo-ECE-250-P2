#ifndef LINKEDPROCESS_H
#define LINKEDPROCESS_H

#include "process.h"

class LinkedProcess: public Process
{
public:
    LinkedProcess* next;
    LinkedProcess* previous;

    LinkedProcess(unsigned int PID, int head_mem);
    ~LinkedProcess();
};

#endif