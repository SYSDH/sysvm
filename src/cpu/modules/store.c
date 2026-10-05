#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_store(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    int addr;

    if (cpu->currentOp == STORE_REG) {
        addr = cpu->reg[ram[cpu->ip++]];
    } else {
        addr = readInt(&cpu->ip, ram);
    }

    writeInt(addr, cpu->reg[ram[cpu->ip++]], ram);
}