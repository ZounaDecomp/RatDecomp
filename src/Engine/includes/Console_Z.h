#ifndef _CONSOLE_Z_H_
#define _CONSOLE_Z_H_
#include "Types_Z.h"
#include "DynArray_Z.h"
#include "String_Z.h"
#include "Name_Z.h"
#include "PopupMenu_Z.h"

class ConsoleInterp_Z;
class DrawInfo_Z;

typedef Bool (*CommandProc)();

struct Command_Z {
    S32 m_Command;
    S32 m_Alias;
    CommandProc m_Proc;
    Command_Z* m_Prev;
};

class Console_Z {
protected:
    Char* m_ConsoleText;
    S32 m_UnksS32_0x4;
    DynArray_Z<Char> m_TextBolded;
    U8 m_Pad_0x10[4976];
    U32 m_UnkU32_0x1380;
    U32 m_UnkU32_0x1384;
    U32 m_UnkU32_0x1388;
    U32 m_UnkU32_0x138c;
    U32 m_UnkU32_0x1390;
    U32 m_UnkU32_0x1394;
    U32 m_UnkU32_0x1398;
    U32 m_UnkU32_0x139c;
    U32 m_UnkU32_0x13a0;
    U32 m_UnkU32_0x13a4;
    U32 m_UnkU32_0x13a8;
    Bool m_UnkBool_0x13ac;
    U8 m_Pad_0x13ad[4095];
    PopupMenu_Z* m_PopupMenu;

private:
    Command_Z* m_CommandList;
    U32 m_CommIndex;
    U32 m_MaxComm;
    U32 m_UnkU32_0x23bc;
    String_Z<1088> m_CommandStack[16];
    U32 m_NbParam;
    Char* m_StrParam[16];
    Bool m_IsFloatParam[16];
    Float m_FloatParam[16];
    U32 m_CommandNbVar;
    String_Z<32> m_CommandVar[32];
    U32 m_StackNbVar;
    Bool m_StackVarState[8];
    U32 m_FolderFlag;
    U32 m_Flag;
    U32 m_Depth;
    Bool m_UnkBool_0x6c70;
    ConsoleInterp_Z* m_Interp;

public:
    void SetVar(Char* i_Var);
    void AddCommand(const Char* i_Command, CommandProc i_Proc, const Char* i_Desc);

    U32 GetNbParam() { return m_NbParam; }

    virtual ~Console_Z();
    virtual void Init();
    virtual U32 InitConsole();
    virtual void CloseConsole();
    virtual void EnableFolder(unsigned long a1);
    virtual void DisableFolder(unsigned long a1);
    virtual void EnableFlag(unsigned long a1);
    virtual void DisableFlag(unsigned long a1);
    virtual void Update(float a1);
    virtual void Draw(DrawInfo_Z& a1);
    virtual PopupMenu_Z* GetPopupMenu();
    virtual void Flush();
    virtual void DisplayStatus(unsigned long a1, const char* a2);
    virtual void MessageStatus(unsigned long a1, const char* a2, ...);
    virtual void SaveMessage(const char* a1);
    virtual void SaveWarningMessage(const char* a1);
    virtual void MessageError(bool a1, ...);
};

#endif
