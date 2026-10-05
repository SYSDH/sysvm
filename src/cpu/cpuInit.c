#include <stdio.h>
#include <string.h>

#include "cpu/cpu.h"
#include "ram/ram.h"

#include "vm/vm.h"

CPU *CPU_Init(CPU *cpu, int initIp) {
    memset(cpu->reg, 0, sizeof(cpu->reg));
    
    cpu->ip  = initIp;
    cpu->sp  = &cpu->reg[SP];

    *cpu->sp = RAMSIZE - 4;
    cpu->reg[BP] = *cpu->sp;

    cpu->running = 1;

    return cpu;
}