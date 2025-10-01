# C++ Module 06 – Type Casting, Serialization, and Runtime Type Identification

## Overview

This repository contains the solutions for **Module 06** of the 42 School C++ curriculum. The exercises in this module focus on deepening the understanding of type conversions, serialization techniques, and runtime type identification in C++. All code follows the educational guidelines and coding conventions specified for the course.

## Learning Outcomes

- **Master explicit type casting in C++** and understand its necessity in various scenarios.
- **Gain practical serialization skills**, a foundation for networking, file I/O, and low-level programming.
- **Understand and implement runtime type identification** using C++ polymorphism.
- **Practice memory safety and good coding habits** by following strict rules and conventions.
- **Collaborate and learn through peer evaluation**, improving both technical and interpersonal skills.

## Educational Purpose

The main objectives of this module are:

- **Introduce advanced type conversion mechanisms in C++** through explicit type casting.
- **Explore serialization and deserialization** as foundational concepts for data storage and transmission.
- **Practice identifying object types at runtime** without relying on RTTI (`typeinfo`), leveraging polymorphism and safe casting.
- **Develop clean, readable, and maintainable code** using object-oriented principles.
- **Gain practical experience** with C++ memory management and avoid common pitfalls such as memory leaks.

This module is designed to build strong foundational skills required for C++ development, emphasizing genuine learning by reasoning, experimenting, and peer collaboration.

## Module Content and Implementation

### Exercise 00: Conversion of Scalar Types

**Directory:** `ex00/`  
**Main Class:** `ScalarConverter`

- The `ScalarConverter` class is implemented as a static utility (non-instantiable), containing:
  ```cpp
  static void convert(const std::string& literal);
  ```
- **Implementation Details:**
    - The `convert` method analyzes the input string and determines if it represents a char, int, float, or double literal.
    - It explicitly casts the detected value into all four scalar types.
    - Handles pseudo-literals (`nan`, `inf`, `nanf`, `inff`, etc.), non-displayable chars, and impossible conversions.
    - Uses standard library functions and explicit casting (such as `static_cast` and reinterpretation) to perform conversions.
    - Displays output for each scalar type as specified.
- **Test Program:**  
  The `main.cpp` takes a command-line argument and prints the results for each scalar type.

### Exercise 01: Serialization

**Directory:** `ex01/`  
**Main Classes:** `Serializer`, `Data`

- The `Data` structure contains actual data members (e.g., `int`, `float`).
- The `Serializer` class provides two static methods:
  ```cpp
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
  ```
    - `serialize` converts a `Data*` pointer to a `uintptr_t` integer (using reinterpretation).
    - `deserialize` converts a `uintptr_t` back to a `Data*` pointer.
- **Implementation Details:**
    - Both methods are static and cannot be called from an instance.
    - The conversion uses `reinterpret_cast`.
    - The main program creates a `Data` instance, serializes its pointer, deserializes it, and validates the result by comparing pointers and optionally printing the member values.

### Exercise 02: Identify Real Type

**Directory:** `ex02/`  
**Main Classes:** `Base`, `A`, `B`, `C`

- `Base` is a polymorphic class with a public virtual destructor.
- `A`, `B`, and `C` are empty classes that inherit from `Base`.
- **Implementation Details:**
  - `Base* generate(void);`
    - Randomly instantiates an object of type `A`, `B`, or `C` and returns as a `Base*`.
  - `void identify(Base* p);`
    - Identifies the actual derived type of the object pointed to by `p`, using dynamic casting and prints "A", "B", or "C".
  - `void identify(Base& p);`
    - Identifies the actual derived type of the object referenced by `p` using reference dynamic_cast (no pointer usage), prints "A", "B", or "C".
- The main program calls `generate`, then passes the result to both `identify` functions to demonstrate runtime type identification.

## How to Build and Run

Each exercise folder contains a `Makefile` for easy compilation.  
To build and run an exercise, for example `ex00`:

```bash
cd ex00
make
./convert <literal>
```

Repeat for `ex01` and `ex02` with their respective executables.