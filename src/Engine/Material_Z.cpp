#include "Material_Z.h"
U32 Material_Z::DefaultRdrFlag = MAT_RDR_UNK23;

Material_Z::Material_Z() {
    m_RdrFlags2 = 0;
    m_WaterHeightMap = NULL;
    m_RdrFlags = DefaultRdrFlag;
    m_ColFlag = MAT_COL_UNK0 | MAT_COL_COLLIDABLE | MAT_COL_UNK2;
    m_ObjectFlags = 0;
    m_TextureFlags = 0;

    m_UVTransform.m.m[0][0] = 1.0f;
    m_UVTransform.m.m[0][1] = 0.0f;
    m_UVTransform.m.m[0][2] = 0.0f;
    m_UVTransform.m.m[0][3] = 0.0f;
    m_UVTransform.m.m[1][0] = 0.0f;
    m_UVTransform.m.m[1][1] = 1.0f;
    m_UVTransform.m.m[1][2] = 0.0f;
    m_UVTransform.m.m[1][3] = 0.0f;
    m_UVTransform.m.m[2][0] = 0.0f;
    m_UVTransform.m.m[2][1] = 0.0f;
    m_UVTransform.m.m[2][2] = 1.0f;
    m_UVTransform.m.m[2][3] = 0.0f;

    m_DiffuseOpacity = 1.0f;
    m_EmissiveColor = Vec3f(0.5f, 0.5f, 0.5f);
    m_DiffuseColor = Vec3f(0.5f, 0.5f, 0.5f);
    m_Rotation = -1.0f;
}
