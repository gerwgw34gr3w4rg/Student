#include <stdio.h>

#include "encapsulation.c"


int main(void) {
    Person *ivan = Person_init("Ivan", 5);
    Person_print(ivan);
    Person_set_name(ivan, "Jack");
    Person_set_age(ivan, 71);
    Person_print(ivan);
    Person_delete(ivan);
    ivan = NULL;
}