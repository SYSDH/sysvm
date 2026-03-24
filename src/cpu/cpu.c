#include <stdio.h>

#include "cpu.h"

unsigned char RAM[RAMSIZE];
int reg[8];

int PC = 0;

void cpu() {
    while (1)
    {
        unsigned char opcd = RAM[PC++];

        switch (opcd)
        {
            case MOV: {
                unsigned char regIndex = RAM[PC++];
                unsigned char value = RAM[PC++];
                reg[regIndex] = value;
                break;
            }

            case WRITE: {
                unsigned char regIndex = RAM[PC++];
                unsigned char mode = RAM[PC++];

                if (mode) {
                    printf("%c", (char)reg[regIndex]);
                } else {
                    printf("%d", reg[regIndex]);
                }

                break;
            }

            case ADD: {
                unsigned char regIndex = RAM[PC++];
                unsigned char value = RAM[PC++];

                reg[regIndex] += value;
                break;
            }

            case SUB: {
                unsigned char regIndex = RAM[PC++];
                unsigned char value = RAM[PC++];

                reg[regIndex] -= value;
                break;
            }

            case JMP:
                PC = RAM[PC++];
                break;

            case JZ: {
                unsigned char regIndex = RAM[PC++];

                if (!reg[regIndex]) PC = RAM[PC++];
                else PC++;

                break;
            }

            case JNZ: {
                unsigned char regIndex = RAM[PC++];

                if (reg[regIndex]) PC = RAM[PC++];
                else PC++;

                break;
            }

            case EXIT:
                return;
        }
    }
    
    
}
