# 🚀 Programming Advices Journey

Welcome to my central C++ repository documenting my progress through the **Programming Advices** roadmap!  
This repository serves as a practical archive of my problem-solving practice, algorithm implementations, performance comparisons, and custom C++ libraries.

---

## 📌 About This Repository

The primary goal of this repository is to track my evolution as a Software Engineer and C++ Developer. It reflects my hands-on experience in:

*   **Problem-Solving & Logic Building:** Breaking down complex business logic and mathematical challenges into structured code.
*   **Performance & Optimization:** Writing initial implementations and comparing them against reference solutions to analyze code quality and efficiency.
*   **Modular Architecture:** Moving away from monolithic scripts toward modular, reusable headers and clean project structures.
*   **Data Handling:** Working with console applications, stream buffers, and text-file database systems.

---

## 🧭 Roadmap & Course Modules

The journey is structured around the official Programming Advices curriculum:

### 🔹 03 - Introduction to Programming with C++ – Level 1
Foundational concepts of C++ programming, control flow, functions, loops, arrays, and standard input/output operations through comprehensive daily exercises.

### 🔹 04 - Algorithms & Problem-Solving – Level 1
A collection of 50 foundational algorithmic challenges designed to build intuitive logical thinking and fundamental problem-solving skills.

### 🔹 05 - Algorithms & Problem-Solving – Level 2
Intermediate problem-solving covering advanced array manipulation, random number generation, matrix math, and code refactoring.  
*   *Key Feature:* Direct comparison between my solutions (`Me.cpp`) and the instructor's reference solutions (`Teacher.cpp`) to learn cleaner design patterns.

### 🔹 06 - Introduction to Programming Using C++ Level 2
Deep dive into core language capabilities, including:
*   Pointers, Reference Variables, and Memory Management.
*   Structures, Enumerations, and Advanced String Operations.
*   File Streams (`fstream`) for reading, writing, updating, and parsing persistent data files.

### 🔹 07 - Algorithms & Problem Solving Level 3
Advanced matrix operations, vector manipulations, string tokenization, and building a lightweight client database system using structured text files.

---

## 📦 Custom Libraries (`MyLibraries`)

To promote code reuse and avoid redundancy, I developed reusable header-only and split-source modular C++ libraries:

*   **`InputLib`:** Input validation utility functions (handling ranges, type constraints, and standard input errors).
*   **`MathLib`:** Mathematical utilities, prime number algorithms, matrix transformations, and number formatting.
*   **`MyStringLib`:** String transformations, splitting/joining tokens, casing utilities, and formatting tools.

> Standardized structure: Header files in `include/` and implementation files in `src/`.

---

## 🛠️ Key Technical Skills Demonstrated

- **Core C++:** Modern C++ practices, Memory Management, File I/O, STL Vectors, and Strings.
- **Algorithms:** Sorting, Searching, Array & Matrix Transformations, Tokenization.
- **Software Engineering:** Modular Code Design, Refactoring, Code Reviews, and Git Version Control.

---

## ⚙️ Compilation & Execution

Source code can be compiled using any C++11 (or newer) compatible compiler such as `g++`:

```bash
# Example: Compiling a specific solution with custom libraries
g++ -I./MyLibraries/include Courses/Course\ 7/Problem1Me.cpp MyLibraries/src/*.cpp -o Problem1
./Problem1