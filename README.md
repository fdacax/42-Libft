*This project has been created as part of the 42 curriculum by &lt;your-login&gt;.*

# Libft

## Description

Libft is a project from the 42 School curriculum. Its goal is to create a personal C library by reimplementing several standard C library functions, as well as developing additional utility functions.

The main purpose of this project is to understand how commonly used C functions work internally, strengthen programming fundamentals, and gain a deeper understanding of memory management, pointers, strings, and data structures.

The library is written in C and can be reused in future 42 projects.

## Library Contents

The library is divided into several groups of functions:

### 1. Character Checks and Conversions

Functions used to check and convert individual characters.

- `ft_isalpha` – Checks whether a character is alphabetic.
- `ft_isdigit` – Checks whether a character is a digit.
- `ft_isalnum` – Checks whether a character is alphanumeric.
- `ft_isascii` – Checks whether a character belongs to the ASCII character set.
- `ft_isprint` – Checks whether a character is printable.
- `ft_toupper` – Converts a lowercase letter to uppercase.
- `ft_tolower` – Converts an uppercase letter to lowercase.

### 2. String Functions

Functions for handling and manipulating strings.

- `ft_strlen` – Calculates the length of a string.
- `ft_strlcpy` – Copies a string into a destination buffer with size protection.
- `ft_strlcat` – Appends a string to another string with size protection.
- `ft_strchr` – Finds the first occurrence of a character in a string.
- `ft_strrchr` – Finds the last occurrence of a character in a string.
- `ft_strncmp` – Compares two strings up to a specified number of characters.
- `ft_strnstr` – Searches for a substring within a limited number of characters.
- `ft_strdup` – Duplicates a string.
- `ft_substr` – Extracts a substring.
- `ft_strjoin` – Joins two strings into a newly allocated string.
- `ft_strtrim` – Removes specified characters from the beginning and end of a string.
- `ft_split` – Splits a string into an array of strings using a delimiter.
- `ft_strmapi` – Applies a function to each character of a string and returns a new string.
- `ft_striteri` – Applies a function to each character of a string.

### 3. Memory Functions

Functions for handling memory at byte level.

- `ft_memset` – Fills a memory area with a specified byte.
- `ft_bzero` – Sets a memory area to zero.
- `ft_memcpy` – Copies a specified number of bytes between memory areas.
- `ft_memmove` – Copies memory while handling overlapping memory regions.
- `ft_memchr` – Searches for a byte in a memory area.
- `ft_memcmp` – Compares two memory areas.
- `ft_calloc` – Allocates memory and initializes it to zero.

### 4. Conversion Functions

- `ft_atoi` – Converts a string into an integer.
- `ft_itoa` – Converts an integer into a string.

### 5. File Descriptor Functions

Functions that write characters, strings, and numbers to a file descriptor.

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### 6. Linked List Functions (Bonus)

Functions for creating and manipulating singly linked lists.

- `ft_lstnew` – Creates a new list node.
- `ft_lstadd_front` – Adds a node to the beginning of a list.
- `ft_lstsize` – Counts the number of nodes in a list.
- `ft_lstlast` – Returns the last node of a list.
- `ft_lstadd_back` – Adds a node to the end of a list.
- `ft_lstdelone` – Deletes a node.
- `ft_lstclear` – Deletes a list and its nodes.
- `ft_lstiter` – Applies a function to each node.
- `ft_lstmap` – Creates a new list by applying a function to each node.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This generates the static library:

```bash
libft.a
```

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

### Using the library

Include the header file in your C source code:

```c
#include "libft.h"
```

Compile your program together with the library:

```bash
cc main.c -L. -lft -I. -o program
```

Then execute it:

```bash
./program
```

## Resources

The following resources were useful throughout the development of this project:

### Documentation and References

- **C standard library documentation** – Used to understand the expected behaviour of standard C functions.
- **`man` pages** – Used to check function descriptions, parameters, return values, and edge cases.
- **[cppreference](https://en.cppreference.com/w/c)** – Reference for C language features and standard library functions.
- **[Stack Overflow](https://stackoverflow.com/)** – Used as a supplementary resource to research programming problems, understand errors, and compare different approaches to implementation.

### Peer Learning

Discussions with fellow 42 students were also useful during the project. Sharing questions, discussing possible solutions, and comparing approaches helped clarify concepts and improve problem-solving skills.

### AI Usage

AI was used as a learning and debugging assistant during the development of Libft.

It helped with:

- Understanding the expected behaviour of standard C library functions.
- Clarifying concepts involving pointers, pointer arithmetic, memory allocation, and memory management.
- Reviewing implementations and identifying logical errors.
- Understanding compiler warnings, segmentation faults, and AddressSanitizer reports.
- Discussing edge cases and improving the handling of memory and strings.
- Understanding linked lists and how to manipulate their nodes.

AI assistance was mainly used to explain concepts, review code, and guide debugging. The implementations were developed and tested by the student, who remains responsible for understanding the code and its behaviour.

## Final Notes

This project was an opportunity to strengthen my understanding of C programming, especially pointers, memory management, strings, and data structures.

It also helped me develop a more systematic approach to debugging, testing, and writing reliable code.
