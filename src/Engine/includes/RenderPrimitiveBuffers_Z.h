#ifndef _RENDERPRIMITIVEBUFFERS_Z_H_
#define _RENDERPRIMITIVEBUFFERS_Z_H_
#include "Types_Z.h"

class IndexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual void Release();                              /* 0x0C */
};

class BaseIndexBuffer_Z : public IndexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual void Release();                              /* 0x0C */
};

class VertexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual void Release();                              /* 0x0C */
    void* m_Data;
};

class BaseVertexBuffer_Z : public VertexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual void Release();                              /* 0x0C */
};
#endif
