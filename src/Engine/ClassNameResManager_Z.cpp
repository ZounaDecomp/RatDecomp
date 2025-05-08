#include "ClassNameResManager_Z.h"

void ClassNameResManager_Z::Shut() {
    m_ClassHT.Flush();
    
    for (S32 i = m_ClassResHA.FindFirst(); i >= 0; i = m_ClassResHA.FindNext(i)) {
        m_ClassResHA[i].Flush();
    }
}

void ClassNameResManager_Z::Load(const Name_Z& i_Name, const Name_Z& i_FileName, void** i_Data) {
    S32 l_ClassID;
    GetClassID(i_Name, i_FileName, l_ClassID);
    m_ClassResHA[l_ClassID].Load(i_Data);
}

void ClassNameResManager_Z::UpdateLinks(const Name_Z& i_Name, const Name_Z& i_FileName) {
    S32 l_ClassID;
    GetClassID(i_Name, i_FileName, l_ClassID);
    m_ClassResHA[l_ClassID].UpdateLinks();
}

Bool ClassNameResManager_Z::GetClassID(const Name_Z& i_Name, const Name_Z& i_FileName, S32& o_ClassID, Bool i_AddClass) {
    o_ClassID = m_ClassResHA.FindFirst();

    while (o_ClassID >= 0) {
        if (i_Name == m_ClassResHA[o_ClassID].m_Name && i_FileName == m_ClassResHA.Get((U32)o_ClassID).m_FileName) {
            return TRUE;
        }

        o_ClassID = m_ClassResHA.FindNext(o_ClassID);
    }

    if (i_AddClass) {
        o_ClassID = m_ClassResHA.Add();
        m_ClassResHA[o_ClassID].m_Name = i_Name;
        m_ClassResHA[o_ClassID].m_FileName = i_FileName;
    }

    return FALSE;
}

Weak_Z ClassNameRes_Z::ClassNameRes_Z() {
    m_UnkS32_0x8 = -1;
}

Weak_Z HashS32Table_Z::HashTableBase_Z() {
    m_NbElem = 0;
    m_NbFree = 0;
    m_ScanID = -1;
    m_Status = NULL;
    m_Hash = NULL;
    Resize(HASHTABLE_DEFAULT_SIZE);
}

Bool ClassNameResManager_Z::MarkHandles() {
    S32 l_ClassID;
    l_ClassID = m_ClassResHA.FindFirst();

    while (l_ClassID >= 0) {
        m_ClassResHA[l_ClassID].MarkHandles();
        l_ClassID = m_ClassResHA.FindNext(l_ClassID);
    }
    return TRUE;
}

void ClassNameResManager_Z::MarkHandlesFromClass(const Name_Z& i_Name, const Name_Z& i_FileName) {
    S32 l_ClassID;
    if (GetClassID(i_Name, i_FileName, l_ClassID, FALSE)) {
        m_ClassResHA[l_ClassID].MarkHandles();
    }
}

Bool ClassNameResManager_Z::Minimize() {
    S32 l_ClassID;
    m_ClassHT.Minimize();
    m_ClassResHA.Minimize();
    l_ClassID = m_ClassResHA.FindFirst();
    while (l_ClassID >= 0) {
        m_ClassResHA[l_ClassID].Minimize();
        l_ClassID = m_ClassResHA.FindNext(l_ClassID);
    }
    return TRUE;
}

void ClassNameResManager_Z::RemoveClassId(const S32 i_ClassID )
{
    if (!m_ClassResHA.IsElement(i_ClassID))
    { 
        return;
    }

    m_ClassResHA[i_ClassID].Flush();
    m_ClassResHA.Remove(i_ClassID);
}

void ClassNameResManager_Z::RemoveClassId(const Name_Z& i_Name, const Name_Z& i_FileName) {
    S32 l_ClassID;
    if (GetClassID(i_Name, i_FileName, l_ClassID, FALSE)) {
        RemoveClassId(l_ClassID);
    }
}

BaseObject_ZHdl ClassNameResManager_Z::GetObjectInClass(const S32 i_ClassID, const S32 i_EnumID) {

}

void ClassNameRes_Z::Minimize() {
    m_ResourceHT.Minimize();
}

void ClassNameRes_Z::Load(void** l_Data) {

}

void ClassNameRes_Z::UpdateLinks() {

}

void ClassNameRes_Z::MarkHandles() {

}


// $SABE: Only here for now to match HashTableBase_Z::Insert
void dummy() {
    HashS32Table_Z tab;
    S32Hash_Z ele;
    tab.Insert(ele);
}
