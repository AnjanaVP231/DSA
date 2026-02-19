# Static Memory Analyzer

A simple C program that analyzes another C program source file to estimate the total static memory required by its variable declarations.

## Overview

The `memory_analyzer` program reads a source file line by line, identifies variable declarations, and calculates the memory usage based on the data type and any array dimensions.

It supports:
- Basic types: `int`, `char`, `float`, `double`, `long`, `short`
- Array declarations: `int arr[10];`
- Pointers (basic detection): `int *ptr;`
- Multiple declarations on a single line: `int a, b[10];`

## Files

- `memory_analyzer.c`: The main source code for the analyzer tool.
- `test_program.c`: A sample C program with various declarations to test the analyzer.

## How to Compile

You can compile the analyzer using any standard C compiler like `gcc` or `clang`.

```bash
gcc memory_analyzer.c -o memory_analyzer
```

## How to Run

Run the executable and pass the target C file as an argument.

```bash
./memory_analyzer test_program.c
```

Or run without arguments and you will be prompted for a filename:

```bash
./memory_analyzer
Enter filename to analyze: test_program.c
```

## Example Output

```text
--- Analyzing Static Memory ---
Line: 'int a;' -> 4 bytes
Line: 'char b;' -> 1 bytes
Line: 'float c;' -> 4 bytes
Line: 'double d;' -> 8 bytes
Line: 'int arr[10];' -> 40 bytes
Line: 'char str[20];' -> 20 bytes
Line: 'float farr[5];' -> 20 bytes
Line: 'double darr[2];' -> 16 bytes

--------------------------------
Total Static Memory Required: 113 bytes
```

