#include "ResName.h"
extern Name_Z::Name_Z(const char* a1);
Name_Z::Name_Z(const Name_Z& a1) {
    m_ID = a1.m_ID;
}

sDialogNames::sDialogNames() {
}

sDialogFrameNames::sDialogFrameNames() {
    // stubbed
}

sFrameNames::sFrameNames() {
    // stubbed
}

sDialogButtonNames::sDialogButtonNames() {
    // stubbed
}

sButtonNames::sButtonNames() {
    // stubbed
}

sDialogNames DialogNames;
sDialogFrameNames DialogFrameNames;
sFrameNames FrameNames;
sDialogButtonNames DialogButtonNames;
sButtonNames ButtonNames;
