#ifndef _RESOURCE_OBJECT_Z_H_
#define _RESOURCE_OBJECT_Z_H_
#include "BaseObject_Z.h"
#include "DynArray_Z.h"
class ResourceObjectLink_Z
{
    public:
        Weak_Z ResourceObjectLink_Z() {};
        ~ResourceObjectLink_Z();
        void Load(void* a1);
        void EndLoad();
        void EndLoadLinks();
        void MarkHandles();
        DynArray_Z<BaseObject_ZHdl, 32> m_LinkedResourceDA;
};

class ResourceObject_Z : public BaseObject_Z
{
    public:
        Weak_Z ResourceObject_Z() {};
        Weak_Z ~ResourceObject_Z();
        virtual void Load(void* a1);
        virtual void EndLoad();
        virtual void LoadLinks(void* a1);
        virtual void EndLoadLinks();
        virtual void MarkHandles();
    	ResourceObjectLink_Z m_ResObjLink;
};

#endif
