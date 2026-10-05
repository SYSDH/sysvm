#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_ret(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;
    
    if (*cpu->sp >= RAMSIZE - 4) {
        return; 
    }
    
    *cpu->sp += 4;

    int returnAddr = 0;
    returnAddr |= ram[*cpu->sp-3];
    returnAddr |= ram[*cpu->sp-2] << 8;
    returnAddr |= ram[*cpu->sp-1] << 16;
    returnAddr |= ram[*cpu->sp]   << 24;
    
    cpu->ip = returnAddr;
}