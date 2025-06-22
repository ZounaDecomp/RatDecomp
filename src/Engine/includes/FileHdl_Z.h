#ifndef _FILE_HDL_Z_H_
#define _FILE_HDL_Z_H_
#include "Types_Z.h"
#include "ansi_files.h"
#include "dvd.h"

class FileHdl_Z {
private:
    DVDFileInfo m_DvdFileInfo;
    S32 m_CurrentPos;
    U32 m_EntryNum;
    FILE* m_FilePtr;
    U32 m_LastError;
};

#endif
