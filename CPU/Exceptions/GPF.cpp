#include "GPF.h"

void printf(char *);
void printHex(uint8_t);

EXCEPTIONS_GPF::EXCEPTIONS_GPF(InterruptManager* interruptManager)
    : InterruptHandler(0x0D, interruptManager)
{
}

EXCEPTIONS_GPF::~EXCEPTIONS_GPF()
{
}

uint32_t EXCEPTIONS_GPF::HandleInterrupt(uint32_t esp)
{
    CPUState* CSTATE = (CPUState*)esp;
    printf("\5");
    printf("A Kernel Panic Occured. HALTING...                 \nSYSMSG_EXCEPTION:  General Protection Fault\n\n");
    printf("Extended stack pointer = 0x");
    printHex32(esp);
    printf("\nExtended instruction pointer  = 0x");
    printHex32(CSTATE->eip);
    printf("\nCode segment selector = 0x");
    printHex32(CSTATE->cs);
    printf("\nError code = 0x");
    printHex32(CSTATE->error);
    printf("\n");
    printf("Registers:\n");
    printf("EAX = 0x");
    printHex32(CSTATE->eax);
    printf("\nEBX = 0x");
    printHex32(CSTATE->ebx);
    printf("\nECX = 0x");
    printHex32(CSTATE->ecx);
    printf("\nEDX = 0x");
    printHex32(CSTATE->edx);
    printf("\nESI = 0x");
    printHex32(CSTATE->esi);
    printf("\nEDI = 0x");
    printHex32(CSTATE->edi);
    printf("\nEBP = 0x");
    printHex32(CSTATE->ebp);
    Power.halt();
    return esp;
}