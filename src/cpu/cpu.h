#ifndef CPU_H
#define CPU_H

// Commands
#define EXIT 0xFF

#define MOV 0x10

#define ADD 0x20

#define JZ 0x30
#define JMP 0x31

#define WRITE 0x40

// Register
#define H 0
#define He 1
#define Li 2
#define Be 3
#define B 4
#define C 5
#define N 6
#define O 7

extern unsigned char RAM[1024];

void cpu();

#endif
