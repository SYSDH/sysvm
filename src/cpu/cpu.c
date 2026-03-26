#include <stdio.h>
#include <string.h>

#include "cpu.h"

unsigned char RAM[RAMSIZE];
int reg[8];

int Pb = RAMSIZE - 1;
int PC = 0;

static int readInt() {
    int val = 0;
    val |= RAM[PC++];
    val |= RAM[PC++] << 8;
    val |= RAM[PC++] << 16;
    val |= RAM[PC++] << 24;
    return val;
}

static void writeInt(int addr, int val) {
    RAM[addr]     = (val & 0xFF);
    RAM[addr + 1] = (val >> 8) & 0xFF;
    RAM[addr + 2] = (val >> 16) & 0xFF;
    RAM[addr + 3] = (val >> 24) & 0xFF;
}


void cpu() {
    while (1)
    {
        unsigned char opcd = RAM[PC++];

        switch (opcd)
        {
            case MOV: case MOV_REG: {
                unsigned char dest = RAM[PC++];

                if (opcd == MOV_REG) {
                    reg[dest] = reg[RAM[PC++]];
                } else {
                    reg[dest] = readInt();
                }

                break;
            }

            case IN: {
                char buffer[256];
                
                if (fgets(buffer, sizeof(buffer), stdin)) {
                    buffer[strcspn(buffer, "\n")] = 0;
                    int len = strlen(buffer);

                    writeInt(Pb - 3, -1); 
                    Pb -= 4;

                    for (int i = len - 1; i >= 0; i--) {
                        writeInt(Pb - 3, (int)buffer[i]);
                        Pb -= 4;
                    }
                }
                break;
            }
            
            case LOAD: case LOAD_REG: {
                int addr;

                if (opcd == LOAD_REG) {
                    addr = reg[RAM[PC++]];
                } else {
                    addr = readInt();
                }

                unsigned char dest = RAM[PC++];

                int val = 0;
                val |= RAM[addr];
                val |= RAM[addr + 1] << 8;
                val |= RAM[addr + 2] << 16;
                val |= RAM[addr + 3] << 24;
                reg[dest] = val;

                break;
            }

            case STORE: case STORE_REG: {
                int addr;

                if (opcd == STORE_REG) {
                    addr = reg[RAM[PC++]];
                } else {
                    addr = readInt();
                }

                writeInt(addr, reg[RAM[PC++]]);
                break;
            }

            case OUT: case OUT_REG: {
                int value;

                if (opcd == OUT_REG) {
                    unsigned char regIndex = RAM[PC++];
                    value = reg[regIndex];
                } else {
                    value = readInt();
                }
                
                int mode = readInt();

                if (mode) {
                    printf("%c", (char)value);
                } else {
                    printf("%d", value);
                }

                fflush(stdout);
                break;
            }

            case ADD: case ADD_REG: {
                unsigned char dest = RAM[PC++];

                if (opcd == ADD_REG) {
                    reg[dest] += reg[RAM[PC++]];
                } else {
                    reg[dest] += readInt();
                }

                break;
            }

            case SUB: case SUB_REG: {
                unsigned char dest = RAM[PC++];

                if (opcd == SUB_REG) {
                    reg[dest] -= reg[RAM[PC++]];
                } else {
                    reg[dest] -= readInt();
                }

                break;
            }

            case JMP:
                PC = readInt();
                break;

            case JZ: {
                unsigned char regIndex = RAM[PC++];
                int target = readInt();
                if (!reg[regIndex]) PC = target;

                break;
            }

            case JNZ: {
                unsigned char regIndex = RAM[PC++];
                int target = readInt();
                if (reg[regIndex]) PC = target;

                break;
            }

            case PUSH: case PUSH_REG: {
                int val;

                if (opcd == PUSH_REG) {
                    val = reg[RAM[PC++]];
                } else {
                    val = readInt();
                }
                
                writeInt(Pb - 3, val);
                Pb -= 4;

                break;
            }

            case POP: {
                if (Pb >= RAMSIZE - 1) {reg[RAM[PC++]] = -1; break;}

                Pb += 4;
                unsigned char dest = RAM[PC++];

                int val = 0;
                val |= RAM[Pb-3];
                val |= RAM[Pb-2] << 8;
                val |= RAM[Pb-1] << 16;
                val |= RAM[Pb]   << 24;
                reg[dest] = val;
                break;
            }
            case EXIT:
                return;

            default:
                return;
        }
    }
    
    
}
