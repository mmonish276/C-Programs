# C-Programs
#### This repository contains various programs I've written in C. Any suggestions are welcome. Please enjoy!
#
# Instructions for Usage
## Prerequisites

Ensure you have the following installed:
- [Visual Studio Code (VS Code)](https://code.visualstudio.com/)
- [GCC](https://gcc.gnu.org/) (or another C compiler like Clang)
- [C/C++ Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

## Instructions

### 1. Open Your Project

1. Launch VS Code.
2. Open your project folder by selecting `File` > `Open Folder...` and choosing the directory containing your C source files.

### 2. Install Required Extensions

1. Open the Extensions view by pressing `Ctrl+Shift+X`.
2. Search for and install the **C/C++** extension by Microsoft.
3. (Optional) Install the **Code Runner** extension if you prefer to run code snippets directly.

### 3. Compile and Run Your Program

1. Open the C file you want to compile in VS Code.

2. Open the Terminal in VS Code by pressing `Ctrl+`` (backtick) or by selecting `Terminal` > `New Terminal`.

3. **Compile the Program:**
   - In the terminal, use the `gcc` command to compile your C program. Replace `<ProgramName>` with the name of your file (without the `.c` extension), and `<ProgramName.c>` with the actual name of your C source file.
   
     ```sh
     gcc -o <ProgramName> <ProgramName.c>
     ```

   - For example, if your file is named `main.c`, you would run:
   
     ```sh
     gcc -o main main.c
     ```

   - This command compiles `main.c` into an executable named `main`.

4. **Run the Compiled Program:**
   - After compiling, you can run the program by typing `./` followed by the name of the executable. If you used `main` as the executable name, type:
   
     ```sh
     ./main
     ```

   - If your program expects command-line arguments, include them after the executable name. For example, if your program expects two arguments, you would run:
   
     ```sh
     ./main arg1 arg2
     ```
# Sources

For further reading and a comprehensive understanding of C programming, refer to the PDF below. Most programs in this repository were made with the help of lessons and exercises in this textbook.

- [The C Programming Language (Kernighan & Ritchie)](https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20(Kernighan%20Ritchie).pdf)
 
