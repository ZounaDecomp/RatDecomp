#include "Handle_Z.h"
#include "Main_Z.h"
#include "Program_Z.h"

BaseObject_ZHdl::operator BaseObject_Z*() const {
    return GETPTR(*this);
}
