#ifndef HELPERS_H
#define HELPERS_H

#include <stddef.h>

typedef enum {
    WARNING_ERROR = 0,
    FATAL_ERROR = 1
} Severity;

extern char *programName;

void showError(Severity sev, char *extraMessage);
void setProgram(char *programVar);

#endif
