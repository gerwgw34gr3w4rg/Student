#include <stdio.h>

#include "encapsulation.c"


int main(void) {
    Person *ivan = Person_init("Ivan", 5);
    ivan -> print(ivan);
    ivan -> set_age(ivan, 89);
    ivan -> set_name(ivan, "Peter");
    ivan -> print(ivan);
    Person_delete(ivan);
    ivan = NULL;
}