#include <stdio.h>


typedef struct {
    int age;
    char *name;
}Person;


int main(){
    struct Person p = {.age = 15, .name = "Ivan"};
    printf("p.age = %d p.name = %s\n", p.age, p.name);
    p.age = 20;
    printf("p.age = %d p.name = %s\n", p.age, p.name);
    getchar();
}