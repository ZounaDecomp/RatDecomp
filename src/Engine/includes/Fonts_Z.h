#ifndef _FONTS_Z_H_
#define _FONTS_Z_H_
#include "DynArray_Z.h"
#include "ResourceObject_Z.h"
#include "Types_Z.h"
#include "Math_Z.h"
#include "HashTable_Z.h"
S32 GetUTF8CharBytes(const S8* a1);
U32 GetUTF8CharCode(const S8* a1);

class FontGlyphHash_Z {
public:
    S32 HashBase() const { return m_CharCode; }
    S32 m_CharCode;
    S32 m_MaterialIndex;
    Float m_Descent;
    Vec2f m_TexCoordTopLeft;
    Vec2f m_TexCoordBottomRight;
};

class Fonts_Z : public ResourceObject_Z {
public:
    Fonts_Z();
    virtual ~Fonts_Z();
    virtual void Load(void* a1);
    virtual void EndLoad();
    virtual void AfterEndLoad();
    virtual void MarkHandles();

private:
    S32 m_FontGlyphCount;
    DynArray_Z<S32, 32> m_MaterialDA;
    HashTableBase_Z<FontGlyphHash_Z> m_FontGlyphHash;
};

#endif
