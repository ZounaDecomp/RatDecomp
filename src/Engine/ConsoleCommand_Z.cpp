#include "Console_Z.h"
#include "Memory_Z.h"
#include "Name_Z.h"

extern "C" S32 strlen(const Char* str);
void Console_Z::AddCommand(const Char* i_Command, CommandProc i_Proc, const Char* i_Desc) {
    S32 l_CommandName;
    Command_Z* l_Command = NewL_Z(26) Command_Z;
    Char l_Char;
    Char l_Alias[16];
    S32 l_AliasSize;
    Command_Z* l_CommandList;
    if (l_Command) {
        l_Command->m_Command = 0;
        l_Command->m_Alias = 0;
        l_Command->m_Proc = NULL;
        l_Command->m_Prev = 0;
    }

    if (i_Command) {
        l_CommandName = Name_Z::GetID(i_Command, 0);
    }
    else {
        l_CommandName = 0;
    }
    l_Command->m_Command = l_CommandName;
    l_AliasSize = 0;
    l_Command->m_Proc = i_Proc;

    for (S32 i = 0; i < strlen(i_Command) && l_AliasSize < 15; i++) {
        l_Char = i_Command[i];
        if (l_Char >= 'A' && l_Char <= 'Z' || l_Char >= '0' && l_Char <= '9') {
            l_Alias[i] = l_Char;
            l_AliasSize++;
        }
    }
    l_Alias[l_AliasSize] = 0;
    l_Command->m_Alias = Name_Z::GetID(l_Alias, 0);

    l_CommandList = m_CommandList;
    while (l_CommandList->m_Prev) {
        l_CommandList = l_CommandList->m_Prev;
    }
    if (l_CommandList) {
        l_CommandList->m_Prev = l_CommandList;
    }
    m_CommandList = l_CommandList;
}
