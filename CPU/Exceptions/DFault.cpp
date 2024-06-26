#include "DFault.h"

void printf(char *);
void printHex(uint8_t);

EXECPTION_DOUBLE_FAULT::EXECPTION_DOUBLE_FAULT(InterruptManager* interruptManager)
    : InterruptHandler(0x08, interruptManager)
{

}

EXECPTION_DOUBLE_FAULT::~EXECPTION_DOUBLE_FAULT()
{

}

uint32_t EXECPTION_DOUBLE_FAULT::HandleInterrupt(uint32_t esp)
{
    CPUState* CSTATE = (CPUState*)esp;
    printf("\5");
    printf("A Kernel Panic Occured. HALTING...                 \nSYSMSG_EXCEPTION:  Double Fault\n\n");
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