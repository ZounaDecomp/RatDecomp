#ifndef _BINK_TYPES_H_
#define _BINK_TYPES_H_

typedef signed char S8;
typedef signed short S16;
typedef signed long S32;
typedef signed long long S64;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
#ifndef _SIZE_T_DEF
#define _SIZE_T_DEF
typedef unsigned long size_t;
#endif
typedef unsigned long long u64;
typedef unsigned int uint;

typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef int BOOL;

// Pointer to unknown, to be determined at a later date.
typedef void* unkptr;
typedef U32 unknown;

#define TRUE 1
#define FALSE 0

#ifndef NULL
#ifndef __cplusplus
#define NULL ((void*)0)
#else
#define NULL 0
#endif
#endif
#define nullptr 0

#endif
