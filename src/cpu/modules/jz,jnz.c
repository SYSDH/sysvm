#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_jz_jnz(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    unsigned char regIndex = ram[cpu->ip++];
    
    int target = readInt(&cpu->ip, ram);
    int cond = (cpu->currentOp == JZ) ? !cpu->reg[regIndex] : cpu->reg[regIndex];

    if (cond) cpu->ip = target;

}