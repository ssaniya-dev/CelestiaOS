
#include "Shell.h"

CShell::CShell()
{
}

CShell::~CShell()
{
}

void printf(char *);
void printHex(uint8_t);
void printfchar(char st);

static int CharBufferIndex = 0;

void CShell::clearBuffer()
{
    for (int i = 0; i < 256; i++)
    {
        CharBuffer[i] = 0x00;
    }
    CharBufferIndex = 0;
}

void CShell::OnKeyDown(uint8_t key)
{
    if (key < 0x80 & key != 0x3A & key != 0x2A & key != 0x2A & key != 0x36 & key != 0x3A & key != 0x0E & key != 0x38 & key != 0x1D)
    {
        CharBuffer[CharBufferIndex] = KeyCodeToChar(key);
        CharBufferIndex++;
    }
    else if (key == 0x3E)
    {
        clearBuffer();
        CharBufferIndex = 0;
    }
}

void CShell::Shell()
{
    printf("\n");
    if (CharBuffer[0x00] == 'e' & CharBuffer[0x01] == 'c' & CharBuffer[0x02] == 'h' & CharBuffer[0x03] == 'o')
    {
        if (CharBuffer[0x04] == '\0')
        {
            printf("cannot print null character");
        }
        else if (CharBuffer[0x05] == '$' && CharBuffer[0x06] == 'S' && CharBuffer[0x07] == 'P')
        {
            for (int i = 0; i < SPIndex; i++)
            {
                printf(SP[i]);
            }
        }
        else
        {
            for (uint8_t i = 0x05; CharBuffer[i] != '\n'; i++)
            {
                printfchar(CharBuffer[i]);
            }
        }
    }
    else
    {
        for (int i = 0x00; i < CharBufferIndex; i++)
        {
            printHex(i);
            printf(" : ");
            printfchar(CharBuffer[i]);
            printf("\n");
        }
    }
    printf("\n");
    clearBuffer();
    asm("int $0x80"
        :
        : "a"(1), "b"("root@secos:~#> "));
}