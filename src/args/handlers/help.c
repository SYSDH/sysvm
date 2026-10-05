#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args/args.h"
#include "utils.h"

void handleHelp(const char *val, ArgCtx *ctx) {
    #define BRIGHT "\x1b[1m"
    #define RESET "\x1b[0m"

    (void)val;
    (void)ctx;

    printf("Usage: %s%s [options] <File>%s\n\n", BRIGHT, programName, RESET);
    printf("%sOptions%s:\n", BRIGHT, RESET);

    for (int i = 0; i < optCount; i++) {
        printf("  -%s%-10s%s --%s%-17s%s %s\n",
            BRIGHT,
            options[i].shortOpt,
            RESET,
            BRIGHT,
            options[i].longOpt,
            RESET,
            options[i].desc
        );
    }

    printf("\nExample:\n  %s%s binary.bin %s\n", BRIGHT, programName, RESET);
    
    exit(0);
}