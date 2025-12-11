#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


#include "pseudo_mc.h"


Instruction decode_command(uint8_t command);
void print_instruction(Instruction instruction);


int main(void){
    unsigned command;
    while(scanf("%x", &command) == 1){
        uint8_t cmd = (uint8_t)(command & 0xFF);
        assert(cmd == command);
        Instruction instruction = decode_command(cmd);
        print_instruction(instruction);
    }
}


Instruction decode_command(uint8_t command){
    Instruction instruction;
    // MOV
    if(0 == (command >> 7)){
        instruction.opcode = MOVI;
        instruction.operand.immediate = command;
        return instruction;
    }
    //IN / OUT
    else if(1 == ((command >> 6) & 0b01)){
        if(0x30 == (command >> 2)){
            instruction.opcode = IN;
        }
        else if(0x31 == (command >> 2)){
            instruction.opcode = OUT;
        }
        else{
            fprintf(stderr, "Bad IN/OUT %x\n", (unsigned)command);
            abort();
        }
        int rf1 = command & 0b11;
        instruction.operand.register_ = rf1;
        return instruction;
    }

    instruction.operand.operands.rd = (command >> 2) & 0b11;
    instruction.operand.operands.rs = (command) & 0b11;
    //ADD
    if(0x8 == (command >> 4)){
        instruction.opcode = ADD;
        return instruction;
    }
    //SUB
    else if(0x9 == (command >> 4)){
        instruction.opcode = SUB;
        return instruction;
    }
    //MUL
    else if(0xA == (command >> 4)){
        instruction.opcode = MUL;
        return instruction;
    }
    //DIV
    else if(0xB == (command >> 4)){
        instruction.opcode = DIV;
        return instruction;
    }
    fprintf(stderr, "Unrecognized instruction %x\n", (unsigned)command);
    abort();
}

const char *register_names[] = {"A", "B", "C", "D"};

void print_instruction(Instruction instruction){
    if(MOVI == instruction.opcode){
        printf("MOVI D, %d\n", instruction.operand.immediate);
    }
    else if(IN == instruction.opcode){
        printf("IN %s\n", register_names[instruction.operand.register_]);
    }
    else if(OUT == instruction.opcode){
        printf("OUT %s\n", register_names[instruction.operand.register_]);
    }
    else if(ADD == instruction.opcode){
        printf("ADD %s, %s\n", register_names[instruction.operand.operands.rd],
                                register_names[instruction.operand.operands.rs]);
    }
    else if(SUB == instruction.opcode){
        printf("SUB %s, %s\n", register_names[instruction.operand.operands.rd],
                                register_names[instruction.operand.operands.rs]);
    }
    else if(MUL == instruction.opcode){
        printf("MUL %s, %s\n", register_names[instruction.operand.operands.rd],
                                register_names[instruction.operand.operands.rs]);
    }
    else if(DIV == instruction.opcode){
        printf("DIV %s, %s\n", register_names[instruction.operand.operands.rd],
                                register_names[instruction.operand.operands.rs]);
    }
    else{
        fprintf(stderr, "Unsupported instraction\n");
        abort();
    }
}