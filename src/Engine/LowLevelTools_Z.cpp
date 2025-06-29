#include "Handle_Z.h"
#include "Program_Z.h"
#include "Node_Z.h"
#include "Assert_Z.h"
#include "Math_Z.h"

void Node_Z::UpdateTM(Node_Z* i_Parent) {
    Mat4x4 l_LocalMatrix;
    Mat4x4 l_LocalMatrix2;
    m_Rotation.GetMatrix(l_LocalMatrix);
    Float l_Scale = m_Scale;
    l_LocalMatrix2.m[0][0] = l_LocalMatrix2.m[0][0] * l_Scale;
    l_LocalMatrix2.m[1][0] = l_LocalMatrix2.m[1][0] * l_Scale;
    l_LocalMatrix2.m[2][0] = l_LocalMatrix2.m[2][0] * l_Scale;
    l_LocalMatrix2.m[0][1] = l_LocalMatrix2.m[0][1] * l_Scale;
    l_LocalMatrix2.m[1][1] = l_LocalMatrix2.m[1][1] * l_Scale;
    l_LocalMatrix2.m[2][1] = l_LocalMatrix2.m[2][1] * l_Scale;
    l_LocalMatrix2.m[0][2] = l_LocalMatrix2.m[0][2] * l_Scale;
    l_LocalMatrix2.m[1][2] = l_LocalMatrix2.m[1][2] * l_Scale;
    l_LocalMatrix2.m[2][2] = l_LocalMatrix2.m[2][2] * l_Scale;
    l_LocalMatrix2.m[3][0] = m_Translation.x;
    l_LocalMatrix2.m[3][1] = m_Translation.y;
    l_LocalMatrix2.m[3][2] = m_Translation.z;

    l_LocalMatrix = (*(Mat4x4*)m_RotInWorldMatrix.m.m13.dummy.i32) * l_LocalMatrix2;
    Mat4x4* l_WorldMatrix = (Mat4x4*)m_RotInWorldMatrix.m.m13.dummy.i32;

    l_WorldMatrix->m[0][0] = l_LocalMatrix.m[0][0];
    l_WorldMatrix->m[0][1] = l_LocalMatrix.m[0][1];
    l_WorldMatrix->m[0][2] = l_LocalMatrix.m[0][2];
    l_WorldMatrix->m[0][3] = l_LocalMatrix.m[0][3];
    l_WorldMatrix->m[1][0] = l_LocalMatrix.m[1][0];
    l_WorldMatrix->m[1][1] = l_LocalMatrix.m[1][1];
    l_WorldMatrix->m[1][2] = l_LocalMatrix.m[1][2];
    l_WorldMatrix->m[1][3] = l_LocalMatrix.m[1][3];
    l_WorldMatrix->m[2][0] = l_LocalMatrix.m[2][0];
    l_WorldMatrix->m[2][1] = l_LocalMatrix.m[2][1];
    l_WorldMatrix->m[2][2] = l_LocalMatrix.m[2][2];
    l_WorldMatrix->m[2][3] = l_LocalMatrix.m[2][3];
    l_WorldMatrix->m[3][0] = l_LocalMatrix.m[3][0];
    l_WorldMatrix->m[3][1] = l_LocalMatrix.m[3][1];
    l_WorldMatrix->m[3][2] = l_LocalMatrix.m[3][2];
    l_WorldMatrix->m[3][3] = l_LocalMatrix.m[3][3];
    
    m_RotInWorld *= m_Rotation;
    m_RotInWorld.GetMatrix(m_RotInWorldMatrix);
    m_Flag |= 0x10; // $VIOLET: TODO: Define this flag. Possibly FL_NODE_HAS_SCALE?
    m_OtherScaleUsedInFrustrum *= m_Scale;
    m_OneOverScale = 1.0f / m_OtherScaleUsedInFrustrum;

}

BaseObject_Z* HandleManager_Z::GetPtr(const BaseObject_ZHdl& i_Hdl) const {
    const HandleRec_Z& l_HdlRec = m_HandleRecDA[i_Hdl.GetID()];
    if (l_HdlRec.m_Key == i_Hdl.GetKey()) {
        if (l_HdlRec.m_xRamBlock >= 0) {
            return gData.ClassMgr->GetPtrXRam(l_HdlRec);
        }
        return l_HdlRec.m_ObjPtr;
    }
    return NULL;
}
