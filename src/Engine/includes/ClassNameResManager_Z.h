#ifndef _CLASSNAMERESMANAGER_Z_H_
#define _CLASSNAMERESMANAGER_Z_H_
#include "HashTable_Z.h"
#include "HoleArray_Z.h"

class ClassNameRes_Z {
public:
    Name_Z m_Name;
    Name_Z m_FileName;
    S32 m_UnkS32_0x8;
    HashS32Table_Z m_ResourceHT;

    ClassNameRes_Z();

    void Flush() {
        m_ResourceHT.Flush();
    }

    void Load(void** l_Data);
    void UpdateLinks();
};

class ClassNameResManager_Z {
    HashName_ZTable_Z m_ClassHT;
    HoleArray_Z<ClassNameRes_Z, 32> m_ClassResHA;

public:
    ClassNameResManager_Z() : m_ClassHT(64) {
    }

    void** Load(const Name_Z& i_Name, const Name_Z& i_FileName, void** i_Data);
    void UpdateLinks(const Name_Z& i_Name, const Name_Z& i_FileName);
    Bool GetClassID(const Name_Z& i_Name, const Name_Z& i_FileName, S32& o_ClassID, Bool i_AddClass = TRUE);

    virtual void Shut();
    virtual void MarkHandles();
    virtual void Minimize();
};

#endif
