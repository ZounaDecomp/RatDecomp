#include "Sys_Z.h"
#include "Types_Z.h"
extern "C" int strlen(const Char* str);
extern "C" int strcpy(Char* dest, const Char* src);
extern "C" int strncpy(Char* dest, const Char* src, S32 n);
extern "C" int strstr(Char* str, const char* substr);

void Sys_Z::GetAbsoluteFromPath(const Char* i_Path, Char* o_AbsPath, Char* i_Unk) {
}
