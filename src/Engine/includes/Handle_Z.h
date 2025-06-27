#ifndef _HANDLE_Z_H_
#define _HANDLE_Z_H_
#include "Types_Z.h"
#include "Name_Z.h"
#include "DynArray_Z.h"
#include "HashTable_Z.h"
//#include "Global_Z.h"

#define HandleGranularity 16384
#define HANDLE_NULL BaseObject_ZHdl(0);

class BaseObject_Z;
class BaseObject_ZHdl;
class HandleManager_Z;
class DrawInfo_Z;
class GCGlobals;
extern GCGlobals gData;

#define GETPTR(h) gData.ClassMgr->GetPtr(h)

#define HANDLE_Z(ClassName, ParentName)                          \
    class ClassName##Hdl;                                        \
    class ClassName##Hdl : public ParentName##Hdl {              \
    private:                                                     \
    public:                                                      \
        ClassName##Hdl(void) {                                   \
            m_RealID.GblID = 0;                                  \
        }                                                        \
        ClassName##Hdl(const ClassName##Hdl& i_Org) {            \
            m_RealID.GblID = i_Org.m_RealID.GblID;               \
        }                                                        \
        ClassName##Hdl(const BaseObject_ZHdl& i_Org) {           \
            ClassName##Hdl* Ptr = (ClassName##Hdl*)&i_Org;       \
            m_RealID.GblID = Ptr->m_RealID.GblID;                \
        }                                                        \
        ClassName##Hdl& operator=(const ClassName##Hdl& i_Org) { \
            m_RealID.GblID = i_Org.m_RealID.GblID;               \
            return *this;                                        \
        }                                                        \
        ClassName##Hdl(int i_Val) {                              \
            m_RealID.GblID = i_Val;                              \
        }                                                        \
        ClassName* operator->() const {                          \
            return (ClassName*)GETPTR((BaseObject_ZHdl&)*this);  \
        }                                                        \
        operator ClassName*() const {                            \
            return (ClassName*)GETPTR((BaseObject_ZHdl&)*this);  \
        }                                                        \
    }

union HdlID {
    S32 GblID;

    struct {
        S32 Key : 8,
            ID : 24;
    } Ref;
};

class BaseObject_ZHdl {
    friend class HandleManager_Z;
    friend class BaseObject_Z;

public:
    BaseObject_ZHdl() {
        m_RealID.GblID = 0;
    }

    BaseObject_ZHdl(const S32 i_Val) {
        m_RealID.Ref.ID = i_Val;
        m_RealID.Ref.Key = (S8)i_Val;
    }

    S32 GetID() const {
        return m_RealID.Ref.ID;
    }

    S8 GetKey() const {
        return m_RealID.Ref.Key;
    }

    Bool IsValid() {
        BaseObject_Z* l_Ptr = *this;
        return l_Ptr != NULL;
    }

    operator BaseObject_Z*() const;

private:
protected:
    HdlID m_RealID;
};

struct HandleRec_Z {
    S8 m_Key;
    S8 m_Flag;
    Bool m_Marked;
    BaseObject_Z* m_ObjPtr;
    Name_Z m_Name;
    S16 m_ClassID;
    S16 m_xRamBlock;
};

class HandleManager_Z {
public:
    DynArray_Z<HandleRec_Z, HandleGranularity> m_HandleRecDA;
    DynArray_Z<S32, HandleGranularity> m_FreeRecDA;
    HashS32Table_Z m_Placeholder_NameToIdHashtable;
    U32 m_HandleRecDASize;
    S32 m_NbFree;
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

    BaseObject_Z* GetPtr(const BaseObject_ZHdl& i_Hdl) const;
    BaseObject_Z* GetPtrXRam(const HandleRec_Z&) const;
    BaseObject_ZHdl U32ToHandle(S32 i_Value);
    S32 HandleToU32(const BaseObject_ZHdl& i_Hdl);
    void MarkU32Handle(U32 i_Hdl);
    Bool MarkHandle(const BaseObject_ZHdl&);
    void ForbidCheckHandles(Bool i_ForbidCheckHandles);
    BaseObject_ZHdl CreateNewHandle(BaseObject_Z* i_BObj, const Name_Z& i_Name, S16 i_ClassID, U8 i_Flag);
    void ExpandSize(S32 i_NewSize);
    void AddResourceRef(const HandleRec_Z&, S32 i_IDInDA);

    inline Name_Z& GetHandleName(const BaseObject_ZHdl& i_Hdl) {
        int l_ID = i_Hdl.GetID();
        int l_Key = i_Hdl.GetKey();

        if (CheckKey(l_ID, l_Key)) {
            return m_HandleRecDA[l_ID].m_Name;
        }

        return m_NullName;
    }

    inline Bool CheckKey(int i_ID, int i_Key) const {
        return (i_ID < m_HandleRecDA.GetSize() && m_HandleRecDA[i_ID].m_Key == i_Key);
    }
};

#endif
