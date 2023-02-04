#ifndef STATICPROCESS_H
#define STATICPROCESS_H

#include "process.h"

class StaticProcess: public Process
{
public:
    bool deleted;

    StaticProcess(unsigned int PID, int head_mem);
    ~StaticProcess();
};

#endif