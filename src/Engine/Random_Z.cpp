#include "Random_Z.h"
#include "Types_Z.h"

Float ran1(S32* i_Seed) {
    S32 j;
    S32 l_Quotient;
    static S32 iy = NULL;
    static S32 iv[NTAB];
    Float temp;

    if (*i_Seed <= 0 || !iy) {
        if (-*i_Seed < 1)
            *i_Seed = 1;
        else
            *i_Seed = -*i_Seed;

        for (j = NTAB + 7; j >= 0; j--) {
            l_Quotient = *i_Seed / IQ;
            *i_Seed = IA * (*i_Seed - l_Quotient * IQ) - IR * l_Quotient;
            if (*i_Seed < 0)
                *i_Seed += IM;
            if (j < NTAB)
                iv[j] = *i_Seed;
        }
        iy = iv[0];
    }

    l_Quotient = *i_Seed / IQ;
    *i_Seed = IA * (*i_Seed - l_Quotient * IQ) - IR * l_Quotient;
    if (*i_Seed < 0)
        *i_Seed += IM;
    j = iy / NDIV;
    iy = iv[j];
    iv[j] = *i_Seed;
    if ((temp = (AM * iy)) > RNMX)
        return (Float)RNMX;
    else
        return temp;
}

S32 SEED;
gQRandomStruct_Z gQRandom;

void InitRandom(S32 i_Seed) {
    if (i_Seed < 0)
        SEED = i_Seed;
    else
        SEED = -i_Seed;

    ran1(&SEED);
}

S32 Alea(S32 i_Min, S32 i_Max) {
    int l_AddValue;
    Float l_Rand = ((0.9999f + (i_Max - i_Min)) * ran1(&SEED));
    if (l_Rand >= 0.0f) {
        l_AddValue = l_Rand;
    }
    else {
        l_AddValue = -l_Rand;
        l_AddValue = -l_AddValue;
    }
    return i_Min + l_AddValue;
}

Float Random() {
    return ran1(&SEED);
}

Float getPointFive() {
    return 0.5f;
}

Float getTwo() {
    return 2.0f;
}
