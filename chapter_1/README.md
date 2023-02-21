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
