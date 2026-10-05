#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_exit(VirtualMachine *vm) {
    vm->cpu->running = 0;
}