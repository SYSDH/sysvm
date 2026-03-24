#include "cpu/cpu.h"
#include "ram/ram.h"

int main() {
    int bytes[] = {0x10, 0x0, 0x61, 0x40, 0x0, 0x1, 0xFF};

    int bytesSize = sizeof(bytes) / sizeof(bytes[0]);

    genRam(bytes, bytesSize);

    cpu();
}