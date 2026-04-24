#include <stdlib.h>

#include "../args.h"

void handleEntry(const char *val, void *context) {
    Config *cfg = (Config *)context;
    cfg->entryAddr = atoi(val);
}