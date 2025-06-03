#include "Console_Z.h"
#include "Memory_Z.h"
#include "Name_Z.h"

void Console_Z::DisplayHelp() {
    return;
}

void Console_Z::AddCommand(const Char* i_Command, CommandProc i_Proc, const Char* i_Desc) {
    Command_Z* l_Command = NewL_Z(26) Command_Z;
    if (l_Command) {
        l_Command->m_Command = 0;
        l_Command->m_Alias = 0;
        l_Command->m_Prev = NULL;
        l_Command->m_Proc = NULL;
    }

    l_Command->m_Command = i_Command ? Name_Z::GetID(i_Command, 0) : 0;
    l_Command->m_Proc = i_Proc;
    
    Char l_Alias[16];
    S32 l_AliasSize = 0;

    S32 len = strlen(i_Command);
    
    char* l_AliasStr = l_Alias;

    Char l_Char;
    for (S32 i = 0; i < len && l_AliasSize < 15; i++) {
         l_Char = i_Command[i];
        if ('A' <= l_Char && l_Char <= 'Z' || '0' <= l_Char && l_Char <= '9') {
            *l_AliasStr++ = l_Char;
            l_AliasSize++;
        }
    }
    
    l_Alias[l_AliasSize] = '\0';
    l_Command->m_Alias = Name_Z::GetID(l_Alias, 0);
    
    Command_Z* l_Tail = m_CommandList;
    Command_Z* l_Tail2 = (Command_Z*)(void*)l_Tail;
    
    for (Command_Z* l_TailCopy = m_CommandList; l_TailCopy != NULL; l_TailCopy = l_TailCopy->m_Prev)
        ;

    if (NULL == l_Tail) {
        m_CommandList = l_Command;
    }
    else if (l_Tail == l_Tail2)
    {
        l_Command->m_Prev = l_Tail;
        m_CommandList = l_Command;
        
    }
    else {
        l_Command->m_Prev = l_Tail->m_Prev;
        l_Tail->m_Prev = l_Command;
    }
}
