#include <stdio.h>

/* Verify the expression getchar() != EOF is 0 or 1. */

int main(void)
{
    // Prints 1 if the character isn't EOF, otherwise 0
    printf("%i\n", (getchar() != EOF));
}