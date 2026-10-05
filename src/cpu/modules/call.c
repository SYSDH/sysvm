#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_call(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    int target = readInt(&cpu->ip, ram);

    writeInt(*cpu->sp - 3, cpu->ip, ram);
    *cpu->sp -= 4;

    cpu->ip = target;
}