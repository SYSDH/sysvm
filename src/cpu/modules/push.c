#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_push(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    int val;

    if (cpu->currentOp == PUSH_REG) {
        val = cpu->reg[ram[cpu->ip++]];
    } else {
        val = readInt(&cpu->ip, ram);
    }

    writeInt(*cpu->sp - 3, val, ram);
    *cpu->sp -= 4;
}