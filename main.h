#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Prototypes for main printf functions */
int _printf(const char *format, ...);

/* Prototypes for character-related handler functions */
int handle_char(va_list args);
int handle_string(va_list args);

/* Prototypes for number-related handler functions */
int handle_integer(va_list args);
int handle_unsigned(va_list args);

/* Prototypes for format-related handler functions */
int handle_hex(va_list args, char format);
int handle_octal(va_list args);

/* Prototypes for utility functions */
int process_format(const char *format, va_list args);

#endif /* MAIN_H */
