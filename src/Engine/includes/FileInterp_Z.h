#ifndef _FILE_INTERP_Z_H_
#define _FILE_INTERP_Z_H_
#include "BaseStream_Z.h"
#include "ConsoleInterp_Z.h"
#include "File_Z.h"
class FileInterp_Z : public BaseStream_Z {
public:
    File_Z* GetFile() {
        return &m_File;
    }
    virtual void Opened(S32 a1, S32 a2, S32 a3);
    virtual void Readed(S32 a1, S32 a2, S32 a3);
private:
    File_Z m_File;
    S32 m_linesOrCommandsParsed;
    S32 m_UnkInt;
    S32 m_StackIndex;
    S32 m_Flags;
    String_Z<64> m_FileName;
    S32 m_ParamCountMaybe;
    String_Z<64> m_Params[16];
};


#endif
