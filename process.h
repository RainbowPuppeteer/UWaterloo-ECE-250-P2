#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
    unsigned int pid;
    int head_memory;

    Process(unsigned int PID, int head_mem);
    virtual ~Process() = 0;
};

#endif