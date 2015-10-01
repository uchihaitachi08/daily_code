#include <stdio.h>

// Works for unsigned ints.
// Scroll down to the "actual algorithm" to see the interesting code.

// Utility function for displaying binary representation of an unsigned integer
void printBin(unsigned int x) {
    int i;
    for (i = 31; i >= 0; i--) printf("%i", (x >> i) & 1);
    printf("\n");
}
// Utility function to print out a separator
void printSep() {
    int i;
    for (i = 31; i>= 0; i--) printf("-");
    printf("\n");
}

int main()
{
    while (1)
    {
        unsigned int a, b;

        printf("Enter two unsigned integers separated by spaces: ");
        scanf("%u %u", &a, &b);
        getchar();

        printBin(a);
        printBin(b);
        printSep();

            /************ The actual algorithm starts here ************/

        // These are all the bits in a that are less than their corresponding bits in b.
        unsigned int ltb = ~a & b;

        // These are all the bits in a that are greater than their corresponding bits in b.
        unsigned int gtb = a & ~b;

        ltb |= ltb >> 1;
        ltb |= ltb >> 2;
        ltb |= ltb >> 4;
        ltb |= ltb >> 8;
        ltb |= ltb >> 16;
        

        // Nonzero if a > b
        // Zero if a <= b
        unsigned int isGt = gtb & ~ltb;

        // If you want to make this exactly '1' when nonzero do this part:
        isGt |= isGt >> 1;
        isGt |= isGt >> 2;
        isGt |= isGt >> 4;
        isGt |= isGt >> 8;
        isGt |= isGt >> 16;
        isGt &= 1;
        if(gtb)
            printf("yoho\n");
        else
            printf("yrgsago\n");

            /************ The actual algorithm ends here ************/

        // Print out the results.
        printBin(ltb); // Debug info
        printBin(gtb); // Debug info
        printSep();
        printBin(isGt); // The actual result
    }
}