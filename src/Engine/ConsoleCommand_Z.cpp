#include "Console_Z.h"
#include "Memory_Z.h"
#include "Name_Z.h"
#include "ConsoleInterp_Z.h"
#include "Types_Z.h"
#include "String_Z.h"
Extern_Z "C" int strncmp(char* str1, char str2, int n);
Extern_Z "C" size_t strlen(const char* str);
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

Command_Z* PrevCommand;
// $VIOLET: PLEASE FINISH THIS I BEG IM SUFFERING IM GONNA KILL MYSELF
Bool Console_Z::InterpCommand(Char* i_CommandStr, Bool i_Depth) {
    String_Z<1024> l_CommandStack[16];
    S32 l_CommandNameLen;
    Command_Z* pCVar8 = NULL;
    if (!strlen(i_CommandStr)) {
        return FALSE;
    }
    S32 i;
    Char* l_CommandStr = i_CommandStr;
    m_UnkCount_0x19F0 = 0;
    for (i = 0; *l_CommandStr == ' ' || *l_CommandStr == '\t'; l_CommandStr++, i++);

    while (m_UnkCount_0x19F0 < 16 && i_CommandStr[i]) {
        l_CommandNameLen = 0;
        while (true) {
            Char l_Char = i_CommandStr[i + l_CommandNameLen]; 
            if (l_Char == ' ' || l_Char == '\t' || l_Char == 0) {
                break;
            }
            S32 l_StrNCmp = strncmp(&i_CommandStr[i + l_CommandNameLen], '"', 2);
            if (l_StrNCmp == 0 || i_CommandStr[i + l_CommandNameLen] != '"') {
                if (l_StrNCmp == 0) {
                    i++;
                }
                l_CommandStack[m_UnkCount_0x19F0 * 64][l_CommandNameLen] = i_CommandStr[i + l_CommandNameLen];
            }
            else {
                i++;
                for (; i_CommandStr[i + l_CommandNameLen] != '"'; l_CommandNameLen++) {
                    if (strncmp(&i_CommandStr[i + l_CommandNameLen], '"', 2) == 0) {
                        i++;
                    }
                    l_CommandStack[m_UnkCount_0x19F0 * 64][l_CommandNameLen] = i_CommandStr[i + l_CommandNameLen];
                }
                i++;
            }
        }
        l_CommandStack[m_UnkCount_0x19F0 * 64][l_CommandNameLen] = 0;
        m_StrParam[m_UnkCount_0x19F0] = l_CommandStack[m_UnkCount_0x19F0 * 64];

        Float l_FloatValue;
        if ((l_CommandNameLen == 0) || (InterpFloat(l_CommandStack[m_UnkCount_0x19F0 * 64], l_FloatValue) == 0))
        {
            m_IsFloatParam[m_UnkCount_0x19F0] = FALSE;
        }
        else {
            m_IsFloatParam[m_UnkCount_0x19F0] = TRUE;
            m_FloatParam[m_UnkCount_0x19F0] = l_FloatValue;
        }

        if ((fstricmp(l_CommandStack[m_UnkCount_0x19F0 * 64], "TRUE") == 0) || (fstricmp(l_CommandStack[m_UnkCount_0x19F0 * 64], "On") == 0)) {
            Float l_FalseValue = 1.0f;
            m_IsFloatParam[m_UnkCount_0x19F0] = TRUE;
            m_FloatParam[m_UnkCount_0x19F0] = l_FalseValue;
        }

        if ((fstricmp(l_CommandStack[m_UnkCount_0x19F0 * 64], "FALSE") == 0) || (fstricmp(l_CommandStack[m_UnkCount_0x19F0 * 64], "Off") == 0)) {
            Float l_FalseValue = 0.0f;
            m_IsFloatParam[m_UnkCount_0x19F0] = TRUE;
            m_FloatParam[m_UnkCount_0x19F0] = l_FalseValue;
        }

        i = i + l_CommandNameLen;
        for (l_CommandStr = &i_CommandStr[i]; *l_CommandStr == ' ' || *l_CommandStr == '\t'; l_CommandStr++, i++);
        m_UnkCount_0x19F0++;

    }
    if (this->m_UnkCount_0x19F0 != 0) {
        Name_Z l_CommandName = Name_Z::GetID(l_CommandStack[0], 0);
        Command_Z* pCVar2 = PrevCommand;

        if ((PrevCommand == NULL) ||
            (l_CommandName != PrevCommand->m_Command && l_CommandName != PrevCommand->m_Alias)) {
            for (pCVar8 = this->m_CommandList; pCVar8 != NULL; pCVar8 = (Command_Z*)pCVar8->m_Prev) {
                pCVar2 = pCVar8;
                if (l_CommandName == pCVar8->m_Command || l_CommandName == pCVar8->m_Alias)
                    break;
            }
            if (pCVar8 == NULL) {
                pCVar2 = PrevCommand;
            }
        } else {
            pCVar8 = PrevCommand;
        }

        PrevCommand = pCVar2;
        if (pCVar8 == NULL) {
            U32 uVar5 = this->m_UnkCount_0x19F0;
            if (uVar5 == 3) {
                int cmp = fstricmp(l_CommandStack[0], "#define");
                if ((cmp) == 0) {
                    Char* __dest = l_CommandStack[0];
                    this->m_UnkCount_0x19F0 = this->m_UnkCount_0x19F0 - 1;
                    Console_Z* pCVar7 = this;
                    for (int i = 0; i < (int)this->m_UnkCount_0x19F0; i = i + 1) {
                        strcpy(__dest, l_CommandStack[(i + 1) * 0x40]);
                        __dest += 0x40;
                        pCVar7->m_FloatParam[0] = pCVar7->m_FloatParam[1];
                        pCVar7 = (Console_Z*)&pCVar7->m_UnkS32_0x4;
                        this->m_FloatParam[i] = this->m_FloatParam[i + 1];
                    }
                }
            }
            else if (uVar5 < 3)  {
                if (uVar5 == 2) {
                    if (fstricmp(l_CommandStack[0], "#SET") == 0) {
                        SetVar(l_CommandStack[1]);
                        return TRUE;
                    }
                    if (fstricmp(l_CommandStack[0], "#UNSET") == 0) {
                        UnVar(l_CommandStack[1]);
                        return TRUE;
                    }
                    if ((fstricmp(l_CommandStack[0], "#IF") == 0) || (fstricmp(l_CommandStack[0], "#IFDEF") == 0)) {
                        PushVar(IsVar(l_CommandStack[1]));
                    }
                    if ((fstricmp(l_CommandStack[0], "#IFNOT") == 0) || (fstricmp(l_CommandStack[0], "#IFNDEF") == 0)) {
                        PushVar(!IsVar(l_CommandStack[1]));
                    }
                }
                if (fstricmp(l_CommandStack[0], "#ELSE") == 0) {
                    ChangeVarState();
                }

                if (fstricmp(l_CommandStack[0], "#ENDIF") == 0) {
                    PopVar();
                }
            }
        }
    }
    if ((m_StackNbVar == 0) || m_StackVarState[m_StackNbVar - 1]) {
        LaunchCommand(i_CommandStr, l_CommandStack[0], i_Depth, pCVar8);
    }
    return TRUE;
}
// $VIOLET: THIS ONE TOO AGH
void Console_Z::InterpCommandLine(const Char* i_CommandStr, U32 i_Depth) {
    U32 l_Pos                   = 0;
    U32 l_CurPos                = 0;
    String_Z<1024>    l_CurCommand;

    while (i_CommandStr[l_Pos+l_CurPos] !=0 )
    {
        if (i_CommandStr[l_Pos+l_CurPos] == ';')
        {
            l_CurCommand.StrnCpy(i_CommandStr + l_Pos, l_CurPos);
            l_CurCommand[l_CurPos] = 0;
            
            InterpCommand(l_CurCommand, i_Depth);
            
            l_Pos += l_CurPos;
            l_Pos++;
            l_CurPos=0;
        }
        else
        {
            l_CurPos ++;
        }
    }

    if (l_CurPos>0)
    {
        l_CurCommand.StrnCpy(i_CommandStr+l_Pos,l_CurPos);
        l_CurCommand[l_CurPos] = 0;

        InterpCommand(l_CurCommand, i_Depth);
    }
}
