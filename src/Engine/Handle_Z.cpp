#include "Handle_Z.h"
#include "Main_Z.h"
#include "Program_Z.h"

#define HANDLEREC_GRANULARITY 16384

HandleManager_Z::HandleManager_Z() {
    m_NbFree = 0;
    m_HandleRecDASize = 0;
    ExpandSize(HANDLEREC_GRANULARITY);
    m_UnkS32_0x44 = 0;
    m_UnkBool_SetsDeltaTimeTo30fps_0x34 = FALSE;
    m_DoAsynchCheckHandles = FALSE;
    m_LastDeleteFrameNb = -1;
    m_CheckHandlesQueued = FALSE;
    m_ForbidCheckHandles = FALSE;
}

S32 HandleManager_Z::HandleToU32(const BaseObject_ZHdl& i_Hdl) {
    return i_Hdl.m_RealID.GblID;
}

const BaseObject_ZHdl& HandleManager_Z::CreateNewHandle(BaseObject_Z* i_ObjPtr, const Name_Z& i_Name, S16 i_ClassID, U8 i_Flag) {
    if (!m_NbFree) {
        ExpandSize();
    }

    int l_FreeRecID = m_FreeRecDA[--m_NbFree];

    HandleRec_Z& l_Rec = m_HandleRecDA[l_FreeRecID];
    l_Rec.m_ObjPtr = i_ObjPtr;
    l_Rec.m_Name = i_Name;
    l_Rec.m_xRamBlock = -1;
    l_Rec.m_ClassID = i_ClassID;
    l_Rec.m_Flag = i_Flag;
    l_Rec.m_Marked = HANDLE_MARKED_UNK;

    i_ObjPtr->SetHandle(l_FreeRecID, l_Rec.m_Key);
    i_ObjPtr->SetName(i_Name);

    i_ObjPtr->Init();
    AddResourceRef(l_Rec, l_FreeRecID);

    return i_ObjPtr->GetHandle();
}

void HandleManager_Z::DeleteHandle(const BaseObject_ZHdl& i_Hdl) {
    U32 l_ID = i_Hdl.GetID();
    HandleRec_Z& l_Rec = m_HandleRecDA[l_ID];

    if (l_Rec.m_xRamBlock != -1) {
        gData.XRamMgr->FreeBlock(l_Rec.m_xRamBlock);
    }
    l_Rec.m_xRamBlock = -1;

    RemoveResourceRef(l_Rec);

    l_Rec.m_Marked = HANDLE_MARKED_FALSE;
    l_Rec.m_ClassID = -1;

    Delete_Z l_Rec.m_ObjPtr;

    l_Rec.m_Name = m_NullName;
    l_Rec.m_Key++;
    if (l_Rec.m_Key == 0) {
        l_Rec.m_Key++;
    }

    l_Rec.m_AsyncRelated = FALSE;
    l_Rec.m_Flag = l_Rec.m_Flag & 0xfe;
    l_Rec.m_ObjPtr = NULL;

    m_FreeRecDA[m_NbFree++] = l_ID;
}

// $SABE TODO: Fix match %, believed cause is inlined BitArray_Z::GetBit in HashTableBase_Z::Supress
void HandleManager_Z::RemoveResourceRef(const HandleRec_Z& i_HandleRec) {
    if (i_HandleRec.m_Flag & 0x8) {
        S32Hash_Z l_HashElt(i_HandleRec.m_Name.GetID());
        Bool l_Result = m_HandleIdHT.Suppress(l_HashElt);
        ASSERTLE_Z(l_Result, "", 121, "bResult");
    }
}

void HandleManager_Z::AddResourceRef(const HandleRec_Z& i_HandleRec, S32 i_Index) {
    if (i_HandleRec.m_Flag & 0x8) {
        S32Hash_Z l_HashElt(i_HandleRec.m_Name.GetID(), i_Index);
        Bool l_Result = m_HandleIdHT.Insert(l_HashElt);
        ASSERTLE_Z(gData.m_UpdatingResource || l_Result, "", 131, "gData.UpdatingResource || bResult");
    }
}

// $SABE TODO: Fix match %, believed cause is inlined BitArray_Z::GetBit in HashTableBase_Z::Search
S32 HandleManager_Z::IsResourceRef(S32 i_Hdl) {
    S32Hash_Z l_HashElt(i_Hdl);
    const S32Hash_Z* l_Result = m_HandleIdHT.Search(l_HashElt);
    if (l_Result) {
        return l_Result->m_Value;
    }
    return -1;
}

S32 HandleManager_Z::ChangeHandleName(const BaseObject_ZHdl& i_Hdl, const Name_Z& i_Name) {
    int l_ID = i_Hdl.GetID();
    int l_Key = i_Hdl.GetKey();

    if (CheckKey(l_ID, l_Key)) {
        HandleRec_Z l_HandleRec = m_HandleRecDA[i_Hdl.GetID()];
        ASSERTLE_Z(!(l_HandleRec.m_Flag & HandleRec_Z::RSC), "", 157, "!(HdlRec.Flag&HandleRec_Z::RSC)");
        l_HandleRec.m_Name = i_Name;
        return TRUE;
    }
    return FALSE;
}

void HandleManager_Z::MarkU32Handle(U32 i_Hdl) {
    Bool l_Result = FALSE;
    int l_ID;
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
