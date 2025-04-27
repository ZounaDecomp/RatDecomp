#ifndef _RESNAME_H_
#define _RESNAME_H_
#include "Types_Z.h"
#include "Name_Z.h"
class sDialogNames 
{
public:
    Name_Z m_DialogNames[0x11C/4];
    inline sDialogNames();
};

class sDialogFrameNames 
{
public:
    Name_Z m_DialogFrameNames[0x60/4];
    inline sDialogFrameNames();
};

class sFrameNames 
{
public:
    Name_Z m_FrameNames[0x60/4];
    inline sFrameNames();
};

class sDialogButtonNames 
{
public:
    Name_Z m_DialogButtonNames[0xC1C/4];
    inline sDialogButtonNames();
};

class sButtonNames 
{
public:
    Name_Z m_ButtonNames[0xC1C/4];
    inline sButtonNames();
};

#endif
