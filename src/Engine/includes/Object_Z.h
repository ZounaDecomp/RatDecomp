#ifndef _OBJECT_Z_H_
#define _OBJECT_Z_H_
#include "ResourceObject_Z.h"
#include "SystemObject_Z.h"
#include "Collision_Z.h"
#include "Object_ZHdl.h"
#include "StaticArray_Z.h"

class Node_Z;

#define FL_OBJECTDATAS_CLONED (U32)(1 << 3)

/* sizeof(ObjectDatas_Z) == 0x28 */
class ObjectDatas_Z : public ResourceObject_Z {
public:
    ObjectDatas_Z();

    virtual ~ObjectDatas_Z() { }

    virtual void Load(void** i_Data);
    virtual Bool MarkHandles();
    virtual void UpdatePointers(Object_Z* i_Obj, S32 i_Param = -1);
    virtual void Clone(ObjectDatas_ZHdl& o_ObjectDatasHdl, Object_ZHdl& o_ObjectHdl);
    virtual void Draw(DrawInfo_Z& i_DrawInfo);
    virtual void HideObject(S32 i_Index);
    virtual void UnHideObject(S32 i_Index);
    virtual void SetShadowData(Node_Z* i_Node, const Vec3f& i_Origin, const ColLineResult_Z& i_Result, Float i_Radius);
    virtual void UpdateShadowData(Node_Z* i_Node, const Vec3f& i_Origin, Float i_Radius);
    virtual void UpdateReflectData(Node_Z* i_Node, const Vec3f& i_Origin);

    virtual void SetDfltColor(const Color& i_Color) {
        m_DefaultColor = i_Color;
    }

    virtual void SetDfltColorNoAlpha(const Color& i_Color);
    virtual void SetDfltColorAlpha(Float i_Alpha);
    virtual void FreeLightCacheEntry(U16 i_Index);

private:
    U32 m_Flag;
    Color m_DefaultColor;
};

/* sizeof(Object_Z) == 0x80 */
class Object_Z : public ResourceObject_Z {
public:
    Object_Z();

    // $SABE TODO: Vtable not getting generated atm?
    virtual void Init() { }

    virtual ~Object_Z() { }

    virtual void Load(void** i_Data);
    virtual void EndLoad();
    virtual void LoadLinks(void** i_Data);
    virtual void EndLoadLinks();
    virtual void Clean();
    virtual Bool MarkHandles();
    virtual void Draw(DrawInfo_Z& i_DrawInfo, ObjectDatas_Z* i_Data);

    virtual void DrawReceiveShadow(DrawInfo_Z& i_DrawInfo, ObjectDatas_Z* i_Data, S32 i_ObjID) { }

    virtual void DrawCastingShadow(DrawInfo_Z& i_DrawInfo, ObjectDatas_Z* i_Data);
    virtual void UpdateObject(Node_Z* i_Node, ObjectDatas_Z* i_Data);

    virtual Bool GetCollisionVLines(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Vec4f& i_Vec, ColLineResult_Z& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionLines(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Segment_Z& i_Seg, ColLineResult_Z& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetClingLines(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Segment_Z& i_Seg, ClingLineResult_Z& o_Result) {
        return FALSE;
    }

    virtual Bool GetCollisionSphere(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Sphere_Z& i_Seg, StaticArray_Z<ColSphereResult_Z, 256, 0, 1>& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionMovingSphere(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Capsule_Z& i_Cap, ColLineResult_Z& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionCapsule(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Capsule_Z& i_Cap, StaticArray_Z<ColSphereResult_Z, 128, 0, 1>& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionBoxes(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Sphere_Z& i_Sph, DynArray_Z<BoxFlag_Z, 8, 0, 0, 4>& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionTriangles(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Sphere_Z& i_Sph, DynArray_Z<TriangleFlag_Z, 8, 0, 0, 4>& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual Bool GetCollisionSpheres(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Sphere_Z& i_Sph, DynArray_Z<SphereFlag_Z, 8, 0, 0, 4>& o_Result, U64 i_Flag, U64 i_NoFlag) {
        return FALSE;
    }

    virtual S32 GetCollisions(Node_Z* i_Node, ObjectDatas_Z* i_Data, const Sphere_Z& i_Sph, const Vec3f& i_Dir, Float i_Len, ColLineResult_Z* o_Result, S32 i_MaxElem, U64 i_Flag, U64 i_NoFlag) {
        return 0;
    }

private:
    U8 m_Unk_0x14[12];
    Sphere_Z m_BSphereLocal;
    Box_Z m_BBoxLocal;
    Float m_FadeOutDistance;
    U32 m_Flag;
    U16 m_Type;
    ObjectDatas_ZHdl m_ObjectDataHdl;
};

#endif
