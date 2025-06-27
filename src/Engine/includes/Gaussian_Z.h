#ifndef _GAUSSIAN_Z_H_
#define _GAUSSIAN_Z_H_
#include "Types_Z.h"
#include "Math_Z.h"

struct MipmapGC {
    Vec3f m_Vecs[16]; // $VIOLET: not certain its vecs
};

S32 Compute_MipmapedGaussConvol(MipmapGC* i_Mip, int i_SizeX, int i_SizeY, Float i_UnkFloat, Float i_UnkFloat2); // $VIOLET: Maybe i_Sigma and i_Alpha? idrk

#endif
