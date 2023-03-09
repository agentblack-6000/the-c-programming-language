#include <stdio.h>

// maximum input line size
#define MAXLINE 1000
#define CHARLIMIT 80

int getlinelen(char line[], int maxline);

/* Write a program to print all the input lines that are longer than 80 characters */

/* print longest input line */
int main(void)
{
    // current line length
    int len;

    // current line
    char line[MAXLINE];

    // gets a line and prints it out if its length > CHARLIMIT
    while ((len = getlinelen(line, MAXLINE)) > 0)
    {
        if (len > CHARLIMIT)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int getlinelen(char line[], int maxline)
{
    int c, i;

    // copies char from user into line array
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    // increments c if last char is \n
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    // sets the last character of the array to \0
    line[i] = '\0';

    // returns the length of the array
    return i;
}