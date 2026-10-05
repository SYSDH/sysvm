#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_sub(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    unsigned char dest = ram[cpu->ip++];

    if (cpu->currentOp == SUB_REG) {
        cpu->reg[dest] -= cpu->reg[ram[cpu->ip++]];
    } else {
        cpu->reg[dest] -= readInt(&cpu->ip, ram);
    }
}