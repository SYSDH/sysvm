#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_jmp(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;
    
    unsigned char regTarget = ram[cpu->ip];

    if (cpu->currentOp == JMP) cpu->ip = readInt(&cpu->ip, ram);
    else cpu->ip = cpu->reg[regTarget];
}