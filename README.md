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

- `cc` compiler
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
cc your_file.c -L. -lftprintf -o your_program
```

---

## Algorithm & Data Structure

### Overview

`ft_printf` works by iterating over the format string character by character. When it encounters a regular character, it outputs it directly. When it finds a `%`, it reads the next character to identify the format specifier and dispatches the call to the corresponding helper function.

```
for each character in format:
    if character != '%' → write it directly
    if character == '%' → read next char → dispatch to helper function
```

### Variadic Arguments — how `va_list` works

In C, functions normally have a fixed number of parameters. `ft_printf`, however, accepts any number of arguments. This is made possible by **variadic functions**, using the macros defined in `<stdarg.h>`.

When you call:

```c
ft_printf("%d %s %u", 42, "hello", 7u);
```

The compiler pushes all arguments onto the **stack** in sequence before the function is called:

```
[ "%d %s %u" ] ← first argument (format)
[     42     ] ← second argument
[  "hello"   ] ← third argument
[     7u     ] ← fourth argument
```

The four macros from `<stdarg.h>` are used to walk through those positions manually:

| Macro | Role |
|---|---|
| `va_list ap` | Declares a cursor that tracks the current position in the argument list |
| `va_start(ap, format)` | Initializes the cursor, anchored right after the last named parameter |
| `va_arg(ap, type)` | Reads the current argument as `type` **and** advances the cursor to the next one |
| `va_end(ap)` | Cleans up the internal state of `ap` — mandatory, omitting it is undefined behavior |

### Step-by-step execution flow

```
ft_printf("%d %s %u", 42, "hello", 7u)
            │
            ▼
        va_start(ap, format)
            │
            │   ap → [42] ["hello"] [7u]
            ▼
        reads '%d' → calls ft_print_decimal(&ap)
                        va_arg(*ap, long long) → returns 42, ap advances
            │
            │   ap → ["hello"] [7u]
            ▼
        reads '%s' → calls ft_print_str(&ap)
                        va_arg(*ap, char *) → returns "hello", ap advances
            │
            │   ap → [7u]
            ▼
        reads '%u' → calls ft_print_unsigned(&ap)
                        va_arg(*ap, unsigned int) → returns 7, ap advances
            │
            │   ap → [empty]
            ▼
        va_end(ap)
```

### Why `va_list` is passed by pointer to helper functions

`va_list` behaves like an array in many implementations — passing it by value gives the helper function a **copy** of the cursor. The copy advances inside the helper, but the original in `ft_printf` stays in place, causing the next specifier to read the wrong argument.

Passing by pointer ensures that every `va_arg` call inside any helper function advances the **original** cursor:

```c
// wrong — receives a copy, ft_printf cursor does not advance
int ft_print_decimal(va_list ap);

// correct — receives the address, ft_printf cursor advances together
int ft_print_decimal(va_list *ap);

// call site inside ft_printf
ft_print_decimal(&ap);
```

### Return value

Each helper function returns the number of characters it wrote to stdout. `ft_printf` accumulates that count across all characters and specifiers and returns the **total number of characters written**, matching the behavior of the standard `printf`.

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
