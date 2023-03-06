#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines. */

int main(void)
{
    int c, blanks, tabs, lines;

    blanks = tabs = lines = 0;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++lines;
        }
        else if (c == '\t')
        {
            ++tabs;
        }
        else if (c == ' ')
        {
            ++blanks;
        }
    }
    printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", blanks, tabs, lines);
}