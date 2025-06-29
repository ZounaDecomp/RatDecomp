#include "MathTools_Z.h"
extern const Float Pi;
#define PI Pi
#define PI2 (PI / 2.0f)
#define TABLESIZE_COS 32
#define BITCOUNT_INVSQRT 7
#define BITCOUNT_ACOS 6
#define TABLESIZE_INVSQRT (1 << BITCOUNT_INVSQRT)
#define TABLESIZE_ACOS (1 << BITCOUNT_ACOS)
static Float gTableAcos[TABLESIZE_ACOS];
static Float gTableCos[TABLESIZE_COS + 1];
static U8 gTable1InvSqrt[TABLESIZE_INVSQRT];

void MathInitTables() {
    int i;

    for (i = 0; i <= TABLESIZE_COS; ++i) {
        Float angle = i * (PI2 / TABLESIZE_COS);
        gTableCos[i] = cos(angle);
    }

    for (i = 0; i < TABLESIZE_INVSQRT; ++i) {
        U32 l_UnkNum = (127UL << 23) + (i << (23 - BITCOUNT_INVSQRT));
        Float l_FloatNum = *(Float*)&l_UnkNum;
        l_FloatNum = (Float)(1.0 / sqrtf(l_FloatNum));
        l_UnkNum = *(U32*)&l_FloatNum;
        gTable1InvSqrt[i] = (U8)((l_UnkNum >> (23 - 8)) & 0xffUL);
    }

    for (i = 0; i < TABLESIZE_ACOS; ++i) {
        U32 l_UnkNum = (0x7UL << 27) | (i << (27 - BITCOUNT_ACOS));
        Float l_FloatNum = *(Float*)&l_UnkNum;
        gTableAcos[i] = (Float)acos(1.F - l_FloatNum);
    }
}
