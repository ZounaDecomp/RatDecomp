#include "Fonts_Z.h"
#include "Main_Z.h"
#include "Program_Z.h"

S32 GetUTF8CharBytes(const Char* i_CharBytePtr) {
    if ((*i_CharBytePtr & 0x80) == 0) {
        return 1;
    }
    else if ((*i_CharBytePtr & 0xE0) == 0xC0) {
        return 2;
    }
    else if ((*i_CharBytePtr & 0xF0) == 0xE0) {
        return 3;
    }
    else if ((*i_CharBytePtr & 0xF8) == 0xF0) {
        return 4;
    }
    return 1;
}

U32 GetUTF8CharCode(const Char* i_CharBytePtr) {
    const U8* l_CharByteU8Ptr = (const U8*)i_CharBytePtr;
    char l_CharFirstByte = *l_CharByteU8Ptr;

    if ((l_CharFirstByte & 0x80) == 0) {
        return l_CharByteU8Ptr[0];
    }
    else if ((l_CharFirstByte & 0xE0) == 0xC0) {
        return ((l_CharByteU8Ptr[0] & 0xff) << 8) | (l_CharByteU8Ptr[1] & 0xff);
    }
    else if ((l_CharFirstByte & 0xF0) == 0xE0) {
        return ((l_CharByteU8Ptr[0] & 0xff) << 16) | ((l_CharByteU8Ptr[1] & 0xff) << 8) | (l_CharByteU8Ptr[2] & 0xff);
    }
    else if ((l_CharFirstByte & 0xF8) == 0xF0) {
        return ((l_CharByteU8Ptr[0] & 0xff) << 24) | ((l_CharByteU8Ptr[1] & 0xff) << 16) | ((l_CharByteU8Ptr[2] & 0xff) << 8) | (l_CharByteU8Ptr[3] & 0xff);
    }

    return 1;
}

void Fonts_Z::MarkHandles() {
    for (S32 i = 0; i < m_MaterialDA.GetSize(); i++) {
        if (gData.ClassMgr->GetPtr(m_MaterialDA[i]) != NULL) {
            gData.ClassMgr->GetPtr(m_MaterialDA[i])->MarkHandles();
        }
    }
    ResourceObject_Z::MarkHandles();
}

void Fonts_Z::GetCharDesc(const char* i_Char, CharDesc& o_CharDesc) {
    S32 l_CharCode = GetUTF8CharCode(i_Char);
    FontGlyphHash_Z* l_Glyph = (FontGlyphHash_Z*)i_Char;
    if (m_FontGlyphHash.GetNbElem()) {
        m_FontGlyphHash.Insert(*l_Glyph); //this doesnt make sense. might be search
    }
}
