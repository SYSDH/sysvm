#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_jg_jl(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    unsigned char regIndex = ram[cpu->ip++];
    
    int target = readInt(&cpu->ip, ram);
    int cond = (cpu->currentOp == JG) ? cpu->reg[regIndex] > 0 : cpu->reg[regIndex] < 0;

    if (cond) cpu->ip = target;
}