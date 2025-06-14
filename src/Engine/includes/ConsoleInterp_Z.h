#ifndef _CONSOLE_INTERP_Z_H_
#define _CONSOLE_INTERP_Z_H_
#include "DynArray_Z.h"
#include "Manipulator_Z.h"

class FileInterp_Z;

class StackCommandInterp_Z {
private:
    Char m_Unk[84];
};

class ConsoleInterp_Z : public Manipulator_Z {
public:
    void PushCommand(Char* i_CommandLine, Bool i_Unk);
    inline S32 NbCommands() const { return m_StackCommIdx; }
private:
    S32 m_StackCommIdx;
    StackCommandInterp_Z m_StackComm[2048];
    DynArray_Z<FileInterp_Z*> m_FileStack;
};

#endif
