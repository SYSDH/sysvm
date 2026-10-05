#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_pop(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    if (*cpu->sp >= RAMSIZE - 4) {
        cpu->reg[ram[cpu->ip++]] = 0; 
        return;
    }

    *cpu->sp += 4;
    unsigned char dest = ram[cpu->ip++];

    int val = 0;

    val |= ram[*cpu->sp-3];
    val |= ram[*cpu->sp-2] << 8;
    val |= ram[*cpu->sp-1] << 16;
    val |= ram[*cpu->sp]   << 24;

    cpu->reg[dest] = val;
}