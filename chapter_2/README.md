# The C Programming Language: Chapter 2

## Contents

1. [2.1 Variable Names](#21-variable-names)

## 2.1 Variable Names

Restrictions on variable names and symbolic constants:

1. Names can contain letters and numbers, and the first character must be a letter
2. The `_` counts as a letter, useful for improving readability, however variable names should
not start with an `_` as library routines often use such names
3. Uppercase and lowercase letters are distinct, `x` and `X` are different variables
4. Keywords like `if`, `else`, `int`, `float`, etc. are reserved and can't be used as variable names

Traditional C practice is to use lower case for variable names and uppercase for symbolic constants

