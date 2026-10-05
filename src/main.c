#include <stdio.h>
#include <limits.h>

#include "cpu/cpu.h"
#include "ram/ram.h"
#include "vm/vm.h"
#include "args/args.h"
#include "utils.h"

int checkHeader(FILE *f, unsigned int header) {
    unsigned char headerBytes[4];

    if (fread(headerBytes, 1, 4, f) != 4) {
        showError(FATAL_ERROR, "file too small to contain header");
        fclose(f);
        return 0;
    }

    unsigned int fheader = 0;

    fheader |= headerBytes[0];
    fheader |= headerBytes[1] << 8;
    fheader |= headerBytes[2] << 16;
    fheader |= headerBytes[3] << 24;

    if (fheader != header) {
        showError(FATAL_ERROR, "invalid format: missing magic number %d", header);
        fclose(f);
        return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    setProgram(argv[0]);

    ArgCtx ctx = {.ip = 0, .pos = 0};

    parseArgv(argc, argv, &ctx);

    if (!ctx.pos) { showError(FATAL_ERROR, "no input files"); return 1;}

    FILE *f = fopen(ctx.pos, "rb");
    if (!f) {showError(FATAL_ERROR, "unable to open file: %s", ctx.pos); return 1;}

    if (!checkHeader(f, 3301)) return 1;

    VirtualMachine *vm = VM_Create();
    vm->cpu            = CPU_Init(vm->cpu, ctx.ip);

    fread(vm->ram, 1, RAMSIZE, f);
    fclose(f);
    
    CPU_Run(vm);

    VM_Destroy(vm);

    return 0;
}