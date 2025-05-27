#include "binkngc.h"
#pragma optimizewithasm off
U32 mult64anddiv(U32 m1, U32 m2, U32 d) {
    
}

//mult64andshiftgoeshere

void radmemset16(register void* dest, register U16 value, register U32 size) {
    asm {
        srwi r9, size, 1
        slwi r0, value, 16
        cmpwi r9, 0
        or r0, r0, value
        subi r9, r9, 1
        beq loop_exit
    loop:
        stw r0, 0(dest)
        cmpwi r9, 0
        addi dest, dest, 4
        subi r9, r9, 1
        bne loop
    loop_exit:
        andi. r0, size, 1
        beqlr
        sth value, 0(dest)
    }
}
