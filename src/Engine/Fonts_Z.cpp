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
