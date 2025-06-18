#ifndef _FILE_Z_H_
#define _FILE_Z_H_
#include "Types_Z.h"
#include "FileHdl_Z.h"
#include "String_Z.h"
class File_Z {
public:
    ~File_Z();
    void Init(S32 i_Unk, const char* i_FileName);
    S32 GetSize();
    void* GetBuf() { return m_FileBuf; }
private:
    FileHdl_Z m_FileHdl;
    void* m_FileBuf;
    S32 m_FileSize;
    S32 m_FilePos;
    S32 m_Unk;
    String_Z<512> m_FileName; 
};

#endif
