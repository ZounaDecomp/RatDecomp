#ifndef _RADMEM_H_
#define _RADMEM_H_
#include "bink_types.h"
#include "OSAlloc.h"

typedef void *(*RADMEMALLOC)(U32 size);
typedef void (*RADMEMFREE)(void* mem);

void RADSetMemory(register RADMEMALLOC malloc_fn, register RADMEMFREE free_fn);
void* radmalloc(U32 size);
void radfree(void* ptr);

extern volatile OSHeapHandle __OSCurrHeap;

#pragma push
#pragma section ".data" ".data"
__declspec(section ".data") RADMEMALLOC usermalloc = NULL;
__declspec(section ".data") RADMEMFREE userfree = NULL;
#pragma pop

#endif
