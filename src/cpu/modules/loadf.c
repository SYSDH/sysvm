#include <stdio.h>

#include "cpu/cpu.h"
#include "cpu/utils.h"
#include "vm/vm.h"

void cpu_module_loadf(VirtualMachine *vm) {
    RAM ram  = vm->ram;
    CPU *cpu = vm->cpu;

    int pathAddr;
    int destAddr;

    if (cpu->currentOp == LOADF_REG) {
        pathAddr = cpu->reg[ram[cpu->ip++]];
        destAddr = cpu->reg[ram[cpu->ip++]];
    } else {
        pathAddr = readInt(&cpu->ip, ram);
        destAddr = readInt(&cpu->ip, ram);
    }

    unsigned char regStatus = ram[cpu->ip++];
    int mode = readInt(&cpu->ip, ram);

    char cleanPath[256];

    for (int i = 0; i < 255; i++) {
        char c = ram[pathAddr + (i * 4)];
        cleanPath[i] = c;

        if (c == '\0') return;
    }

    cleanPath[255] = '\0';
    FILE *f = fopen(cleanPath, "rb");

    if (!f) {
        cpu->reg[regStatus] = -1;
        return;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    if (destAddr + (size * 4) > RAMSIZE) {
        cpu->reg[regStatus] = -2;
        fclose(f);
        return;
    }


    if (mode == 0) {
        for (long i = 0; i < size; i++) {
            ram[destAddr + i] = fgetc(f);
        }
    } else {
        for (long i = 0; i < size; i++) {
            writeInt(destAddr + (i * 4), fgetc(f), ram);
        }
        writeInt(destAddr + (size * 4), 0, ram);
    }

    fclose(f);
    cpu->reg[regStatus] = (int)size;
}