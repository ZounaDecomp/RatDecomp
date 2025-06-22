#ifndef _USERDEFINE_Z_H_
#define _USERDEFINE_Z_H_
#include "ResourceObject_Z.h"

Extern_Z "C" void memcpy(void* dst, const void* src, int n);

class UserDefineCmd_Z {
public:
    void SetCmd(Char* i_UserDatas, S32 i_DataSize) {
        if (i_DataSize == -1) {
            m_DataSize = strlen(i_UserDatas);
        }
        else {
            m_DataSize = i_DataSize;
        }

        if (m_UserDatas) {
            Free_Z(m_UserDatas);
            m_UserDatas = NULL;
        }

        if (m_DataSize) {
            m_UserDatas = (Char*)AllocL_Z(m_DataSize, 42);
            memcpy(m_UserDatas, i_UserDatas, m_DataSize);
            MakeCommandList();
        }
    }

    Char* GetNextCommand(U32& o_Length);
    Char* GetFirstCommand(U32& o_Length);
    void MakeCommandList();
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
