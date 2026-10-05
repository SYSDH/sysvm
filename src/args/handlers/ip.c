#include <stdlib.h>

#include "args/args.h"

void handleIp(const char *val, ArgCtx *ctx) {
    ctx->ip = atoi(val);
}