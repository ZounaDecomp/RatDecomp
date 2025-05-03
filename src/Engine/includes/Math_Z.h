#ifndef _MATH_Z_H_
#define _MATH_Z_H_

#define ROL_Z(val,shift) ((val<<shift)|(val>>((sizeof(val)*8)-shift)))
#define ROR_Z(val,shift) ((val>>shift)|(val<<((sizeof(val)*8)-shift)))

#endif
