#include <float.h>
#include <limits.h>
#include <stdio.h>

/*
Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct computation. Harder if you compute them:
determine the ranges of various floating-point types
*/

int main(void)
{
    // char
    printf("signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range: 0 to %d\n", UCHAR_MAX);

    // int
    printf("signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: 0 to %u\n", UINT_MAX);
    
    // long
    printf("signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long range: 0 to %lu\n", ULONG_MAX);

    // float and double
    printf("float range: %.10e - %.10e\n", FLT_MIN, FLT_MAX);
    printf("double range: %.10e - %.10e\n", DBL_MIN, DBL_MAX);
}