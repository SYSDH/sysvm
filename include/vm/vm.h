#pragma once

#include "ram/ram.h"
#include "cpu/cpu.h"

typedef struct VirtualMachine {
    uint8_t ram[RAMSIZE];
    CPU *cpu;
} VirtualMachine;

VirtualMachine *VM_Create(void);
void VM_Destroy(VirtualMachine *vm);
