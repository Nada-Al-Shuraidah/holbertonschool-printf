#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

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

/**
* handle_percent - Prints the percentage symbol '%'
*
* Return: Number of characters printed (always 1)
*/
int handle_percent(void)
{
return (write(1, "%", 1));
}

/**
* process_format - Handles the format specifiers
* @format: The format specifier to process
* @args: The list of arguments to handle
*
* Return: Number of characters printed
*/
int process_format(const char *format, va_list args)
{
int count = 0;

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
count += write(1, "%", 1); /* Print % as a normal character */
count += write(1, format, 1);
break;
}
return (count);
}

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
if (*format == '%') /* Processing format specifier */
{
format++;
if (*format == '\0') /* If % is at the end of the string */
return (-1); /* Return error */
count += process_format(format, args); /* Call helper function */
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
