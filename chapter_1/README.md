# The C Programming Language: Chapter 1

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
