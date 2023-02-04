#include "linkedprocess.h"

LinkedProcess::LinkedProcess(unsigned int PID, int head_mem): Process(PID, head_mem), next{nullptr}, previous{nullptr} { }

LinkedProcess::~LinkedProcess() { }