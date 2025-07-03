#ifndef _FILE_HDL_Z_H_
#define _FILE_HDL_Z_H_
#include "Types_Z.h"
#include "ansi_files.h"
#include "dvd.h"

enum Format {
    READ_ONLY = 0x01,
    WRITE_ONLY = 0x02,
    READWRITE = 0x04,
    ASCII = 0x08,
    BINARY = 0x10
};

class FileHdl_Z {
public:
    FileHdl_Z();
    ~FileHdl_Z();

    Bool Open(const Char* i_Filename, U32 i_Flags);
    void SetError(U32 i_Error);
    void WaitIO();
    void* Read(void* i_Buffer, U32 i_Size);
    void Write(const void* i_Buffer, U32 i_Size);
    U32 GetSize() const;
    U32 GetCurPos() const;
    void Close();
    Bool DoFileExists(const Char* i_Filename);
    U32 GetFileDate(const Char* i_Filename);
    void SetFileDate(const Char* i_Filename, U32 i_Date);
    U32 Seek(S32 i_Offset, S32 i_Origin);
    Bool GetRealFileName(const Char* i_Filename, Char* o_RealName);
    void CheckDisc(Bool i_Unk);

    Bool IsOpened() {
        return (m_EntryNum != -1) || (m_FilePtr != NULL);
    }

    const DVDFileInfo& GetDvdFileInfo() const { return m_DvdFileInfo; }

private:
    DVDFileInfo m_DvdFileInfo;
    S32 m_CurrentPos;
    S32 m_EntryNum;
    FILE* m_FilePtr;
    U32 m_LastError;
};

#endif
