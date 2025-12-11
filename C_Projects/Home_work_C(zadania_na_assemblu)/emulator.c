#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define REGISTERS_AMOUNT 4

#define A 0u
#define B 1u
#define C 2u
#define D 3u


int main(int argc, char *argv[]){
#if 0
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    for(int i = 0; NULL != argv[i]; i++){
        printf("argv[%d]=|%s|\n", i, argv[i]);
    }
#endif

    uint8_t registers[REGISTERS_AMOUNT] = {0};
    if(argc != 2){
        fprintf(stderr, "Call: %s op <coders.mk>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if(NULL == file){
        fprintf(stderr, "Error opening file \"%s\":\n", argv[1]);
        perror("foepen");
        abort();
    }

    printf("\"%s\" was successfully opened for reading.", argv[1]);
    //EOF - End Of File
    for(;;){
        unsigned opcode;
        int fscanf_return = fscanf(file, "%x", &opcode);
        if(EOF == fscanf_return){
            break;
        }
        if(1 != fscanf_return){
            printf("ERROR");
            return 0;
        }
        if(0xc7 < opcode){ //0xC7 is the largest valid instruction
            printf("ERROR");
            return 0;
        }
        unsigned first_register_number = (opcode & 0b1100) >> 2;
        unsigned second_register_number = (opcode & 0b11);
        if(opcode < 0x80){ //0...0x7F MOVI
            registers[D] = (uint8_t)opcode;
        }
        else if(opcode < 0x90){ //0x80...0x8F ADD
            registers[first_register_number] += registers[second_register_number];
        }
        else if(opcode < 0xA0){ //0x90...0x9F SUB
            registers[first_register_number] -= registers[second_register_number];
        }
        else if(opcode < 0xB0){ //0xA0...0xAF MUL
            registers[first_register_number] *= registers[second_register_number];
        }
        else if(opcode < 0xC0){ //0xB0...0xBF DIV
            registers[first_register_number] /= registers[second_register_number];
        }
        else if(opcode < 0xC4){ //0xC0...0xC3 IN
            uint8_t value;
            if (scanf("%", SCNu8, &value) != 1){
                printf("ERROR");
                return 0;
            }
            registers[second_register_number] = value;
        }
        else if (opcode < 0xC8){ //0xC4...0xC7 OUT
            printf("%", PRIu8 " ", registers[second_register_number]);
        }
        else {
            fprintf(stderr, "What The Fucking Shit!!! \n Fix That Fucking Big!!!\n");
            abort();
        }
    }
    printf("\b");
    fclose(file);
    return 0;
}