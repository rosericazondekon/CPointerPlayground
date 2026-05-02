# CPointerPlayground
[![Build and Test](https://github.com/rosericazondekon/CPointerPlayground/actions/workflows/check-standard.yaml/badge.svg)](https://github.com/rosericazondekon/CPointerPlayground/actions/workflows/check-standard.yaml)

A focused, hands-on C playground for mastering pointers from first principles to dynamic memory.

This repository is built as a learning path: each file introduces one concept, keeps the code small, and emphasizes practical understanding over theory overload.

## Why This Repo

Pointers are one of the most powerful parts of C, and one of the easiest places to get confused. This project helps you build intuition with progressive examples, including:

- Address and dereference basics
- Pointer arithmetic
- Pointers with arrays and function arguments
- Pointer-to-pointer patterns
- Heap allocation with malloc, calloc, realloc, and free

## Learning Path

Start from top to bottom for the best progression:

- [01_intro.c](01_intro.c)
- [02_pointerArithmetic.c](02_pointerArithmetic.c)
- [03_pointerTypes.c](03_pointerTypes.c)
- [04_pointerToPointer.c](04_pointerToPointer.c)
- [05_pointerArguments.c](05_pointerArguments.c)
- [06_pointersAndArrays.c](06_pointersAndArrays.c)
- [07_arraysArguments.c](07_arraysArguments.c)
- [08_charArrayPointer.c](08_charArrayPointer.c)
- [09_multidimArrays.c](09_multidimArrays.c)
- [10_dynamicMemory.c](10_dynamicMemory.c)
- [11_pointerFuncReturns.c](11_pointerFuncReturns.c)
- [12_functionPointers.c](12_functionPointers.c)
- [13_functionPointerCallbacks.c](13_functionPointerCallbacks.c)
- [14_memoryLeak.c](14_memoryLeak.c)

## Quick Start

Use this section to compile and run any lesson file in minutes.

Prerequisites:

- A C compiler in PATH (for example gcc)
- Terminal opened in this folder, or the ability to cd into it

1. Choose a lesson file and compile it:

```bash
gcc 10_dynamicMemory.c -o dynamicMemory
```

2. Run the program:

```bash
./dynamicMemory
```

If your terminal requires .exe explicitly (common on Windows CMD/PowerShell):

```bash
gcc 10_dynamicMemory.c -o dynamicMemory.exe
dynamicMemory.exe
```


## What You Will Practice

- Reading and writing through pointers safely
- Understanding stack vs heap memory usage
- Resizing dynamic allocations with realloc
- Passing arrays and pointers into functions
- Avoiding memory leaks by pairing allocation with free

## Project Style

- Small, single-purpose examples
- Commented code for learning context
- Filename order reflects difficulty progression

## Note
This repo is for experimentation, so edit examples and rerun often.

