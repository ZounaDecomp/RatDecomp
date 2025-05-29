#include "Sys_Z.h"
#include "Types_Z.h"
Extern_Z "C" int strlen(const Char* str);
Extern_Z "C" int strcpy(Char* dest, const Char* src);
Extern_Z "C" int strncpy(Char* dest, const Char* src, S32 n);
Extern_Z "C" int strstr(Char* str, const char* substr);

void Sys_Z::GetAbsoluteFromPath(const Char* i_Path, Char* o_AbsPath, Char* i_Unk) {
}
