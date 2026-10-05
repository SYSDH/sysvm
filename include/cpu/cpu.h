#pragma once

#include "opcodes.h"
#include "registers.h"

#define SET_CASE(v) case v:

#define CPU_MODULES_TABLE                                      \
    X(cpu_module_exit,    SET_CASE(EXIT)                     ) \
    X(cpu_module_mov,     SET_CASE(MOV)   SET_CASE(MOV_REG)  ) \
    X(cpu_module_add,     SET_CASE(ADD)   SET_CASE(ADD_REG)  ) \
    X(cpu_module_sub,     SET_CASE(SUB)   SET_CASE(SUB_REG)  ) \
    X(cpu_module_push,    SET_CASE(PUSH)  SET_CASE(PUSH_REG) ) \
    X(cpu_module_pop,     SET_CASE(POP)                      ) \
    X(cpu_module_call,    SET_CASE(CALL)                     ) \
    X(cpu_module_ret,     SET_CASE(RET)                      ) \
    X(cpu_module_jmp,     SET_CASE(JMP)   SET_CASE(JMP_REG)  ) \
    X(cpu_module_jg_jl,   SET_CASE(JG)    SET_CASE(JL)       ) \
    X(cpu_module_jge_jle, SET_CASE(JGE)   SET_CASE(JLE)      ) \
    X(cpu_module_jz_jnz,  SET_CASE(JZ)    SET_CASE(JNZ)      ) \
    X(cpu_module_load,    SET_CASE(LOAD)  SET_CASE(LOAD_REG) ) \
    X(cpu_module_store,   SET_CASE(STORE) SET_CASE(STORE_REG)) \
    X(cpu_module_in,      SET_CASE(IN)                       ) \
    X(cpu_module_out,     SET_CASE(OUT)   SET_CASE(OUT_REG)  ) \
    X(cpu_module_loadf,   SET_CASE(LOADF) SET_CASE(LOADF_REG))

typedef struct VirtualMachine VirtualMachine;

typedef struct {
    Registers reg;
    int ip;
    int *sp;

    Opcode currentOp;
    
    int running;
} CPU;

CPU *CPU_Init(CPU *cpu, int initPc);
void CPU_Run(VirtualMachine *vm);

#define X(f, ...) \
    void f(VirtualMachine *vm);
    CPU_MODULES_TABLE
#undef X
