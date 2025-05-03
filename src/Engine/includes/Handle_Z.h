#ifndef _HANDLE_Z_H_
#define _HANDLE_Z_H_
#include "Types_Z.h"
#include "Name_Z.h"
#include "DynArray_Z.h"
#include "HashTable_Z.h"

#define HandleGranularity 16384

class BaseObject_Z;
class BaseObject_ZHdl;
class HandleManager_Z;
class DrawInfo_Z;

#define GETPTR(a) gData.ClassMgr->GetPtr(a)

union HdlID {
    U32 GblID;

    struct {
        U32 Key : 8,
            ID : 24;
    } Ref;
};

class BaseObject_ZHdl {
public:
    BaseObject_ZHdl() {
        m_RealID.GblID = 0;
    }

    U32 GetID() {
        return m_RealID.Ref.ID;
    }

    U32 GetKey() {
        return m_RealID.Ref.Key;
    }

    operator BaseObject_Z*() const;
protected:
    HdlID m_RealID;
};

struct HandleRec_Z {
    U8 m_Key;
    U8 m_Flag;
    Bool m_Marked;
    BaseObject_Z* m_ObjPtr;
    Name_Z m_Name;
    S16 m_ClassID;
    S16 m_xRamBlock;
};

class HandleManager_Z {
public:
    virtual void CheckHandles();
    virtual void MarkHandles(S32 a1);
    virtual void Update(Float a1);
    virtual void Draw(DrawInfo_Z& a1);
    virtual void Minimize();
    virtual void ClearMark();
    virtual void InvalidClassSize(S16 const a1);
    virtual void RemoveResource(const BaseObject_ZHdl& a1);
    virtual void ChangeHandleName(const BaseObject_ZHdl& a1, const Name_Z& a2);
    virtual void DeleteHandle(const BaseObject_ZHdl& a1);
    virtual void GetNameStrFromId(const Name_Z& a1);

    DynArray_Z<HandleRec_Z, HandleGranularity> m_HandleRecDA;
    DynArray_Z<S32, HandleGranularity> m_FreeRecDA;
    HashS32Table_Z m_Placeholder_NameToIdHashtable[0x10];
    S32 m_UnkS32_0x20; // $SABE: Looks unused
    U32 m_HandleRecDASize;
    U32 m_NbFree;
    Name_Z m_NullName;
    BaseObject_ZHdl m_NullHandle;
    Bool m_UnkBool_SetsDeltaTimeTo30fps_0x34;
    Bool m_DoAsynchCheckHandles;
    Bool m_ForbidCheckHandles;
    Bool m_CheckHandlesQueued;
    S32 m_NextHandleToDelete;
    S32 m_NextManagerToMarkHandles;
    U32 m_LastDeleteFrameNb;
    S32 m_UnkS32_0x44; // $SABE: Gets tested in HandleManager_Z::MarkHandle but never passes
    U32 m_FramesSpentDeleting;

    HandleManager_Z();

    BaseObject_Z* GetPtr(const BaseObject_ZHdl& i_Hdl) const;
};

#endif
