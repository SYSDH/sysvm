#pragma once

#include <stddef.h>

#define ARG_NONE 0
#define ARG_REQ  1
#define ARG_OPT  2

#define ARGS_TABLE \
    X("h", "help",    "Show this message",             ARG_OPT,  handleHelp   ) \
    X(NULL, "ip",     "Set instruction pointer start", ARG_REQ,  handleIp     )

typedef struct {
    int   ip;
    char *pos;
} ArgCtx;

typedef struct {
    const char *shortOpt;
    const char *longOpt;
    const char *desc;

    int hasVal;
    void (*handler)(const char *val, ArgCtx *ctx);
} ArgOption;

extern ArgOption options[];
extern const int optCount;

int parseArgv(int argc, char **argv, ArgCtx *ctx);

#define X(simple, long, help, argtype, handler) void handler(const char *val, ArgCtx *ctx);
ARGS_TABLE
#undef X

