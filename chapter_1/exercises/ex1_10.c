#include <stdio.h>

/* Write a program to copy its input to its output, 
replacing each tab by \t, each backspace by \b, and each backslash by \\. */

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
            while ((c = getchar()) == '\t')
                printf("\\t");
        }

        if (c == '\\')
        {
            printf("\\\\");
            while ((c = getchar()) == '\\')
                printf("\\\\");
        }

        if (c == '\b')
        {
            printf("\\b");
            while ((c = getchar()) == '\b')
                printf("\\b");
        }

        putchar(c);
    }
}