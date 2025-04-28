#ifndef _LOWMEMORY_Z_H_
#define _LOWMEMORY_Z_H_
#include "Memory_Z.h"

class MemoryManager_Z : public Hi_MemoryManager_Z {
public:
    virtual void Init();
    virtual void SetCallStackPtrs(unsigned long* a1, long a2);
    virtual ~MemoryManager_Z();
};

extern MemoryManager_Z MemManager;

#endif
