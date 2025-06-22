#ifndef _STRING_Z_H_
#define _STRING_Z_H_
#include "Types_Z.h"
#include "Assert_Z.h"

Extern_Z "C" U32 strlen(const Char* str);
Extern_Z "C" int strcpy(Char* dest, const Char* src);
Extern_Z "C" int vsprintf(const Char* i_Buf, const Char* i_Format, va_list i_Args);
Extern_Z "C" int strncpy(Char* dest, const Char* src, S32 count);
Bool fstricmp(const Char* a1, const Char* a2);
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

    operator const Char*() const {
        return m_Str;
    }

    operator Char*() {
        return m_Str;
    }

    Char* CStr() {
        return m_Str;
    }

    const Char* CStr() const {
        return m_Str;
    }

    S32 StrnCpy(const Char* i_Src, S32 i_Count) {
        return strncpy(m_Str, i_Src, i_Count);
    }

    int Sprintf(const Char* i_Format, ...) {
        va_list l_Args;
        va_start(l_Args, i_Format);

        vsprintf(m_Str, i_Format, l_Args);

        va_end(args);
        return 0;
    }

    inline Char& operator[](S32 i_Index) {
        return m_Str[i_Index];
    }

private:
    Char m_Str[Size];
};

#endif
