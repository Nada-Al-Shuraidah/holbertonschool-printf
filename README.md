Readme

.TH PRINTF 3 "March 2025" "Holberton School" "C Library Functions"
.SH NAME
_printf - produces output according to a format.

.SH SYNOPSIS
#include "main.h"

int _printf(const char *format, ...);

.SH DESCRIPTION
The _printf function generates output according to the format string provided in the format parameter. This function allows formatted output with various format specifiers:
.TP
- %c: Prints a single character.
- %s: Prints a string of characters.
- %%: Prints the percentage symbol.
- %d, %i: Prints a signed integer.
- %u: Prints an unsigned integer.
- %o: Prints a number in octal format.
- %x, %X: Prints a number in hexadecimal format (lowercase or uppercase).

.SH RETURN VALUE
The _printf function returns the total number of characters written to the standard output.

.SH EXAMPLES
.B Example 1: Printing characters and strings
.nf
_printf("Character: %c, String: %s\\n", 'A', "Hello World!");
.fi

.B Example 2: Printing integers in different formats
.nf
_printf("Signed integer: %d\\n", -123);
_printf("Unsigned integer: %u\\n", 123);
_printf("Octal: %o\\n", 255);
_printf("Hexadecimal: %x\\n", 255);
.fi

.SH AUTHORS
Developed by Holberton School students as part of the printf project.

.SH SEE ALSO
man 3 printf: Documentation for the standard library function printf
