#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


typedef struct Rectangle_s{
    unsigned int width;
    unsigned int height;
} Rectangle;

Rectangle *Rectangle_new(unsigned int width, unsigned int height);
void Rectangle_free(Rectangle **rectangle_pointer);

int main(){
    Rectangle window = {.height = 5, .width = 7};
    printf("%u\n", window.height);
    printf("%u\n", window.width);

    //Rectangle *box = (Rectangle *)malloc(sizeof(Rectangle) * (size_t)1000 * (size_t)1000 * (size_t)1000);
    Rectangle *box = (Rectangle *)malloc(sizeof(Rectangle));
    if(NULL == box){
        fprintf(stderr, "Error line %d\n", (__LINE__ -1));
        return 0;
    }

    box -> height = 10;
    box -> width = 20;
    printf("%u\n", box -> height);
    printf("%u\n", box -> width);
    
    Rectangle *figure = Rectangle_new((unsigned int)5, 15u);
    printf("width = %u\n", figure -> width);
    printf("height = %u\n", figure -> height);

    Rectangle_free(&figure);


    free(box);
    box = NULL;
}

Rectangle *Rectangle_new(unsigned int width, unsigned int height){
    Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    if(NULL == rectangle){
        fprintf(stderr, "Error, memory allocation, line %d\n", __LINE__);
        return NULL;
    }
    rectangle -> width = width;
    rectangle -> height = height;

    return rectangle;
}

void Rectangle_free(Rectangle **rectangle_pointer){
    if(NULL == rectangle_pointer){
        fprintf(stderr, "Error, a NULL pointer was passed to the function, line =  %d\n", __LINE__); // в функцию был передан указатель NULL
        return;
    }
    if(NULL == *rectangle_pointer){
        fprintf(stderr, "Warning, the memory pointed to is already NULL\n"); //Предупреждение, память по указателю уже NULL
        return;
    }

    free(*rectangle_pointer);
    *rectangle_pointer = NULL;
}