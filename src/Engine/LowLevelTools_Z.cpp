#include "Handle_Z.h"
#include "Program_Z.h"
#include "Node_Z.h"
#include "Assert_Z.h"
#include "Math_Z.h"

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
