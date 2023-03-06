#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different characters in its input */

int main(void)
{
    int c, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (int i = 0; i < 10; ++i)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c-'0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("|%2d|", i);
        for (int j = 0; j < ndigit[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    
    printf("| whitespace | ");
    for (int i = 0; i < nwhite; ++i)
    {
        printf("*");
    }
    printf("\n| all other characters | ");
    for (int i = 0; i < nother; ++i)
    {
        printf("*");
    }
    printf("\n");
}