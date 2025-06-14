#ifndef _FILE_HDL_Z_H_
#define _FILE_HDL_Z_H_
#include "Types_Z.h"
#include "ansi_files.h"

class FileHdl_Z {
private:
    Char* m_Unk0x0[0x30];
    S32 m_Unk0x30;
    S32 m_Unk0x34;
    S32 m_Unk0x38;
    S32 m_CurrentPos;
    U32 m_EntryNum;
    FILE* m_FilePtr;
    U32 m_LastError;
};

#endif
