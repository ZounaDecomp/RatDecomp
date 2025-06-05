#include "ABC_CategoryData.h" 
Bool ABC_CategoryData::HasCategory(abc_category i_Cat) {
    ABC_CategoryData* m_Curr = this;
    while (true) {
        if (m_Curr->m_Next == NULL) {
            return FALSE;
        }
        if (m_Category == i_Cat) break;
        m_Curr = m_Curr->m_Next;
    }
    return TRUE;
}
