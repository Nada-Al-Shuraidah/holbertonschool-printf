#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/* Helper function to handle characters */
/**
 * handle_char - Prints a single character
 * @args: A list of arguments pointing to the character to print
 *
 * Return: Number of characters printed (always 1)
 */
int handle_char(va_list args)
{
char c = va_arg(args, int);
return (write(1, &c, 1));
}

/* Helper function to handle strings */
/**
 * handle_string - Prints a string
 * @args: A list of arguments pointing to the string to print
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
return (write(1, str, strlen(str)));
}

/* Helper function to handle %% */
/**
 * handle_percent - Prints the percentage symbol '%'
 *
 * Return: Number of characters printed (always 1)
 */
int handle_percent(void)
{
return (write(1, "%", 1));
}

/* Main function _printf */
/**
 * _printf - Produces output according to a specific format
 * @format: A string containing the format specifiers and text
 *
 * Description:
 * This function is used to produce output to the standard output (stdout).
 * It processes the format string and handles conversion specifiers like:
 * - %c: Prints a single character
 * - %s: Prints a string
 * - %%: Prints the percentage symbol
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += handle_char(args);
break;
case 's':
count += handle_string(args);
break;
case '%':
count += handle_percent();
break;
default:
count += write(1, "%", 1);
count += write(1, format, 1);
break;
}
}
else
{
count += write(1, format, 1);
}
format++;
}

va_end(args);
return (count);
}
