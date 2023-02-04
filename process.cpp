#include "process.h"

Process::Process(unsigned int PID, int head_mem): pid{PID}, head_memory{head_mem} { }

Process::~Process() { };