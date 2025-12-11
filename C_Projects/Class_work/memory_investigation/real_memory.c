#include <stdio.h>
#include <assert.h>

#include "binary_byte_string.c"


void print_real_memory(unsigned *n){
    assert(NULL != n);

    printf("address of n: %p\n", &n);
    printf("n=: %12p\n", n);
    printf("*n=0x%x\n", *n);

    unsigned char *bytes = (unsigned char *)n;

    printf("  bytes of n: ");
    for (size_t i = 0; i < sizeof(unsigned); i++){
        printf("    %s\t", binary_byte_string[(size_t)bytes[i]]);
    }
    printf("\n");

    printf("  bytes of n: ");
    for (size_t i = 0; i < sizeof(unsigned); i++){
        printf("%12x\t", (unsigned)bytes[i]);
    }
    printf("\n");

    printf("   addresses: ");
    for (size_t i = 0; i < sizeof(unsigned); i++){
        printf("%p\t", &bytes[i]);
    }
    printf("\n\n");
}

int main(void){
    unsigned x = 0xaabbccdd;
    unsigned y = 0x11223344;
    unsigned z = 0x1a2b3c4d;
    print_real_memory(&x);
    print_real_memory(&y);
    print_real_memory(&z);
}