#ifndef _STRING_Z_H_
#define _STRING_Z_H_
#include "Types_Z.h"
#include "Assert_Z.h"

Extern_Z "C" int strlen(const Char* str);
Extern_Z "C" int strcpy(Char* dest, const Char* src);
Extern_Z "C" int vsprintf(const Char* i_Buf, const Char* i_Format, va_list i_Args);

S32 fstricmp(const Char* a1, const Char* a2);
void fsprintfID(Char* a1, U32 a2, U32 a3);

template <S32 Size>
class String_Z {
public:
    String_Z<Size>() {
        Empty();
    }

    void Empty() {
        m_Str[0] = 0;
    }

    void StrCpy(const Char* i_Str) { strcpy(m_Str, i_Str); }

    inline String_Z<Size>& operator=(const char* i_Text) {
        StrCpy(i_Text);
        return *this;
    }

    int Sprintf(const Char* i_Format, ...) {
        va_list l_Args;
        va_start(l_Args, i_Format);

        vsprintf(m_Str, i_Format, l_Args);

        va_end(args);
        return 0;
    }

private:
    Char m_Str[Size];
};

#endif
