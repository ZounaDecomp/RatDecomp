#ifndef _RADMEM_H_
#define _RADMEM_H_
#include "bink_types.h"

typedef void *(*RADMEMALLOC)(U32 size);
typedef void (*RADMEMFREE)(void* mem);

void RADSetMemory(register RADMEMALLOC malloc_fn, register RADMEMFREE free_fn);
void* radmalloc(U32 size);
#endif
