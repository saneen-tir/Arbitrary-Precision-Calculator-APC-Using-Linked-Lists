# Arbitrary Precision Calculator (APC) Using Linked Lists

## Overview
The Arbitrary Precision Calculator (APC) is a command-line application written in C that performs arithmetic operations on very large integers that exceed the limits of standard data types. The calculator represents numbers digit by digit using linked lists, allowing accurate computation through dynamic memory allocation and low-level arithmetic logic.

This project focuses on system-level programming concepts such as pointer manipulation, memory management, and data structure–based computation.

---

## Features
- Supports addition, subtraction, multiplication, and division of large integers
- Handles numbers of arbitrary length beyond built-in data type limits
- Uses linked lists to store digits dynamically
- Correct carry and borrow propagation across multiple digits
- Handles operands of unequal length
- Accepts input through command-line arguments
- Modular and well-structured codebase
- Makefile-based build system

---

## Technologies Used
- C (Advanced)
- Linked Lists (ADT)
- Dynamic Memory Allocation
- Pointer Manipulation
- Command-Line Argument Parsing
- Makefile
- GCC Compiler

---

## How It Works
1. Each input number is broken down into individual digits.
2. Digits are stored in a linked list, allowing dynamic expansion.
3. Arithmetic operations are performed digit by digit, similar to manual calculation.
4. Carry and borrow values are propagated correctly across nodes.
5. Intermediate results are stored in temporary linked lists and cleaned up to prevent memory leaks.
6. The final result is printed to the console.

---

## Usage
./apc <number1> <operator> <number2>

## Example
./apc 12345678901234567890 + 98765432109876543210

