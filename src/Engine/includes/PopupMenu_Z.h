#ifndef _POPUPMENU_Z_H_
#define _POPUPMENU_Z_H_
#include "Types_Z.h"

class PopupMenu_Z;

class PopupItem_Z;
class PopupPage_Z;

class PopupMenu_Z {
public:
    U8 m_Pad_0x0[0x14];

    PopupMenu_Z();

    virtual void Update(Float a1);
    virtual void Show(S32 a1, S32 a2);
    virtual void DrawPage(S32 a1, S32 a2, PopupPage_Z& a3);
    virtual void AddSeparator();
    virtual void AddItem(U32 a1, const Char* a2, PopupItem_Z* a3, PopupItem_Z* a4, U32 a5, U32* a6);
    virtual void PushSubItem(const Char* a1, S32& a2, S32& a3);
    virtual void PushSubItem(const Char* a1);
    virtual void PopSubItem();
    virtual void RemoveItem(S32 a1, S32 a2);
    virtual void FindItem(S32 a1);
};

#endif
