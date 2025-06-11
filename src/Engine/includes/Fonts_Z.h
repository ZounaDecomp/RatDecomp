#ifndef _FONTS_Z_H_
#define _FONTS_Z_H_
#include "Material_ZHdl.h"
#include "DynArray_Z.h"
#include "ResourceObject_Z.h"
#include "Types_Z.h"
#include "Math_Z.h"
#include "HashTable_Z.h"
struct CharDesc {
    S32 m_CharCode;
    S32 m_MaterialIndex;
    Float m_Descent;
    Vec2f m_TexCoordTopLeft;
    Vec2f m_TexCoordBottomRight;
};

S32 GetUTF8CharBytes(const Char* a1);
U32 GetUTF8CharCode(const Char* a1);

class FontGlyphHash_Z {
public:
    S32 m_ID;
    S32 m_MaterialIndex;
    Float m_Descent;
    Float m_TopLeftCoord[2];
    Float m_BottomRightCoord[2];
    S32 m_Ref;
    FontGlyphHash_Z() { }

    inline S32 HashBase() const { return m_ID; }
    inline void SetShadow() { m_Ref = -1; }

    inline S32 HashIncrement() const {
        return HashBase() == 0;
    }
    Bool operator==(const FontGlyphHash_Z& i_Elem) { return i_Elem.m_ID == m_ID; }
    Bool operator!=(const FontGlyphHash_Z& i_Elem) { return i_Elem.m_ID != m_ID; }
    FontGlyphHash_Z& operator=(const FontGlyphHash_Z& i_Elem) {
        m_ID = i_Elem.m_ID;
        m_MaterialIndex = i_Elem.m_MaterialIndex;
        m_Descent = i_Elem.m_Descent;
        m_TopLeftCoord[0] = i_Elem.m_TopLeftCoord[0];
        m_TopLeftCoord[1] = i_Elem.m_TopLeftCoord[1];
        m_BottomRightCoord[0] = i_Elem.m_BottomRightCoord[0];
        m_BottomRightCoord[1] = i_Elem.m_BottomRightCoord[1];
        m_Ref = i_Elem.m_Ref;
    }
};

class Fonts_Z : public ResourceObject_Z {
public:
    Fonts_Z();
    virtual ~Fonts_Z();
    virtual void Load(void* a1);
    virtual void EndLoad();
    virtual void AfterEndLoad();
    virtual void MarkHandles();
    void GetCharDesc(const char* i_Char, CharDesc& o_CharDesc);

private:
    Material_ZHdlDA m_MaterialDA; // $VIOLET: Fix the stupid and dumb Material_ZHdl issues you were having
    HashTableBase_Z<FontGlyphHash_Z> m_FontGlyphHash;
};

#endif
