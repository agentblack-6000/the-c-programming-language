#include <stdio.h>

#define  LOWER  0
#define  UPPER  300
#define  STEP   20

/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

float fahr_to_celsius(int fahr);

int main(void)
{
    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3d %6.1f\n", fahr, fahr_to_celsius(fahr));
    }
}

/* fahr_to_celsius: converts Fahrenheit to Celsius */
float fahr_to_celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}