#include "staticprocess.h"

StaticProcess::StaticProcess(unsigned int PID, int head_mem): Process(PID, head_mem), deleted{false} { }

