#include "Fonts_Z.h"
#include "Main_Z.h"

extern Globals gData;

S32 GetUTF8CharBytes(const S8* a1)
{
    if ((*a1 & 0x80) == 0) {
        return 1;
    } else if ((*a1 & 0xE0) == 0xC0) {
        return 2;
    } else if ((*a1 & 0xF0) == 0xE0) {
        return 3;
    } else if ((*a1 & 0xF8) == 0xF0) {
        return 4;
    }
    return 1;
}

U32 GetUTF8CharCode(const S8* a1)
{
    const U8 *p = (const U8*)a1;
    char v1 = *p;
    
    if ((v1 & 0x80) == 0)
    {
        return p[0];
    }
    else if ((v1 & 0xE0) == 0xC0)
    {
        return ((p[0] & 0xff) << 8) | (p[1] & 0xff);
    }
    else if ((v1 & 0xF0) == 0xE0)
    {
        return ((p[0] & 0xff) << 16) | ((p[1] & 0xff) << 8) | (p[2] & 0xff);
    }
    else if ((v1 & 0xF8) == 0xF0)
    {
        return ((p[0] & 0xff) << 24) | ((p[1] & 0xff) << 16) | ((p[2] & 0xff) << 8) | (p[3] & 0xff);
    }

    return 1;
}
