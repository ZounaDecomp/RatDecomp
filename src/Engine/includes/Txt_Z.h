#ifndef _TXT_H_
#define _TXT_H_
#include "ResourceObject_Z.h"
#include "File_Z.h"

class Txt_Z : public ResourceObject_Z
{
    virtual void Load(void **i_Data);
    virtual ~Txt_Z() {m_File->~File_Z();};
private:
    File_Z* m_File;
};

#endif
