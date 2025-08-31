#ifndef _CLASSMANAGER_Z_H_
#define _CLASSMANAGER_Z_H_
#include "Handle_Z.h"

class ClassManager_Z : public HandleManager_Z {
public:
    void LoadLinkId(void* i_ID, void** i_Data);
    void UpdateLinkFromId(BaseObject_ZHdl& i_Hdl, S32 i_ID);
    void UpdateLink(BaseObject_ZHdl& i_Hdl);
    void LoadName(Name_Z&, void**);
    void LoadLink(BaseObject_ZHdl& i_Hdl, void** i_Data);

    Bool IsBigFileOpened() const { return m_IsBigFileOpened; }

    BaseObject_ZHdl& NewObject(const Name_Z& a1, const Name_Z& a2);

private:
    Char m_Unks[0x522];
    Bool m_IsBigFileOpened;
};

#endif
