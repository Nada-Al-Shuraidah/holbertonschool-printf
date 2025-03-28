#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
