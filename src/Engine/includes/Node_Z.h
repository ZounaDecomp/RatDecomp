#ifndef _NODE_Z_H_
#define _NODE_Z_H_
#include "BaseObject_Z.h"
#include "Bitmap_Z.h"
#include "Math_Z.h"
#include "Color_Z.h"
#include "Object_Z.h"
#include "ResourceObject_Z.h"
#include "SystemObject_Z.h"
#include "UserDefine_Z.h"
#include "Agent_ZHdl.h"
#include "Agent_Z.h"
#include "HFog_Z.h"

class LightData_Z;

class Node_Z : public ResourceObject_Z {
public:
    void UpdateRootTM();
    void UpdateTM(Node_Z* i_Parent);

    inline Quat& GetRotInWorld() { return m_RotInWorld; }

    inline void DisableFlag(U32 i_Flag) { m_Flag &= ~i_Flag; }

    inline Sphere_Z& GetBSphere() { return m_BSphere; }

    inline void SetBSphere(const Sphere_Z& i_Sph) { m_BSphere = i_Sph; }

    inline Mat3x3& GetRotInWorldMatrix() { return m_RotInWorldMatrix; }

private:
    Agent_ZHdl m_Agent;
    Mat4x4 m_InverseWorldMatrix;
    Mat3x3 m_RotInWorldMatrix;
    Mat3x3 m_InverseRotInWorldMatrxi;
    Quat m_RotInWorld;
    Vec3f m_Translation;
    S32 m_Flag;
    Quat m_Rotation;
    Float m_Scale;
    Float m_OtherScaleUsedInFrustrum;
    Float m_OneOverScale;
    S32 m_UnkRelatedToSeadRef;
    Color m_Color;
    Sphere_Z m_BSphere;
    Rect_Z m_DisplaySeadRect;
    Rect_Z m_CollideSeadRect;
    ObjectDatas_Z* m_ObjDatas;
    Object_Z* m_Object;
    UserDefine_Z* m_UserDefine;
    Node_Z* m_Parent;
    Node_Z* m_HeadSon;
    Node_Z* m_PrevSibling;
    Node_Z* m_NextSibling;
    LightData_Z* m_Light; // needs actually defined.
    HFogData_Z* m_FogData;
    Bitmap_Z* m_BitmapRadiosityRelated;
    BaseObject_Z* m_UnkObjPtr;
};

#endif
