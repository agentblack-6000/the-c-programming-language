#include <stdio.h>

/*
Experiment with leaving out parts of the program to see what error messages you can get.

mispelled main(): undefined symbols for architecture arm64 
mispelled <stdio.h>: <studio.h> not found 
mispelled #include: invalid preprocessing directive 
mispelled printf(): implict function declaration 
missing } : expected } to match { 
missing ; : expected ; after expression 
missing > : expected >
missing " : missing terminating 
*/

int main(void)
{
    printf("hello, world\n");
}