#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_load(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;
    int addr;

    if (cpu->currentOp == LOAD_REG) {
        addr = cpu->reg[ram[cpu->ip++]];
    } else {
        addr = readInt(&cpu->ip, ram);
    }

    unsigned char dest = ram[cpu->ip++];

    int val = 0;

    val |= ram[addr];
    val |= ram[addr + 1] << 8;
    val |= ram[addr + 2] << 16;
    val |= ram[addr + 3] << 24;
    
    cpu->reg[dest] = val;
}