*This project has been created as part of the 42 curriculum by fedacax.*

# Libft

## Description

Libft is the first C project in the 42 curriculum: rewrite part of the standard C library (`libc`) from scratch and build a personal library, `libft.a`, to reuse in later projects.

Reimplementing functions like `strlen`, `memmove` or `atoi` forces you to understand what happens under the hood: how pointers and pointer arithmetic work, when and how to allocate and free memory, and how to handle `NULL`, overlapping buffers and other edge cases. The project also includes linked list functions, the first contact with data structures in the curriculum.

The code follows the 42 Norm and only uses the functions allowed by the subject (`malloc`, `free` and `write`).

## Library contents

### libc functions

| Group | Functions |
|---|---|
| Characters | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

These behave like the originals described in the `man` pages (`ft_strlcpy`, `ft_strlcat` and `ft_strnstr` follow the BSD versions).

### Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Joins two strings into a newly allocated one |
| `ft_strtrim` | Removes characters from a given set from both ends of a string |
| `ft_split` | Splits a string into an array of strings using a delimiter |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character and returns a new string |
| `ft_striteri` | Applies a function to each character, in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Linked lists

These functions use the `t_list` struct, defined in `libft.h`.

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node |
| `ft_lstadd_front` | Adds a node at the beginning |
| `ft_lstadd_back` | Adds a node at the end |
| `ft_lstsize` | Counts the nodes |
| `ft_lstlast` | Returns the last node |
| `ft_lstdelone` | Deletes a single node |
| `ft_lstclear` | Deletes the whole list |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Creates a new list by applying a function to each node |

## Instructions

### Compilation

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Then compile and link against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o program
./program
```

## Resources

### References

- `man` pages, the main source for understanding the expected behavior of each function
- [cppreference – C](https://en.cppreference.com/w/c)
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/c-programming-language/)
- [Stack Overflow](https://stackoverflow.com/), for specific questions and comparing approaches
- Discussions with other 42 students, mainly about edge cases and testing

### AI usage

AI was used as a study and debugging aid, not to write the functions. Specifically:

- clarifying concepts;
- interpreting compiler errors, segfaults and AddressSanitizer reports;
- reviewing code that had already been written, looking for edge cases that had been missed.