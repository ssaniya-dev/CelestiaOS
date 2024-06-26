#ifndef SHELL_H
#define SHELL_H

#include "../Drivers/Keyboard.h"
#include "../Include/types.h"
#include "../Include/Public_VAR.h"

class CShell : public CustomShell
{
    char CharBuffer[256];

public:
    CShell();
    ~CShell();
    virtual void Shell();
    virtual void clearBuffer();
    virtual void OnKeyDown(uint8_t key);
};

#endif