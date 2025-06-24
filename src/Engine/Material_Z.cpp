#include "Material_Z.h"
#include "ResourceObject_Z.h"
U32 Material_Z::DefaultRdrFlag = FL_MAT_RDR_UNK23;

Material_Z::Material_Z() {
    m_RdrFlags2 = 0;
    m_WaterHeightMap = NULL;
    m_RdrFlags = DefaultRdrFlag;
    m_ColFlag = FL_MAT_COL_UNK0 | FL_MAT_COL_COLLIDABLE | FL_MAT_COL_UNK2;
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

Material_Z::~Material_Z() {
    // $VIOLET: TODO: Implement this
}

Bool Material_Z::MarkHandles() {
    if (!ResourceObject_Z::MarkHandles()) {
        return FALSE;
    }
    else {
        for (S32 i = 0; i < mtl_nb_params; i++) {
            if (gData.ClassMgr->GetPtr(m_CurBmapHdl[i]) != NULL) {
                gData.ClassMgr->GetPtr(m_CurBmapHdl[i])->MarkHandles();
            }
        }
        return TRUE;
    }
}

void Material_Z::Clean() {
    // $VIOLET: TODO: Implement this.
}

void Material_Z::UpdateTMatrix() {
    // $VIOLET: TODO: Implement this.
}
