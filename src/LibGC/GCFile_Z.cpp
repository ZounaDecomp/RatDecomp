#include "FileHdl_Z.h"
#include "Assert_Z.h"
// $VIOLET: TODO: Actually implement these in file_io.c
Extern_Z "C" FILE* fopen(const Char* i_Filename, const Char* i_Mode);

Bool FileHdl_Z::Open(const Char* i_Filename, U32 i_Flags) {
    ASSERTL_Z(!IsOpened(), "", 6);
    Char l_FileName[128];
    Bool l_Aux = GetRealFileName(i_Filename, l_FileName);
    m_LastError = 0;

    if ((i_Flags & READ_ONLY)) {
        l_Aux = DVDConvertPathToEntrynum(l_FileName);
        m_EntryNum = l_Aux;
        if ((m_EntryNum >= 0) && (DVDFastOpen(m_EntryNum, &m_DvdFileInfo) == FALSE)) {
            Close();
        }
        SetError(!IsOpened());
    }
    else if (l_Aux) {
        if ((i_Flags & WRITE_ONLY)) {
            m_FilePtr = fopen(l_FileName, "wb");
        }
    }
    else {
        m_FilePtr = fopen(l_FileName, "rb");
    }
    m_LastError = !IsOpened();
    return m_LastError == 0;
}
