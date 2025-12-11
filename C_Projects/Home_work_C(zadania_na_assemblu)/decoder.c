#include <stdio.h>
#include <stdlib.h>


#define INSTRUCTIONS_AMOUNT (size_t)256
char *assembler[INSTRUCTIONS_AMOUNT] = {
    "MOVI 0", "MOVI 1", "MOVI 2", "MOVI 3", "MOVI 4", "MOVI 5", "MOVI 6", "MOVI 7", 
    "MOVI 8", "MOVI 9", "MOVI 10", "MOVI 11", "MOVI 12", "MOVI 13", "MOVI 14", "MOVI 15", 
    "MOVI 16", "MOVI 17", "MOVI 18", "MOVI 19", "MOVI 20", "MOVI 21", "MOVI 22", "MOVI 23", 
    "MOVI 24", "MOVI 25", "MOVI 26", "MOVI 27", "MOVI 28", "MOVI 29", "MOVI 30", "MOVI 31", 
    "MOVI 32", "MOVI 33", "MOVI 34", "MOVI 35", "MOVI 36", "MOVI 37", "MOVI 38", "MOVI 39", 
    "MOVI 40", "MOVI 41", "MOVI 42", "MOVI 43", "MOVI 44", "MOVI 45", "MOVI 46", "MOVI 47", 
    "MOVI 48", "MOVI 49", "MOVI 50", "MOVI 51", "MOVI 52", "MOVI 53", "MOVI 54", "MOVI 55", 
    "MOVI 56", "MOVI 57", "MOVI 58", "MOVI 59", "MOVI 60", "MOVI 61", "MOVI 62", "MOVI 63", 
    "MOVI 64", "MOVI 65", "MOVI 66", "MOVI 67", "MOVI 68", "MOVI 69", "MOVI 70", "MOVI 71", 
    "MOVI 72", "MOVI 73", "MOVI 74", "MOVI 75", "MOVI 76", "MOVI 77", "MOVI 78", "MOVI 79", 
    "MOVI 80", "MOVI 81", "MOVI 82", "MOVI 83", "MOVI 84", "MOVI 85", "MOVI 86", "MOVI 87", 
    "MOVI 88", "MOVI 89", "MOVI 90", "MOVI 91", "MOVI 92", "MOVI 93", "MOVI 94", "MOVI 95", 
    "MOVI 96", "MOVI 97", "MOVI 98", "MOVI 99", "MOVI 100", "MOVI 101", "MOVI 102", "MOVI 103", 
    "MOVI 104", "MOVI 105", "MOVI 106", "MOVI 107", "MOVI 108", "MOVI 109", "MOVI 110", "MOVI 111", 
    "MOVI 112", "MOVI 113", "MOVI 114", "MOVI 115", "MOVI 116", "MOVI 117", "MOVI 118", "MOVI 119", 
    "MOVI 120", "MOVI 121", "MOVI 122", "MOVI 123", "MOVI 124", "MOVI 125", "MOVI 126", "MOVI 127",
    "ADD A, A", "ADD A, B", "ADD A, C", "ADD A, D", "ADD B, A", "ADD B, B", "ADD B, C", "ADD B, D", 
    "ADD C, A", "ADD C, B", "ADD C, C", "ADD C, D", "ADD D, A", "ADD D, B", "ADD D, C", "ADD D, D", 
    "SUB A, A", "SUB A, B", "SUB A, C", "SUB A, D", "SUB B, A", "SUB B, B", "SUB B, C", "SUB B, D", 
    "SUB C, A", "SUB C, B", "SUB C, C", "SUB C, D", "SUB D, A", "SUB D, B", "SUB D, C", "SUB D, D", 
    "MUL A, A", "MUL A, B", "MUL A, C", "MUL A, D", "MUL B, A", "MUL B, B", "MUL B, C", "MUL B, D", 
    "MUL C, A", "MUL C, B", "MUL C, C", "MUL C, D", "MUL D, A", "MUL D, B", "MUL D, C", "MUL D, D", 
    "DIV A, A", "DIV A, B", "DIV A, C", "DIV A, D", "DIV B, A", "DIV B, B", "DIV B, C", "DIV B, D", 
    "DIV C, A", "DIV C, B", "DIV C, C", "DIV C, D", "DIV D, A", "DIV D, B", "DIV D, C", "DIV D, D", 
    "IN A", "IN B", "IN C", "IN D", "OUT A", "OUT B", "OUT C", "OUT D", 
};

#if 0
char *decoder(unsigned command);


int main(){
    unsigned command;
    int scanf_returns = scanf("%x", &command);
    while (EOF != scanf_returns){
        if (scanf_returns != 1){
            printf("ERROR");
            return 0;
        }
        char *instraction = decoder(command);
        if (NULL == instraction){
            printf("ERROR");
            return 0;
        }
        printf("%s\n", instraction);
        scanf_returns = scanf("%x", &command);
    }
    
}
#endif

char *decoder(unsigned command){
    if (command >= INSTRUCTIONS_AMOUNT){
        return NULL;
    }
    if (NULL == assembler[command]){
        return NULL;
    }
    return assembler[command];
}