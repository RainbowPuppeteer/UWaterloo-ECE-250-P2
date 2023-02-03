#ifndef PROCESS_H
#define PROCESS_H

class Process
{
public:
    int pid;
    int head_memory;

    Process(int PID, int head_mem);
    ~Process();
};

#endif