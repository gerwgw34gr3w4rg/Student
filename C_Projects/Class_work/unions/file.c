#include <stdio.h>
#include <inttypes.h>


union internals_u {
    unsigned n;
    uint8_t n8[4];
    uint16_t n16[2];
    int n32int;
};


int main(int argc, char *argv[]){
    union internals_u internals;
    internals.n = 4001497518;
    printf("n = %u\n", internals.n);
    printf("n8 = %" PRIu8 "\t%" PRIu8 "\t%" PRIu8 "\t%" PRIu8 "\n",
            internals.n8[0], internals.n8[1], internals.n8[2], internals.n8[3]);
    printf("n16 = %" PRIu16 " %" PRIu16 "\n", internals.n16[0], internals.n16[1]);
    printf("n32int = %d\n", internals.n32int);

    printf("\n%s done!\n", argv[0]);
    printf("\n%s done!\n", __FILE__);
    getchar();
}