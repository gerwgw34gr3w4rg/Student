



#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


int main(){
    int number;
    printf("Введите число\n");
    if (scanf("%d", &number) != 1){
        printf("Error\n");
        abort();
    }
    if (number < 0 or number > 1000){
        printf("Ты выходишь за рамки диапазона\n");
    }
    else if (number % 2 == 0){
        printf("Even\n");
    }
    else {
        printf("Odd\n");
    }
    return 0;
}
