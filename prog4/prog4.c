#include <stdio.h>

/* Structure with bitfields */
struct Bitfield {
    unsigned int firstbit  : 1;  // 1 bit
    unsigned int secondbit : 2;  // 2 bits
    unsigned int thirdbit  : 3;  // 3 bits
};

int main() {

    struct Bitfield a;

    /* Assign values */
    a.firstbit = 1;
    a.secondbit = 2;
    a.thirdbit = 5;

    /* Display values */
    printf("firstbit  = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("thirdbit  = %u\n", a.thirdbit);

    return 0;
}
