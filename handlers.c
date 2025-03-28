#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
* handle_integer - Prints a signed integer
* @args: A list of arguments pointing to the integer to print
*
* Return: Number of characters printed
*/
int handle_integer(va_list args)
{
int num = va_arg(args, int);
char buffer[20];
int len = snprintf(buffer, sizeof(buffer), "%d", num);
return (write(1, buffer, len));
}

/**
* handle_unsigned - Prints an unsigned integer
* @args: A list of arguments pointing to the unsigned integer to print
*
* Return: Number of characters printed
*/
int handle_unsigned(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[20];
int len = snprintf(buffer, sizeof(buffer), "%u", num);
return (write(1, buffer, len));
}

/**
* handle_hex - Prints a number in hexadecimal format
* @args: A list of arguments pointing to the number to print
* @format: The format specifier ('x' or 'X')
*
* Return: Number of characters printed
*/
int handle_hex(va_list args, char format)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[20];
int len;

if (format == 'x')
len = snprintf(buffer, sizeof(buffer), "%x", num);
else
len = snprintf(buffer, sizeof(buffer), "%X", num);

return (write(1, buffer, len));
}

/**
* handle_octal - Prints a number in octal format
* @args: A list of arguments pointing to the number to print
*
* Return: Number of characters printed
*/
int handle_octal(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[20];
int len = snprintf(buffer, sizeof(buffer), "%o", num);
return (write(1, buffer, len));
}
