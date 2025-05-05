#include "ClassNameResManager_Z.h"

void ClassNameResManager_Z::Shut() {
    m_ClassHT.Flush();
    
    for (S32 i = m_ClassResHA.FindFirst(); i >= 0; i = m_ClassResHA.FindNext(i)) {
        m_ClassResHA[i].Flush();
    }
}

void ClassNameResManager_Z::Load(const Name_Z& i_Name, const Name_Z& i_FileName, void** i_Data) {
    S32 l_ID;
    GetClassID(i_Name, i_FileName, l_ID);
    m_ClassResHA[l_ID].Load(i_Data);
}

void ClassNameResManager_Z::UpdateLinks(const Name_Z& i_Name, const Name_Z& i_FileName) {
    S32 l_ID;
    GetClassID(i_Name, i_FileName, l_ID);
    m_ClassResHA[l_ID].UpdateLinks();
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

Weak_Z HashS32Table_Z::HashTableBase_Z() {
    m_NbElem = 0;
    m_NbFree = 0;
    m_ScanID = -1;
    m_Status = NULL;
    m_Hash = NULL;
    Resize(HASHTABLE_DEFAULT_SIZE);
}

void ClassNameResManager_Z::MarkHandles() {

}

void ClassNameResManager_Z::Minimize() {

}

void ClassNameRes_Z::Load(void** l_Data) {

}

void ClassNameRes_Z::UpdateLinks() {

}

// $SABE: Only here for now to match HashTableBase_Z::Insert
void dummy() {
    HashS32Table_Z tab;
    S32Hash_Z ele;
    tab.Insert(ele);
}
