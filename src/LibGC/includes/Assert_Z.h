#ifndef _ASSERT_Z_H_
#define _ASSERT_Z_H_
#include "Types_Z.h"
#include "__va_arg.h"

void ExceptionBool_Z(bool i_Cancelable, const Char* i_Message, ...);
void ExceptionFonc_Z(const Char* i_Title, const Char* i_File, S32 i_Line, const Char* i_Message, U32 a5, U32 a6, U32 a7, U32 a8, U32 a9, U64* a10);
void ExceptionReport(const Char* a1);
void ExceptionHandler();
void BreakPoint_Z();

#undef ASSERT_Z
#define ASSERT_Z(Exp, Comment) \
    if (Exp == FALSE)          \
    ExceptionFonc_Z(#Exp, __FILE__, __LINE__, Comment, 0, 0, 0, 0, 0, 0)
#undef ASSERTL_Z
#define ASSERTL_Z(Exp, Comment, Line) \
    if (Exp == FALSE)                 \
    ExceptionFonc_Z(#Exp, __FILE__, Line, Comment, 0, 0, 0, 0, 0, 0)
#undef ASSERTLE_Z
#define ASSERTLE_Z(Exp, Comment, Line, OrigExp) \
    if (Exp == FALSE)                           \
    ExceptionFonc_Z(OrigExp, __FILE__, Line, Comment, 0, 0, 0, 0, 0, 0)
#undef ASSERTLENF_Z
#define ASSERTLENF_Z(Exp, Comment, Line, OrigExp) \
    ExceptionFonc_Z(OrigExp, __FILE__, Line, Comment, 0, 0, 0, 0, 0, 0)

//#undef ASSERT_Z
//#define ASSERT_Z(Exp) ASSERTC_Z(Exp, __FUNCTION__)

#endif
