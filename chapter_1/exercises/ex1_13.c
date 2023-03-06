#include <stdio.h>

#define LEN 10

/* Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */
int main(void)
{
    int c, lw;
    int lwords[LEN];

    lw = 0;

    for (int i = 0; i < LEN; ++i)
    {
        lwords[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',')
        {
            if (lw < LEN)
            {
                lwords[lw - 1]++;
            }
            lw = 0;
        }
        else
        {
            lw++;
        }
    }

    for (int i = 0; i < LEN; ++i)
    {
        printf("|%2d| ", i + 1);
        for (int j = 0; j < lwords[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}