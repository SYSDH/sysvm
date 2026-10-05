#include <stdlib.h>

#include "vm/vm.h"

VirtualMachine *VM_Create(void) {
    VirtualMachine *vm = malloc(sizeof(VirtualMachine));
    if (!vm) return NULL;

    vm->cpu = malloc(sizeof(CPU));
    
    if (!vm->cpu) {
        free(vm);
        return NULL;
    }

    return vm;
}

void VM_Destroy(VirtualMachine *vm) {
    free(vm->cpu);
    free(vm);
}