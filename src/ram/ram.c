#include "../cpu/cpu.h"

void genRam(int bytes[], int bytesSize) {
    for (int byte = 0; byte < bytesSize; byte++) {
        RAM[byte] = bytes[byte];
    }
}
