#include <stdio.h>
#include <string.h>

#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_in(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    char buffer[256];
                
    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        int len = strlen(buffer);

        writeInt(*cpu->sp - 3, 0, ram); 
        *cpu->sp -= 4;

        for (int i = len - 1; i >= 0; i--) {
            writeInt(*cpu->sp - 3, (int)buffer[i], ram);
            *cpu->sp -= 4;
        }

    }
}