#include "Console_Z.h"
#include "Memory_Z.h"
#include "Name_Z.h"
#include "ConsoleInterp_Z.h"
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

Bool Console_Z::LaunchCommand(const Char* a1, const Char* i_CommandStr, U32 i_Depth, Command_Z* o_Command) {
    U32 l_Alias;
    if (o_Command == NULL) {
        if (i_CommandStr)
            l_Alias = Name_Z::GetID(i_CommandStr, 0);
        else
            l_Alias = 0;
        
        o_Command = m_CommandList;
        while ((o_Command != NULL) ) {
            if ((l_Alias == o_Command->m_Command) || (l_Alias == o_Command->m_Alias))
                break;
            o_Command = o_Command->m_Prev;
        }
    }
    
    if (o_Command == NULL)
        return FALSE;

    S32 l_Depth = m_Depth;
    m_Depth = i_Depth;
    Bool l_Result = o_Command->m_Proc();
    m_UnkBool_0x6c70 = FALSE;
    m_Depth = l_Depth;
    return !!l_Result;
}

void Console_Z::NewCommand(const Char* i_CommandStr, U32 i_Depth) {
    InterpCommandLine(i_CommandStr, i_Depth);
}

void Console_Z::PushCommand(Char* i_CommandLine, Bool i_Unk) {
    m_Interp->PushCommand(i_CommandLine, i_Unk);
}

S32 Console_Z::NbPushedCommand() {
    return m_Interp->NbCommands();
}
