#ifndef _USERDEFINE_Z_H_
#define _USERDEFINE_Z_H_
#include "ResourceObject_Z.h"

class UserDefineCmd_Z {
public:
    void MakeCommandList();            
    Char* GetNextCommand(U32& o_Length);
    Char* GetFirstCommand(U32 &o_Length);
    Char* m_UserDatas;
    S32 m_DataSize;
    S32 m_CurLen;
};

class UserDefine_Z : public ResourceObject_Z {
    UserDefine_Z();
    virtual ~UserDefine_Z();
    void Load(void** i_Data);
private:
    UserDefineCmd_Z m_Cmd;
};

#endif
