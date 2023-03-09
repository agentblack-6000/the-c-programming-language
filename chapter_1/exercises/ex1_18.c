#include <stdio.h>

// maximum input line size
#define MAXLINE 1000

int getlinelen(char line[], int maxline);
void strip(char string[], int length);

/* print longest input line */
int main(void)
{
    // current line length
    int len;

    // current line
    char line[MAXLINE];

    // gets a line and removes trailing blanks and tabs from each line of input
    while ((len = getlinelen(line, MAXLINE)) > 0)
    {
        strip(line, len);
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

void strip(char string[], int length)
{
    // goes through the string setting each space and tab to null
    int i = length - 2;
    while ((string[i] == ' ' || string[i] == '\t') && i > -1)
    {
        string[i] = '\0';
        --i;
    }

    // ends string with new line or if the string is blank prints nothing
    if (string[i + 1] == '\0' && string[i] != '\0')
    {
        string[i + 1] = '\n';
        string[i + 2] = '\0';
    }

    // prints out the string
    printf("%s", string);
}