#include <stdio.h>
#include <limits.h>

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
    if (!f) {showError(FATAL_ERROR, "unable to open file: %s", pos); return 1;}

    unsigned char headerBytes[4];
    if (fread(headerBytes, 1, 4, f) != 4) {
        showError(FATAL_ERROR, "file too small to contain header");
        fclose(f);
        return 1;
    }

    unsigned int header = 0;
    header |= headerBytes[0];
    header |= headerBytes[1] << 8;
    header |= headerBytes[2] << 16;
    header |= headerBytes[3] << 24;

    if (header != 3301) {
        showError(FATAL_ERROR, "invalid format: missing magic number 3301");
        fclose(f);
        return 1;
    }

    fread(RAM, 1, RAMSIZE, f);

    fclose(f);
    
    cpu();

    return 0;
}