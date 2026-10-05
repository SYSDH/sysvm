#pragma once

#include "ram/ram.h"
#include "vm/vm.h"

static inline void writeInt(int addr, int val, RAM ram) {
    ram[addr]     = (val & 0xFF);
    ram[addr + 1] = (val >> 8) & 0xFF;
    ram[addr + 2] = (val >> 16) & 0xFF;
    ram[addr + 3] = (val >> 24) & 0xFF;
}

static inline int readInt(int *pc, RAM ram) {
    int val = 0;

    val |= ram[(*pc)++];
    val |= ram[(*pc)++] << 8;
    val |= ram[(*pc)++] << 16;
    val |= ram[(*pc)++] << 24;

    return val;
}

static inline Opcode peek(VirtualMachine *vm) {
    return (Opcode)vm->ram[vm->cpu->ip];
}

static inline Opcode advance(VirtualMachine *vm) {
    return (Opcode)vm->ram[vm->cpu->ip++];
}