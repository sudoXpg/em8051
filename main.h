#include<stdio.h>
#include<stddef.h>
#include<stdint.h>
#include<string.h>


typedef struct I8051{
    unsigned char A;
    unsigned char B;
    
    unsigned short opcode;
    unsigned short PC;
    unsigned short DPTR;
    unsigned char PSW;
    unsigned char SP;
    
    unsigned char ROM[4096];
    unsigned char RAM[128];

    unsigned char P[3];
    unsigned short timer[1];

    unsigned char TCON;
    unsigned char TMOD;
    unsigned char SCON;
    unsigned char PCON;
    unsigned char IP;
    unsigned char IE;
};

I8051 cpu;


void init(){
    
}