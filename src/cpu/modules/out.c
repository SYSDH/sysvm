#include <stdio.h>

#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_out(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    int value;

    if (cpu->currentOp == OUT_REG) {
        unsigned char regIndex = ram[cpu->ip++];
        value = cpu->reg[regIndex];
    } else {
        value = readInt(&cpu->ip, ram);
    }
    
    int mode = readInt(&cpu->ip, ram);

    if (mode) {
        printf("%c", (char)value);
    } else {
        printf("%d", value);
    }

    fflush(stdout);
}