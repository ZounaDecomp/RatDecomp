#include "MathTools_Z.h"
extern const Float Pi;
#define PI					Pi
#define PI2					(PI/2.0f)
#define TABLESIZE_COS			32
#define BITCOUNT_INVSQRT		7
#define BITCOUNT_ACOS			6
#define TABLESIZE_INVSQRT		(1 << BITCOUNT_INVSQRT)
#define TABLESIZE_ACOS			(1 << BITCOUNT_ACOS)
static Float			gTableAcos[TABLESIZE_ACOS];
static Float			gTableCos[TABLESIZE_COS+1];
static U8				gTable1InvSqrt[TABLESIZE_INVSQRT];
