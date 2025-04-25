#ifndef _RESOURCE_OBJECT_Z_H_
#define _RESOURCE_OBJECT_Z_H_
#include "BaseObject_Z.h"

class ResourceObject_Z : public BaseObject_Z
{
    public:
        ResourceObject_Z() {};
        ~ResourceObject_Z();
        virtual void Load(void* a1);
        virtual void EndLoad();
        virtual void LoadLinks(void* a1);
        virtual void EndLoadLinks();
        virtual void MarkHandles();
    	char pad_000C[8];
};

#endif
