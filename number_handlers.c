#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
