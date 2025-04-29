#ifndef _TYPES_Z_H_
#define _TYPES_Z_H_

typedef char Bool;
typedef unsigned long U32;
typedef long S32;
typedef unsigned short U16;
typedef short S16;
typedef unsigned char U8;
typedef char S8;
typedef char Char;
typedef float F32;
typedef double F64;
typedef unsigned long long U64;
typedef long long S64;
typedef float Float;

#undef S32_MIN
#define S32_MIN -2147483648

#undef FALSE
#define FALSE (Bool) (0==1)

#undef TRUE
#define TRUE (Bool) (0==0)

#undef NULL
#define NULL 0

#undef _ALLOCDEFAULTALIGN
#define _ALLOCDEFAULTALIGN 4

#undef Weak_Z
#define Weak_Z __declspec(weak)

#endif
