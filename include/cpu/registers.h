#pragma once

typedef enum {
    H  = 0,
    He = 1,
    Li = 2,
    Be = 3,
    B  = 4,
    C  = 5,
    N  = 6,
    O  = 7,
    SP = 8,
    BP = 9,
    EOR
} RegistersEnum;

typedef int Registers[EOR];