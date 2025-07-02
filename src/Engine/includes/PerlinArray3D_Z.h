#ifndef _PERLINARRAY3D_Z_H_
#define _PERLINARRAY3D_Z_H_
#include "Macros_Z.h"
#include "Types_Z.h"
#include <cmath.h>

template <S32 SizeX, S32 SizeY, S32 SizeZ>
class PerlinArray3D_Z {
public:
    void Generate(Float i_UnkFloat, Float i_UnkFloat2, int i_UnkInt) {
        m_UnkFloat = i_UnkFloat;
        m_UnkInt = i_UnkInt;
        GenerateNoise();
        for (S32 z = 0, i = 0; z < SizeZ; ++z, ++i) {
            for (S32 y = 0, j = 0; y < SizeY; ++y, ++j) {
                for (S32 x = 0; x < SizeX; ++x) {
                    m_Noise[x + (j * SizeY) + (i * SizeX * SizeY)] = PerlinNoise(x, y, z, i_UnkFloat2);
                }
            }
        }
    }

    Float PerlinNoise(Float i_UnkFloat, Float i_UnkFloat2, Float i_UnkFloat3, Float i_UnkFloat4) {
        Float l_Scale = 2.0f;
        Float l_Noise = 0.0f;
        Float l_UnkFloatUsedInPowf = m_UnkFloat;

        Float l_Temp = i_UnkFloat4;

        for (S32 i = 0; i < m_UnkInt; i++) {
            Float l_Powf = (std::powf(l_UnkFloatUsedInPowf, i));
            Float l_NoiseVal = (InterpolatedNoise(i_UnkFloat * l_Temp, i_UnkFloat2 * l_Temp, i_UnkFloat3 * l_Temp));
            l_Noise = (l_Powf * l_NoiseVal + l_Noise);
            l_Temp *= l_Scale;
        }
        return l_Noise;
    }

    Float InterpolatedNoise(Float i_UnkFloat, Float i_UnkFloat2, Float i_UnkFloat3);
    Float GetNoiseValue(Float X, Float Y, Float Z);
    void GenerateNoise();

private:
    Float m_UnkFloat;
    S32 m_UnkInt;
    Float m_Noise[SizeX * SizeY * SizeZ];
    Float m_Noise2[SizeX * SizeY * SizeZ];
};

#endif
