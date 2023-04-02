# The C Programming Language: Chapter 2

## Contents

1. [2.1 Variable Names](#21-variable-names)
2. [2.2 Data Types and Sizes](#22-data-types-and-sizes)

## 2.1 Variable Names

Restrictions on variable names and symbolic constants:

1. Names can contain letters and numbers, and the first character must be a letter
2. The `_` counts as a letter, useful for improving readability, however variable names should
not start with an `_` as library routines often use such names
3. Uppercase and lowercase letters are distinct, `x` and `X` are different variables
4. Keywords like `if`, `else`, `int`, `float`, etc. are reserved and can't be used as variable names

Traditional C practice is to use lower case for variable names and uppercase for symbolic constants

## 2.2 Data Types and Sizes

C data types:

| type | description |
|------|-------------|
| char | a singe byte capable of storing one character|
| int | an integer |
| float | single-precision floating point |
| double | double-precision floating point |

Qualifiers that can be added to `ints`
| qualifier | description |
|-----------|-------------|
| short | short integers are 16-bits (depends on the compiler) |
| long | long integers are 32-bits (depends on the compiler) |

Restrictions on the compiler:

1. `shorts` and `ints` are atleast 16-bits
2. `longs` are atleast 32 bits
3. `short` isn't longer than `int`
4. `int` isn't longer than `long`

Qualifiers that can be added to `ints` and `chars`
| qualifier | description |
|-----------|-------------|
| unsigned | unsigned numbers are always positive or greater than 0 |
| signed | numbers that can be positive, negative, or zero |

If `chars` are n-bits, `signed chars` range from -2^n to 2^n-1, `unsigned chars` range from 0 to 2^n-1,
if n = 8, signed chars would range from -128 to 127, unsigned chars would range from 0 to 255

The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all these sizes and other
properties of the machine and compiler
