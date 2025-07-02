#include "Handle_Z.h"
#include "Program_Z.h"
#include "Node_Z.h"
#include "BoneNode_Z.h"
#include "Assert_Z.h"
#include "Math_Z.h"

void Node_Z::UpdateTM(Node_Z* i_Parent) {
    Mat4x4 l_LocalMatrix;
    m_Rotation.GetMatrix(l_LocalMatrix);
    l_LocalMatrix.m[0][0] *= m_Scale;
    l_LocalMatrix.m[1][0] *= m_Scale;
    l_LocalMatrix.m[2][0] *= m_Scale;
    l_LocalMatrix.m[3][0] = m_Translation.x;
    l_LocalMatrix.m[0][1] *= m_Scale;
    l_LocalMatrix.m[1][1] *= m_Scale;
    l_LocalMatrix.m[2][1] *= m_Scale;
    l_LocalMatrix.m[3][1] = m_Translation.y;
    l_LocalMatrix.m[0][2] *= m_Scale;
    l_LocalMatrix.m[1][2] *= m_Scale;
    l_LocalMatrix.m[2][2] *= m_Scale;
    l_LocalMatrix.m[3][2] = m_Translation.z;
    GetWorldMatrix() = i_Parent->GetWorldMatrix() * l_LocalMatrix;

    m_RotInWorld = i_Parent->GetRotInWorld() * m_Rotation;
    m_RotInWorld.GetMatrix(m_RotInWorldMatrix);
    EnableFlag(FL_NODE_INVALIDROT);

    m_UniformScale = m_Scale * i_Parent->GetUniformScale();
    m_InverseUniformScale = 1.0f / m_UniformScale;
}

void Node_Z::UpdateRootTM() {
    Mat4x4 l_LocalMatrix;
    m_Rotation.GetMatrix(l_LocalMatrix);
    l_LocalMatrix.m[0][0] *= m_Scale;
    l_LocalMatrix.m[1][0] *= m_Scale;
    l_LocalMatrix.m[2][0] *= m_Scale;
    l_LocalMatrix.m[3][0] = m_Translation.x;
    l_LocalMatrix.m[0][1] *= m_Scale;
    l_LocalMatrix.m[1][1] *= m_Scale;
    l_LocalMatrix.m[2][1] *= m_Scale;
    l_LocalMatrix.m[3][1] = m_Translation.y;
    l_LocalMatrix.m[0][2] *= m_Scale;
    l_LocalMatrix.m[1][2] *= m_Scale;
    l_LocalMatrix.m[2][2] *= m_Scale;
    l_LocalMatrix.m[3][2] = m_Translation.z;
    GetWorldMatrix() = l_LocalMatrix;

    m_RotInWorld = m_Rotation;
    m_RotInWorld.GetMatrix(m_RotInWorldMatrix);
    EnableFlag(FL_NODE_INVALIDROT);

    m_UniformScale = m_Scale;
    m_InverseUniformScale = 1.0f / m_Scale;
}

void BoneNode_Z::UpdateTM(BoneNode_Z* i_Parent) {
    Mat4x4 l_LocalMatrix;
    m_Rotation.GetMatrix(l_LocalMatrix);
    l_LocalMatrix.m[0][0] *= m_Scale.x;
    l_LocalMatrix.m[1][0] *= m_Scale.y;
    l_LocalMatrix.m[2][0] *= m_Scale.z;
    l_LocalMatrix.m[3][0] = m_Translation.x;
    l_LocalMatrix.m[0][1] *= m_Scale.x;
    l_LocalMatrix.m[1][1] *= m_Scale.y;
    l_LocalMatrix.m[2][1] *= m_Scale.z;
    l_LocalMatrix.m[3][1] = m_Translation.y;
    l_LocalMatrix.m[0][2] *= m_Scale.x;
    l_LocalMatrix.m[1][2] *= m_Scale.y;
    l_LocalMatrix.m[2][2] *= m_Scale.z;
    l_LocalMatrix.m[3][2] = m_Translation.z;
    GetWorldMatrix() = i_Parent->GetWorldMatrix() * l_LocalMatrix;

    m_RotInWorld = i_Parent->GetRotInWorld() * m_Rotation;
    m_RotInWorld.GetMatrix(m_RotInWorldMatrix);
    EnableFlag(FL_BONENODE_INVALIDROT);
}

void Node_Z::GetLocal(const Segment_Z& i_WorldSegment, Segment_Z& o_LocalSegment) {
    o_LocalSegment.Origin = GetInverseWorldMatrix() * i_WorldSegment.Origin;
    o_LocalSegment.Direction = GetInverseRotInWorld() * i_WorldSegment.Direction;
    o_LocalSegment.Length = i_WorldSegment.Length * m_InverseUniformScale;
}

void Node_Z::GetLocal(const Sphere_Z& i_Sph, Sphere_Z& o_Sph) {
}

void Node_Z::GetLocal(const Capsule_Z& i_Capsule, Capsule_Z& o_Capsule) {
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
