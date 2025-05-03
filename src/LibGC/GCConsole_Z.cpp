#include "GCConsole_Z.h"
#include "LowMemory_Z.h"

GCConsole_Z::GCConsole_Z()
{
    m_PopupMenu = NewL_Z(13) PopupMenu_Z;
}
