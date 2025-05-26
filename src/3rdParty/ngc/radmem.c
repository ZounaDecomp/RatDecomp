#include "radmem.h"

#pragma push
#pragma section ".data" ".data"
__declspec(section ".data") RADMEMALLOC usermalloc = NULL;
__declspec(section ".data") RADMEMFREE userfree = NULL;
#pragma pop

#pragma optimizewithasm off
void RADSetMemory(register RADMEMALLOC malloc_fn, register RADMEMFREE free_fn) {
    __asm {
        lis r9, usermalloc@ha
        lis r11, userfree@ha
        stw r3, usermalloc@l(r9)
        stw r4, userfree@l(r11)
    }
}

void* radmalloc(U32 size) {

}
