#ifndef _MACROS_Z_H_
#define _MACROS_Z_H_
// $VIOLET: Please use sparingly.  I do believe this is needed to fix inlining of functions that probably had an #ifndef _MASTER.
// $VIOLET: Since we have no idea what possibly could've been there, we have to add this. This is due to the MWCC inlining still
// $VIOLET: taking into account the undefined code when doing it's "should I inline" check. So this is needed. Sorry Sabe.

#define FIXDEBUGINLINING_Z() \
    do {                     \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
        (void)0;             \
    } while (0)

#endif
