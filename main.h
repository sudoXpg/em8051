#include<stdio.h>
#include<stddef.h>
#include<stdint.h>
#include<string.h>
#include<unistd.h>


// Structure representing the Intel 8051 microcontroller
typedef struct I8051 {
    unsigned char A;            // Accumulator: Used for arithmetic and logic operations
    unsigned char B;            // B Register: Used for arithmetic operations, especially multiplication/division

    unsigned short opcode;      // Current instruction opcode
    unsigned short PC;          // Program Counter: Points to the next instruction to execute
    unsigned short DPTR;        // Data Pointer: 16-bit register used for external memory addressing
    unsigned char PSW;          // Program Status Word: Holds flags and status bits
    unsigned char SP;           // Stack Pointer: Points to the top of the stack

    unsigned char ROM[4096];    // Read-Only Memory: Stores the program code
    unsigned char RAM[128];     // Random-Access Memory: Stores temporary data

    unsigned char R[8];         // !! only for testing {iplement paging later!!}

    unsigned char PORT[4];      // Ports P0-P2: General-purpose I/O ports
    unsigned short timer[2];    // Timer: Used for counting or timing operations

    unsigned char TCON;         // Timer Control: Controls timer operations
    unsigned char TMOD;         // Timer Mode: Defines the mode of operation for timers
    unsigned char SCON;         // Serial Control: Configures serial communication
    unsigned char PCON;         // Power Control: Manages power-saving modes
    unsigned char IP;           // Interrupt Priority: Sets interrupt priorities
    unsigned char IE;           // Interrupt Enable: Enables/disables interrupts
} I8051;

I8051 cpu;


void init(){
    memset(&cpu, 0, sizeof(cpu));
}


void cpu_cycle(unsigned short opcode ){
    unsigned char tmp;
    switch(opcode){
        case 0x00:// NOP
            usleep(20);          //<---- // change as per clock
            cpu.PC+=1;
            break;

        case 0x01:// AJMP
            break;
        
        case 0x02:// LJMP
            break;
        
        case 0x03:// RR A
            cpu.A = (cpu.A>>1) | ((cpu.A & 0x01)<<7);
            cpu.PC+=1;
            break;
        
        case 0x04:// INC A
            cpu.A++;
            cpu.PC+=1;
            break;
        
        case 0x05:// INC direct ???
            break;

        case 0x06:// INC @R0
            cpu.RAM[cpu.R[0]]++;
            cpu.PC+=1;
            break;

        case 0x07:// INC @R1
            cpu.RAM[cpu.R[1]]++;
            cpu.PC+=1;
            break;
        
        case 0x08:// INC R0
            cpu.R[0]++;
            cpu.PC+=1;
            break;

        case 0x09:// INC R1
            cpu.R[1]++;
            cpu.PC+=1;
            break;

        case 0x0A:// INC R2
            cpu.R[2]++;
            cpu.PC+=1;
            break;

        case 0x0B:// INC R3
            cpu.R[3]++;
            cpu.PC+=1;
            break;

        case 0x0C:// INC R4
            cpu.R[4]++;
            cpu.PC+=1;
            break;

        case 0x0D:// INC R5
            cpu.R[5]++;
            cpu.PC+=1;
            break;

        case 0x0E:// INC R6
            cpu.R[6]++;
            cpu.PC+=1;
            break;

        case 0x0F:// INC R7
            cpu.R[7]++;
            cpu.PC+=1;
            break;

        case 0x10:// JBC
            break;
        
        case 0x11:// ACALL
            break;
        
        case 0x12:// LCALL
            break;
        
        case 0x13:// RRC
            tmp=cpu.A;
            cpu.A = (cpu.A>>1) | ( cpu.PSW & 0x80 );
            cpu.PSW = (cpu.PSW & 0x7F);
            cpu.PSW = ((tmp & 0x01) << 7) | cpu.PSW;
            cpu.PC+=1;
            break;

        case 0x14:// DEC A
            cpu.A--;
            cpu.PC+=1;
            break;
        
        case 0x15:// DEC direct
            break;
        
        case 0x16:// DEC @R0
            cpu.RAM[cpu.R[0]]--;
            cpu.PC+=1;
            break;

        case 0x17:// DEC @R1
            cpu.RAM[cpu.R[1]]--;
            cpu.PC+=1;
            break;

        case 0x18:// dec r0
            cpu.R[0]--;
            cpu.PC+=1;
            break;

        case 0x19:// dec r1
            cpu.R[1]--;
            cpu.PC+=1;
            break;

        case 0x1A:// dec r2
            cpu.R[2]--;
            cpu.PC+=1;
            break;

        case 0x1B:// dec r3
            cpu.R[3]--;
            cpu.PC+=1;
            break;

        case 0x1C:// dec r4
            cpu.R[4]--;
            cpu.PC+=1;
            break;

        case 0x1D:// dec r5
            cpu.R[5]--;
            cpu.PC+=1;
            break;

        case 0x1E:// dec r6
            cpu.R[6]--;
            cpu.PC+=1;
            break;

        case 0x1F:// dec r7
            cpu.R[7]--;
            cpu.PC+=1;
            break;

        case 0x20:// JB offset
            break;
        
        case 0x21:// AJMP
            break;
        
        case 0x22:// RET
            break;
        
        case 0x23:// RL
            
            break;

        
    }
}