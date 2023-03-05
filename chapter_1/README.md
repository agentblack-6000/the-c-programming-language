# The C Programming Language: Chapter 1

## Contents

1. [1.1 Getting Started](#11-getting-started)
    - [Exercise 1-1](#exercise-1-1)
    - [Exercise 1-2](#exercise-1-2)
2. [1.2 Variables and Arithmetic Expressions](#12-variables-and-arithmetic-expressions)
    - [Exercise 1-3](#exercise-1-3)
    - [Exercise 1-4](#exercise-1-4)
3. [1.3 The For Statement](#13-the-for-statement)
    - [Exercise 1-5](#exercise-1-5)
4. [1.4 Symbolic Constants](#14-symbolic-constants)
5. [1.5 Character Input and Output](#15-character-input-and-output)
    - [1.5.1 File Copying](#151-file-copying)
        - [Exercise 1-6](#exercise-1-6)
        - [Exercise 1-7](#exercise-1-7)
    - [1.5.2 Character Counting](#152-character-counting)
    - [1.5.3 Line Counting](#153-line-counting)
        - [Exercise 1-8](#exercise-1-8)
        - [Exercise 1-9](#exercise-1-9)
        - [Exercise 1-10](#exercise-1-10)
    - [1.5.4 Word Counting](#154-word-counting)
        - [Exercise 1-11](#exercise-1-11)
        - [Exercise 1-12](#exercise-1-12)
6. [1.6 Arrays](#16-arrays)

## 1.1 Getting Started

The first step in learning any programming language is to print the words "hello, world" to the screen.
The C code to do this is-

```c
#include <stdio.h>

int main(void) {
    printf("hello, world\n");
}
```

Using `clang`-

```shell
clang hello.c -o hello
./hello
```

Using `gcc`-

```shell
gcc hello.c
./a.out
```

A C program always consists of functions and variables, no matter its size. The `main()` function is special, that's where program execution begins, i.e every program needs to have a `main()` function somehwere.

The first line in the `hello.c` code snippet,

```c
#include <stdio.h>
```

includes information about the standard I/O library, which is used in `main()` to call the function `print()` with the arugment `"hello, world\n"`.

A sequence of characters in double quotes, such as "hello, world" is called a character string or string constant in C. The `\n` is used for printing a newline character.

C also has other escape sequences-

|  Escape Sequence  |    Usage          |
|----|--------------|
| \t | tab          |
| \b | backspace    |
| \" | double quote |
| \\ | backslash    |

## Exercises

### Exercise 1-1

Experiment with leaving out parts of the program to see what error messages you can get.

|  "error"  |   What `clang` screamed    |
|----|--------------|
| mispelled `main()` | undefined symbols for architecture arm64 |
| mispelled `<stdio.h>` | `<studio.h>` not found |
| mispelled `#include` | invalid preprocessing directive |
| mispelled `printf()` | implict function declaration |
| missing `}` | expected `}` to match `{` |
| missing `;` | expected `;` after expression |
| missing `>` | expected `>` |
| missing `"` | missing terminating `"` |

### Exercise 1-2

Experiment to find out what happens when `printf`'s argument string contains `\c`, where `c` is some character not listed above.

|  escape sequence  |  output   |
|----|--------------|
| `\q`, `\w`, `\y`, `\o`, `\p`, `\s`, `\d`, `\g`, `\h`, `\j`, `\k`, `\l`, `\z`, `\c`, `\m`, `\0`, `\~`, `\}`, `\!`, `\|`, `\>`, `\=`  | invalid escape sequence |
| `\e`, `\a`, `\1`...`\9`  | no new line |
| `\u`, `\x`  | hex digits |
| `\f`, `\v`  | prints "hello, world", new line and then enough space for "hello, world" |
| `\t` | tab stop |
| `\b` | last character missing(backslash) |

## 1.2 Variables and Arithmetic Expressions

This program prints out the conversion of Fahrenheit temperatures to their Celsius equivalents.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

 int main(void)
 {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius Fahrenheit\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
 }
```

These two lines-

```c
/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
```

are a comment, which briefly explain what the program does, any characters between `/*` and `*/` will be ignored by the compiler.

In C, all variables must be declared before they are used, which announces the properties of the variables. A declaration consists of a type name and list of variables, such as-

```c
int fahr, celsius;
int lower, upper, step;
```

The type `int` means that the variables listed are integers, in contrast to the type `float`, which may have some fractional part.

C provides a few from basic data types-

| type | description |
|----|-----|
| `int` | integer |
| `float` | floating point |
| `long` | long integer |
| `double` | double-precision floating point |
| `char` | character- a single byte |

After all the variables are assigned their inital values, a `while` loop is used.
The statements in the `while` loop execute if the condition in the parentheses are true, which are tested each iteration.

The reason for multiplying by 5 and then dividing by 9 is because integer division truncates, i.e any fractional part is discarded. Since 5/9 < 0, it would be truncated to 0 and all the Celsius temperatures would display as 0.

Each `%` construction in `printf` is paired with the corresponding arguments in `printf`, which specify in what form the argument is to be printed. `%d` specifies an integer argument, so the values of the integers `fahr` and `celsius` will be printed.

`%d` can also be prefixed with numbers to specify how wide the integers should be printed, for example

```c
printf("%3d \t %6d\n", fahr, celsius);
```

specifies that `fahr` should be printed in a field 3 digits wide, and `celsius` should be printed in a field 6 digits wide.

However, these results aren't acurate, we need to use the `float` data type to get the correct conversion

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

 int main(void)
 {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
 }
```

Here, `5.0 / 9.0` isn't truncated to 0 because this is floating-point division. If an arithmetic operation has one floating-point operand and one integer operand, the integer will be converted to floating point before the observation is done.

`%3.0f` in `printf` specifies that a floating-point number is to be printed atleast 3 characters wide, without a decimal point and no fraction digits.

`%6.1f` in `printf` specifies that a floating-point number is to be printed at least 6 characters wide, with 1 digit after the decimal point.

`printf` also recognises `%o` for octals, `%x` for hexadecimal, `%c` for characters, `%s` for strings, and `%%` for the `%` itself.

## Exercises

### Exercise 1-3

Modify the temperature conversion program to print a heading above the table.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

 int main(void)
 {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit Celsius\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
 }
 ```

### Exercise 1-4

Write a prgram to print the corresponding Celsius to Fahrenheit table.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius Fahrenheit\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = ((9.0 / 5.0) * celsius) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
```

## 1.3 The For Statement

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

int main(void)
{
    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
```

The `for` statement is a generalization of the `while`. The first part is the initalization, before the loop is entered. (`fahr = 0`), followed by the condition that controls the loop (`fahr <= 300`), and the increment step (`fahr += 20`), and then the condition is re-evaluated.

`for` is great because it is cleaner(uses fewer variables), and more compact (keeps control statements in one place).

## Exercises

### Exercise 1-5

Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

int main(void)
{
    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
```

## 1.4 Symbolic Constants

It's bad practice to leave "magic" numbers-

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

int main(void)
{
    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
```

like `300` and `20`, because-

1. They convey little information to someone who might have to read the program later.
2. They're hard to change quickly

To deal with them, we give them meaningful names.

`#define name replacement_text`

`#define` defines a symbolic constant, such that all occurences of `name` will be replaced by `replacement_text`. `replacement_text` can be any sequence of characters, not just numbers.

```c
#include <stdio.h>

#define  LOWER  0
#define  UPPER  300
#define  STEP   20

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

int main(void)
{
    int fahr;

    printf("Fahrenheit Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
```

## 1.5 Character Input and Output

Text input or output is dealt with as streams of characters. A text stream is a sequence of characters divided into lines, consisting of zero or more characters followed by `\n`.

The standard library provides several functions for reading/writing one character at a time, of which `getchar` and `putchar` are the simplest.

### 1.5.1 File Copying

Knowing `getchar` and `putchar`, we can write a suprising amount of useful code without knowing anything more about I/O.

```c
#include <stdio.h>

int main(void)
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}
```

This program keeps reading a character and printing it out until the character is `EOF`(copies the input). Here, `int` instead of `char`(1 byte) as `c` must be big enough to store `EOF`, which is defined as an integer(4 bytes) in `<stdio.h>`. Since we're using the symbolic constant, nothing in the program depends on a specific numeric value.

`EOF` is defined as `-1`, see code snippet if you want to check:

```c
#include <stdio.h>

int main(void)
{
    printf("%lu", sizeof(EOF));
}
```

A more concise way of writing the copy program:

```c
#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}
```

This is because an assignment in C is an expression that has a value, which can appear as a larger expression. The test condition in the `while` gets a character, assigns it to `c`, and then tests if the character was `EOF`, if not executes the body of the loop otherwise exits.

The `()` around the assignment are necessary because the precedence of `!=` if higher than that of `=`, i.e the statement:

```c
c = getchar() != EOF
```

would be equivalent to:

```c
c = (getchar() != EOF)
```

This would assign `c` to 1 or 0(True or False depending on the call of `getchar` encountered `EOF`).

## Exercises

### Exercise 1-6

Verify the expression `getchar() != EOF` is 0 or 1.

```c
#include <stdio.h>

int main(void)
{
    // Prints 1 if the character isn't EOF, otherwise 0
    printf("%i\n", (getchar() != EOF));
}
```

### Exercise 1-7

Write a program to print the value of EOF.

```c
#include <stdio.h>

int main(void)
{
    printf("%lu", sizeof(EOF));
}
```

### 1.5.2 Character Counting

This program counts characters

```c
#include <stdio.h>

/* counts characters in input */
int main(void) 
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}
```

The `++` operator means increment by 1, the corresponding `--` means decrement by 1. These can be prefix operators (`++nc`) or postfix operators (`nc++`).

The program uses a `long` instead of an `int`, as the `int` has a maximum value of 32767, which might cause it to overflow quite quickly.

Another way to write this program using a `double` and a `for` loop:

```c
#include <stdio.h>

/* counts characters in input */
int main(void) 
{
    double nc;

    for (nc = 0; getchar() != EOF; nc++)
        ;
    
    printf("%.0f\n", nc);
}
```

The body of the loop is empty, because all the work is done in the test and increment. Since C requires the `for` statement to have a body, the isolated semicolon, called a null statement, satifies that condtion.

### 1.5.3 Line Counting

```c
#include <stdio.h>

/* count lines in input */
int main(void)
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}
```

The `==` sign is C's notation for "is equal to". A character written in between `''` represents an integer value equal to the numerical value of the character in the machine's character set(`A` is a character constant, its value is 65 in the ASCII character set, so it's represented internally as `65`, similarly `\n` is `10`).

## Exercises

### Exercise 1-8

Write a program to count blanks, tabs, and newlines.

```c
#include <stdio.h>

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
```

### Exercise 1-9

Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

```c
#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(' ');
            while((c = getchar()) == ' ');
        }
        putchar(c);
    }
}
```

### Exercise 1-10

Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`.

PS: I'm kinda pround of this answer because it works only on the knowledge based on the previous sections, unlike the ones on the web. See my answer on StackOverflow [here](https://stackoverflow.com/questions/14206753/kr-1-10-the-terminal-eats-the-backspace/)!

```c
#include <stdio.h>

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
```

### 1.5.4 Word Counting

A bare-bones program of the UNIX program `wc`:

```c
#include <stdio.h>

#define IN  1
#define OUT 0

/* count lines, words, and characters in input */
int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT) 
        {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
}
```

Every time the program encounters the first character of a word, it counts one more word. `state` records if the program is currently in a word or not.

Here, symbolic constants `IN` and `OUT` are used to make the program more readable.

The line-

```c
nl = nw = nc = 0;
```

sets all three variables to 0. The `||` operator means OR, and a corresponding `&&` for AND, which has a precedence just higher than the OR, evaluated left to right.

The program also uses `else`, an alternative action if the condition in the `if` statement is false. The general form is

```txt
if (expression) 
{
    code
}
else
{
    code
}
```

Only one of the code blocks is executed. The `else if` evaluates another condition, instead of just executing like an `else` block.

## Exercises

### Exercise 1-11

How would you test the word count program? What kinds of input are most likely to uncover bugs, if there are any?

```txt
The program can be tested by compiling and executing it. The program doesn't check for punctuation or words with apostrophes, etc.
```

### Exercise 1-12

Write a program that prints its input one word per line.

```c
#include <stdio.h>

#define IN  1
#define OUT 0

/* prints its input one word per line */
int main(void)
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            printf("\n");
        }
        else if (state == OUT)
        {
            state = IN;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
}
```

## 1.6 Arrays

A program that counts the occurences of each digit, white space characters, and all other characters.

```c
#include <stdio.h>

/* count digits, white space, and other characters */
int main(void)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
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

    printf("digits =");
    for (i = 0; i < 10; ++i)
    {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
```

The line:

```c
int ndigit[10];
```

initializes an array of 10 integers. Arrary subscripts always start at `0` in C, the elements that can be accessed are `ndgit[0], ..., ndigit[9]`. The `if` statements determine if `c` is a digit(\```0``\` - \```9``\` which have increasing character values in ASCII), whitespace character, or another character.

`chars` are just small integers, `char` variables and constants are identical to integers in arithmetic expressions in C.

The statements:

```txt
if (condition-1)
    statement-1
else if (condition-2)
    statement-2
...
else if (condition-n)
    statement-n
else
    statement
```

refer to a multi-way decision, the conditions are evaluated in order until a condition is true, otherwise the `else` block is executed. If there is no `else`, nothing will be done.
