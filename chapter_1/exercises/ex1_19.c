#include <stdio.h>

// maximum input line size
#define MAXLINE 1000

int getlinelen(char line[], int maxline);
void reverse(char string[], int length);

/*
Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses
its input a line at a time.
*/

/* print longest input line */
int main(void)
{
    // current line length
    int len;

    // current line
    char line[MAXLINE];

    // gets a line and reverses it
    while ((len = getlinelen(line, MAXLINE)) > 0)
    {
        reverse(line, len);
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

/* reverse: reverse string */
void reverse(char string[], int length)
{
    // -2 to not print \0 and \n
    for (int i = length - 2; i > -1; --i)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}