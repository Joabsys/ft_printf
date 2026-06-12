# ft_printf

*This project has been created as part of the 42 curriculum by [jesequie].*

---

## Description

**ft_printf** is a project from the 42 curriculum that consists of reimplementing the standard C function `printf`. The goal is to understand how variadic functions work in C — that is, functions that accept a variable number of arguments — as well as to handle different format specifiers for outputting data to the standard output.

The result is a static library `libftprintf.a` that can be used in place of `printf` in future 42 projects.

### Functions implemented

**Main function:**

| Function | Description |
|---|---|
| `ft_printf` | Parses the format string and dispatches to the appropriate print function for each specifier |

**Print helper functions:**

| Function | Specifier | Description |
|---|---|---|
| `ft_print_char` | `%c` | Outputs a single character |
| `ft_print_per` | `%%` | Outputs a literal percent sign |
| `ft_print_str` | `%s` | Outputs a string |
| `ft_print_decimal` | `%d` / `%i` | Outputs a signed decimal integer |
| `ft_print_unsigned` | `%u` | Outputs an unsigned decimal integer |
| `ft_print_hex` | `%x` / `%X` | Outputs an unsigned integer in hexadecimal (lower or uppercase) |
| `ft_print_ptr` | `%p` | Outputs a pointer address in hexadecimal |

### Supported format specifiers

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String of characters |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal integer (lowercase) |
| `%X` | Unsigned hexadecimal integer (uppercase) |
| `%p` | Pointer address |
| `%%` | Literal percent sign |

---

## Instructions

### Requirements

- `gcc` compiler
- `make`
- Unix-based OS (Linux or macOS)

### Compilation

Clone the repository and run `make` in the project root:

```bash
git clone https://github.com/Joabsys/ft_printf.git
cd ft_printf
make
```

This will generate the `libftprintf.a` static library file.

### Available Makefile rules

| Rule | Description |
|---|---|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` then `make` |

### Using ft_printf in your project

Copy `libftprintf.a` and `ft_printf.h` to your project, then compile with:

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

---

## Resources

### Documentation & References

- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c) — comprehensive reference for standard C functions including `printf`
- [man pages online — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) — official manual page for `printf`
- [stdarg.h reference — cppreference.com](https://en.cppreference.com/w/c/variadic) — reference for variadic function macros (`va_list`, `va_start`, `va_arg`, `va_end`)
- [42 Docs — Norminette](https://github.com/42School/norminette) — project subject and Norminette rules

### AI Usage

**Claude (Anthropic)** was used during the development of this project for the following purposes:

- **Conceptual clarification** — understanding how `va_list`, `va_start`, `va_arg`, and `va_end` work to handle variadic arguments
- **Debugging assistance** — identifying issues with argument advancement when passing `va_list` between functions, and handling edge cases such as `NULL` pointers in `%s` and `%p`
- **README writing** — structuring and writing this documentation file

> AI was used exclusively as a learning and support tool. All code was written and understood by the author.
