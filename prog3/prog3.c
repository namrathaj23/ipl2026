#include <stdio.h>

/* Function to print bits of an integer */
void printIntBits(int n)
{
    int i;

    printf("Bits of integer:\n");

    for(i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);

        if(i % 8 == 0)
            printf(" ");
    }

    printf("\n");
}

/* Function to count number of 1 bits */
int countOneBits(int n)
{
    int count = 0;

    while(n != 0)
    {
        if(n & 1)
            count++;

        n = n >> 1;
    }

    return count;
}

/* Function to check endian */
void checkEndian()
{
    int x = 1;

    char *p = (char *)&x;

    if(*p == 1)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}

/* Function to print bits of a float */
void printFloatBits(float f)
{
    int i;

    int *p = (int *)&f;

    printf("Bits of float:\n");

    for(i = 31; i >= 0; i--)
    {
        printf("%d", ((*p >> i) & 1));

        if(i == 31 || i == 23)
            printf(" ");
    }

    printf("\n");
}

int main()
{
    int n;
    float f;

    /* Integer input */
    printf("Enter an integer: ");
    scanf("%d", &n);

    printIntBits(n);

    printf("Number of 1 bits = %d\n", countOneBits(n));

    /* Endian check */
    checkEndian();

    /* Float input */
    printf("\nEnter a floating point number: ");
    scanf("%f", &f);

    printFloatBits(f);

    return 0;
}
