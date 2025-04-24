#include "Fonts_Z.h"

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
