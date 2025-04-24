#include "Handle_Z.h"
#include "Main_Z.h"
#include "Handle_Z.h"

extern Globals gData;

BaseObject_ZHdl::operator BaseObject_Z*() const {
    return GETPTR(*this);
}
