# The C Programming Language: Chapter 1

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

    printf("Celsius Fahrenheit\n");
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
