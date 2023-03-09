#include <stdio.h>

// maximum input line size
#define MAXLINE 1000

int getlinelen(char line[], int maxline);
void copy(char to[], char from[]);


/* 
Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily
long input lines, and as much as possible of the text
*/

/* print longest input line */
int main(void)
{
    // current line length
    int len;

    int c;

    // maximum line length
    int max;

    // current line
    char line[MAXLINE];

    // the longest line
    char longest[MAXLINE];

    // gets a line and checks if its length is greater than the maximum length so far, if so, saves it
    max = 0;
    while ((len = getlinelen(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')
        {
            while ((c = getchar()) != EOF && c != '\n')
            {
                ++len;
            }
        }
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    // prints the longest line
    if (max > 0)
    {
        printf("%slength: %d\n", longest, max);
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

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    // copies to into from until \0 is found 
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}