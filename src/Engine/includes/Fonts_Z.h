#ifndef _FONTS_Z_H_
#define _FONTS_Z_H_
#include "DynArray_Z.h"
#include "ResourceObject_Z.h"
#include "Types_Z.h"
#include "Math_Z.h"
#include "HashTable_Z.h"
// #include "Material_ZHdl.h"
// #include "Material_Z.h"
S32 GetUTF8CharBytes(const Char* a1);
U32 GetUTF8CharCode(const Char* a1);

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
    virtual Bool MarkHandles();

private:
    S32DA m_MaterialDA; // $VIOLET: Fix the stupid and dumb Material_ZHdl issues you were having
    HashTableBase_Z<FontGlyphHash_Z> m_FontGlyphHash;
};

#endif
