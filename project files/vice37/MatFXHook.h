#pragma once
#include "CPatch.h"
#include <src/rwcore.h>

unsigned int &MyMatFXMaterialDataOffset = *(unsigned int *)0x7876CC;

RwBool MyRpMatFXPluginAttach() {
    RwBool result = RpMatFXPluginAttach();
    MyMatFXMaterialDataOffset = RpMaterialGetPluginOffset(0x120);
    return result;
}

void MakeMatFxHook() {
    CPatch::RedirectJump(0x655EB0, MyRpMatFXPluginAttach);
}
