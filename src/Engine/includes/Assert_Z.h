#ifndef _ASSERT_Z_H_
#define _ASSERT_Z_H_
#include "Types_Z.h"
#include "stdarg.h"

void ExceptionBool_Z(bool i_Cancelable, const Char* i_Message, ...);
void ExceptionFonc_Z(const S8* a1, const S8* a2, S32 a3, const char* a4, U32 a5, U32 a6, U32 a7, U32 a8, U32 a9, U64* a10);
void ExceptionReport(const S8* a1);
void ExceptionHandler();
void BreakPoint_Z();

#endif
