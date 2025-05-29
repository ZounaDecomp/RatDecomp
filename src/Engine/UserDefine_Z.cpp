#include "UserDefine_Z.h"
#include "Memory_Z.h"
#include "ResourceObject_Z.h"
#include "Sys_Z.h"
#include "Types_Z.h"
Extern_Z "C" int strlen(char* Str);
Extern_Z "C" void memcpy(void *dst, const void *src, int n);
UserDefine_Z::UserDefine_Z() {
    m_Cmd.m_UserDatas = NULL;
    m_Cmd.m_DataSize = 0;
}

UserDefine_Z::~UserDefine_Z() {
    if (&m_Cmd.m_UserDatas != NULL && m_Cmd.m_UserDatas) {
        Free_Z(m_Cmd.m_UserDatas);
        m_Cmd.m_DataSize = 0;
    }
}

void UserDefineCmd_Z::MakeCommandList() {
    Char* l_CurrentChar;
    S32 l_NewDataSize = 0;
    int i;
    for (i = 0; i < m_DataSize; i++) {
        if (m_UserDatas[i] == '[' || m_UserDatas[i] == ']') 
            continue;
        if (m_UserDatas[i] == ';')
            l_NewDataSize++;

        l_NewDataSize++;
    }
    Char* l_NewUserData = (Char*)AllocL_Z(l_NewDataSize + 1, 137);
    int j = 0;
    for (i = 0; i < m_DataSize; i++) {
        if (m_UserDatas[i] == '[' || m_UserDatas[i] == ']') 
            continue;
        if (m_UserDatas[i] == ';') {
            l_NewUserData[j++] = '\n';
            l_NewUserData[j++] = '\r';
            continue;
        }

        l_NewUserData[j++] = m_UserDatas[i];
    }
    l_NewUserData[j] = 0;
    Free_Z(m_UserDatas);
    m_UserDatas = l_NewUserData;
    m_DataSize = l_NewDataSize;

}

Char *UserDefineCmd_Z::GetFirstCommand(U32 &o_Length)
{
    m_CurLen = 0;
    return GetNextCommand(o_Length);
}

Char* UserDefineCmd_Z::GetNextCommand(U32& o_Length)
{
    o_Length= 0;

    if (m_CurLen>=m_DataSize)
        return NULL;

    for (int i=m_CurLen; i<m_DataSize; i++)
    {
        if (m_UserDatas[i]=='\n')
            break;
        o_Length++;
    }

    m_CurLen += o_Length;
    S32 l_Pos=m_CurLen-o_Length;

    while ((m_CurLen < m_DataSize) && ((m_UserDatas[m_CurLen] == 13) || (m_UserDatas[m_CurLen] == 10) || (m_UserDatas[m_CurLen] == 32)))    m_CurLen++;

    return &m_UserDatas[l_Pos];
}

#pragma dont_inline on
void UserDefine_Z::Load(void** i_Data) {
    S32 l_DataLength;
    *i_Data = Sys_Z::MemCpyFrom(&l_DataLength, *i_Data, 4);
    Char* l_Data = (Char*)*i_Data;
    
    if (l_DataLength == -1) {
        m_Cmd.m_DataSize = strlen(l_Data);
    }
    else {
        m_Cmd.m_DataSize = l_DataLength;
    }

    if (m_Cmd.m_UserDatas) {
        Free_Z(m_Cmd.m_UserDatas);
        m_Cmd.m_UserDatas = NULL;
    }

    if ( m_Cmd.m_DataSize) {
        m_Cmd.m_UserDatas = (Char*)AllocL_Z( m_Cmd.m_DataSize, 42);
        memcpy(m_Cmd.m_UserDatas, l_Data, m_Cmd.m_DataSize);
        m_Cmd.MakeCommandList();
    }
    *(U32*)i_Data += l_DataLength;
}
#pragma dont_inline reset

static const char* s_Unused = "UserDefine_Z.h";
