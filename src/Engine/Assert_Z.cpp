#include "Assert_Z.h"
#include "Types_Z.h"
#include "GXStruct.h"
#include "os.h"
Extern_Z "C" int sprintf(char *s, const char *format, ...);
Extern_Z "C" int strcat(char *dest, const char *src);


void ExceptionBool_Z(bool i_Cancelable, const Char* i_Message, ...) {
    va_list args;
}

void ExceptionFonc_Z(const Char* a1, const Char* a2, S32 a3, const char* a4, U32 a5, U32 a6, U32 a7, U32 a8, U32 a9, U64* a10) {
#ifdef ASSERTENABLED_Z 
    Extern_Z char WhereAmI[0x1C];
    Char l_Buffer[0x28F0];
    GXColor l_FgColor;
    l_FgColor.r = 255;
    l_FgColor.g = 0;
    l_FgColor.b = 0;
    l_FgColor.a = 255;
    GXColor l_BgColor;
    l_BgColor.r = 255;
    l_BgColor.g = 255;
    l_BgColor.b = 255;
    l_BgColor.a = 0;
    sprintf(l_Buffer, "Excep %s %s \"%s\" line%d.\n ", a1, a4, a2, a3);
    strcat(l_Buffer, WhereAmI);
    strcat(l_Buffer, "\n");
    OSFatal(l_FgColor, l_BgColor, l_Buffer);
#endif
}

void ExceptionReport(const Char* a1) {
}

void ExceptionHandler() {
}

void BreakPoint_Z() {
}
