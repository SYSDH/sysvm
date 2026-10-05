#include <stdio.h>
#include <string.h>

#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "ram/ram.h"
#include "vm/vm.h"

void CPU_Run(VirtualMachine *vm) {
    CPU *cpu = vm->cpu;

    while (cpu->running) {
        cpu->currentOp = advance(vm);

        #define X(module, ...) __VA_ARGS__ {module(vm); break;}
        switch (cpu->currentOp) {
            CPU_MODULES_TABLE

            default:
                printf("\nunknown opcode: 0x%X (at ip: %d)\n", cpu->currentOp, cpu->ip - 1);
                return;
        }

        #undef X
    }
}
