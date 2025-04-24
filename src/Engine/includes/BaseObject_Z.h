#ifndef _BASE_OBJECT_Z_H_
#define _BASE_OBJECT_Z_H_
#include "Name_Z.h"
#include "Handle_Z.h"

class BaseObject_Z
{
public:
    Name_Z m_Name;
    BaseObject_ZHdl m_Handle;
    BaseObject_Z();
    virtual void Init();
    ~BaseObject_Z();
    virtual void Load(void* a1);
    virtual void EndLoad();
    virtual void AfterEndLoad();
    virtual void LoadDone();
    virtual void LoadLinks(void* a1);
    virtual void EndLoadLinks();
    virtual void Clean();
    virtual void MarkHandles();
};

#endif
