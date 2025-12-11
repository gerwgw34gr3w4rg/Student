#include <stdio.h>


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
size_t scan_str_size(char *str){
    size_t size_str = 0;
    while(str[size_str] != '\0'){
        size_str++;
    }
    return size_str;
}
