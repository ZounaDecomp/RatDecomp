#ifndef _HANDLE_Z_H_
#define _HANDLE_Z_H_
#include "Types_Z.h"
#include "Name_Z.h"

class BaseObject_Z;
class BaseObject_ZHdl;
class HandleManager_Z;

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

class HandleManager_Z {
public:
    HandleManager_Z();

    BaseObject_Z* GetPtr(const BaseObject_ZHdl& i_Hdl) const;
};

#endif
