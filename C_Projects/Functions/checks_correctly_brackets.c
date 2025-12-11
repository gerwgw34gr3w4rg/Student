#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>


char *name_file = "checks_correctly_brackets.c";


bool checks_correctly_brackets(char *str){
    size_t size_str = 0;
    /*
    RU инструкция
    Функция принимает указатель на строку и ищет размер этой строки по '\0',
    если в строке нет '\0', поведение функции непредсказуемо!
    Не передавать в функцию строку, в которой нет '\0' !!!

    EU instruction
    The function takes a pointer to a string and searches for the size of this string by '\0',
    if there is no '\0' in the string, the function's behavior is unpredictable!
    Do not pass a string to the function where there is no '\0' !!!
    */
    while(str[size_str] != '\0'){  // scan size arr
        size_str++;
    }

    size_t open_brackets_size = size_str / 2;
    char *open_brackets = (char *)malloc(sizeof(char) * open_brackets_size);
    if(NULL == open_brackets){
        fprintf(stderr, "\nError - pointer = NULL\nName file - %s\nLine = %d\n\n"
                        "Press enter to continue executing the program,"
                        " the function will return false\n", name_file, __LINE__ - 3);
        getchar();
        return false;
    }

    size_t i = 0, j = 0;
    for(;;){  // scan ( ), { }, < >, [ ]
        if('\0' == str[i]){
            if(0 != j){
                free(open_brackets);
                return false;
            }
            free(open_brackets);
            return true;
        }
        else if(str[i] == '(' or str[i] == '{' or str[i] == '<' or str[i] == '['){
            if(j == open_brackets_size){
                free(open_brackets);
                return false;
            }
            if(str[i] == '('){
                open_brackets[j] = str[i] + 1;  // by table symbols ASCII: ( + 1 = )
                j++;
            }
            else{
                open_brackets[j] = str[i] + 2;  // by table symbols ASCII: { + 2 = } or < + 2 = > or [ + 2 = ]
                j++;
            }
        }
        else if(str[i] == ')' or str[i] == '}' or str[i] == '>' or str[i] == ']'){
            if(0 == j){
                free(open_brackets);
                return false;
            }
            j--;
            if(str[i] != open_brackets[j]){
                free(open_brackets);
                return false;
            }
        }
        i++;
    }
}