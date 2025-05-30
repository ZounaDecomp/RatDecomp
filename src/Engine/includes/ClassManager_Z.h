#ifndef _CLASSMANAGER_Z_H_
#define _CLASSMANAGER_Z_H_
#include "Handle_Z.h"

class ClassManager_Z : public HandleManager_Z {
public:
    void LoadLinkId(void* i_ID, void** i_Data);
    void UpdateLinkFromId(BaseObject_ZHdl& i_Hdl, S32 i_ID);
    void LoadName(Name_Z&, void**);
};

#endif
