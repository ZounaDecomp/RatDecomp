#ifndef _ABC_CATEGORYDATA_Z_H_
#define _ABC_CATEGORYDATA_Z_H_
#include "ABC_Category_Engine.h"
#include "Types_Z.h"
class ABC_CategoryData;

class ABC_CategoryData { 
    ABC_CategoryData() {
        m_Category = -1;
        m_Next = NULL;
        m_IsPublic = FALSE;
    }
    Bool HasCategory(abc_category i_Cat);
private: 
    ABC_CategoryData* m_Next;
    S32 m_Category;
    Bool m_IsPublic;
};

#endif
