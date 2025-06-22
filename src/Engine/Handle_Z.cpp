#include "Handle_Z.h"
#include "Main_Z.h"
#include "Program_Z.h"

HandleManager_Z::HandleManager_Z() {
}

S32 HandleManager_Z::HandleToU32(const BaseObject_ZHdl& i_Hdl) {
    return i_Hdl.m_RealID.GblID;
}

// $VIOLET: TODO: Finish this
BaseObject_ZHdl HandleManager_Z::CreateNewHandle(BaseObject_Z* i_BObj, const Name_Z& i_Name, S16 i_ClassID, U8 i_Flag) {
    Name_Z l_Name;
    S32 l_FreeRecID;
    if (m_NbFree == 0) {
        ExpandSize(0x4000);
    }

    l_Name = i_Name;

    l_FreeRecID = m_FreeRecDA[m_NbFree--];
    HandleRec_Z& l_Rec = m_HandleRecDA[l_FreeRecID];
    l_Rec.m_ObjPtr = i_BObj;
    l_Rec.m_Name = l_Name;
    l_Rec.m_xRamBlock = -1;
    l_Rec.m_ClassID = i_ClassID;
    l_Rec.m_Flag = i_Flag;
    l_Rec.m_Marked = TRUE;

    i_BObj->SetHandle(l_FreeRecID, l_Rec.m_Key);
    i_BObj->SetName(l_Name, FALSE);
    i_BObj->AfterEndLoad();
    AddResourceRef(l_Rec, l_FreeRecID);
    return i_BObj->GetHandle();
}

void HandleManager_Z::MarkU32Handle(U32 i_Hdl) {
    Bool l_Result = FALSE;
    U32 l_ID;
    S8 l_Key;

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
