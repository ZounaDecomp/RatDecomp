#include "Handle_Z.h"
#include "Main_Z.h"
#include "Program_Z.h"

BaseObject_ZHdl::operator BaseObject_Z*() const {
    return GETPTR(*this);
}

HandleManager_Z::HandleManager_Z() {
}

S32 HandleManager_Z::HandleToU32(const BaseObject_ZHdl& i_Hdl) {
    return i_Hdl.m_RealID.GblID;
}

void HandleManager_Z::MarkU32Handle(U32 i_Hdl) {
    S32 l_ID;
    S8 l_Key;
    Bool l_Result = FALSE;

    l_ID = ((BaseObject_ZHdl*)&i_Hdl)->GetID();
    if (l_ID < m_HandleRecDA.GetSize()) {
        l_Key = ((BaseObject_ZHdl*)&i_Hdl)->GetKey();
        if (l_Key == m_HandleRecDA[l_ID].m_Key) {
            l_Result = TRUE;
        }
    }
    if (l_Result) {
        m_HandleRecDA[l_ID].m_ObjPtr->MarkHandles();
    }
    return;
}
