#include <stdio.h>

#include "cpu/cpu.h"
#include "ram/ram.h"
#include "helpers/helpers.h"
#include "args/args.h"

int main(int argc, char **argv) {
    setProgram(argv[0]);

    char *pos = NULL;

    if (parseArgs(argc, argv, NULL, &pos)) return 1;
    if (!pos) { showError(FATAL_ERROR, "no input files"); return 1;}

    FILE *f = fopen(pos, "rb");
    if (!f) return 1;

    fread(RAM, 1, RAMSIZE, f); 

    fclose(f);

    cpu();

    return 0;
}