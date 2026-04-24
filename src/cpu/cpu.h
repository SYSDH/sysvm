#ifndef CPU_H
#define CPU_H

#include "../ram/ram.h"

// Commands
typedef enum {
    // System
    EXIT        = 0xFF,

    // Data
    MOV         = 0x10, MOV_REG     = 0x11,

    // Math
    ADD         = 0x20, ADD_REG     = 0x21,
    SUB         = 0x22, SUB_REG     = 0x23,

    // Flow
    JZ          = 0x30,
    JNZ         = 0x31,
    JMP         = 0x32, JMP_REG     = 0x33,
    CALL        = 0x34,
    RET         = 0x35,
    JG          = 0x36, JGE         = 0x37,
    JL          = 0x38, JLE         = 0x39,

    // I/O
    OUT         = 0x40, OUT_REG     = 0x41,
    IN          = 0x42, 
    LOADF       = 0x43, LOADF_REG   = 0x44,

    // Stack
    PUSH        = 0x50, PUSH_REG    = 0x51,
    POP         = 0x52,
    // Ram
    LOAD        = 0x60, LOAD_REG    = 0x61,
    STORE       = 0x62, STORE_REG   = 0x63,

} Opcode;

// Register
#define H 0
#define He 1
#define Li 2
#define Be 3
#define B 4
#define C 5
#define N 6
#define O 7

extern unsigned char RAM[RAMSIZE];

void cpu(int initpc);

#endif
