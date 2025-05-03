#include "ClassNameResManager_Z.h"

Weak_Z HashS32Table_Z::HashTableBase_Z() {
    m_NbElem = 0;
    m_NbFree = 0;
    m_ScanID = -1;
    m_Status = NULL;
    m_Hash = NULL;
    Resize(HASHTABLE_DEFAULT_SIZE);
}
