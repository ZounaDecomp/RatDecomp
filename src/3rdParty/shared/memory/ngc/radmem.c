#include "radmem.h"
#include "os/OSAlloc.h"

#pragma optimizewithasm off
asm void RADSetMemory(register RADMEMALLOC malloc_fn, register RADMEMFREE free_fn) {
    lis r9, usermalloc@ha
    lis r11, userfree@ha
    stw r3, usermalloc@l(r9)
    stw r4, userfree@l(r11)
}

asm void* radmalloc(register U32 size)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    stw r31, 0xc(r1)
    stw r0, 0x14(r1)
    mr. r3, r3
    beq ret0
    cmpwi r3, -0x1
    beq ret0
    lis r9, usermalloc@ha
    addi r31, r3, 0x40
    lwz r0, usermalloc@l(r9)
    cmpwi r0, 0x0
    beq osHeapAlloc
    mr r3, r31
    mtlr r0
    blrl
    mr. r3, r3
    beq osHeapAlloc
    cmpwi r3, -0x1
    beq ret0
    li r9, 0x3
    b setupPreMallocInfo
osHeapAlloc:
    lis r9, __OSCurrHeap@ha
    mr r4, r31
    lwz r3, __OSCurrHeap@l(r9)
    bl OSAllocFromHeap
    mr. r3, r3
    bne setFlag
ret0:
    li r3, 0
    b ret
setFlag:
    li r9, 0
setupPreMallocInfo:
    clrlwi r0, r3, 27
    cmpwi r9,3 
    subfic r0, r0, 0x40
    clrlwi r0, r0, 24
    add r3, r3, r0
    stb r0, -1(r3)
    stb r9, -2(r3)
    bne ret
    lis r9, userfree@ha
    lwz r0, userfree@l(r9)
    stw r0, -8(r3)
ret:
    lwz r0, 0x14(r1)
    mtlr r0
    lwz r31, 0xc(r1)
    addi r1, r1, 0x10
    blr
}

asm void radfree(register void* ptr) {
    // this should autogenerate??
    nofralloc
    stwu r1,-8(r1)
    mflr r0
    stw r0,0xc(r1)
    mr. r11, ptr
    beq exit
    lbz r0,-2(r11)
    cmpwi r0,3
    bne free
    lbz r3,-1(r11)
    lwz r9,-8(r11)
    subf r3,r3,r11
    mtlr r9
    blrl
    b exit
free:
    lis r9,__OSCurrHeap@ha
    lbz r4,-1(r11)
    lwz r3,__OSCurrHeap@l(r9)
    subf r4,r4,r11
    bl OSFreeToHeap
exit:
    lwz r0,0xc(r1)
    mtlr r0
    addi r1,r1,8
    blr
}
