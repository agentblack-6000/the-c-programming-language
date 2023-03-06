#include <stdio.h>

/*
Experiment to find out what happens when printf's argument string contains \c, 
where c is some character not listed above.

\q, \w, \y, \o, \p, \s, \d, \g, \h, \j, \k, \l, \z, \c, \m, \0, 
\~, \}, \!`, \|, \>, \=: invalid escape sequence 
\e, \a, \1`...\9: no new line
\u, \x: hex digits
\f, \v: prints "hello, world", new line and then enough space for "hello, world"
\t: tab stop
\b: last character missing(backslash)
*/

int main(void)
{
    printf("hello, world\n");
}