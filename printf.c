#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a specific format
 * @format: A string containing the format specifiers and text
 *
 * Description:
 * This function is used to print formatted text to the standard output
 * (stdout). It takes a format string as input and processes directives
 * within the format string to produce the desired output. The following
 * conversion specifiers are supported:
 * - %c: Prints a single character.
 * - %s: Prints a string.
 * - %%: Prints a percent symbol.
 *
 * Return:
 * The function returns the total number of characters printed to the output.
 */


int _printf(const char *format, ...)
{
va_list args;
int count = 0; /* Number of printed characters */
char *str;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c': /* Letter printing */
count += write(1, &(char){va_arg(args, int)}, 1);
break;
case 's': /* Ptint a text string */
str = va_arg(args, char *);
count += write(1, str, strlen(str));
break;
case '%': /* Print */
count += write(1, "%", 1);
break;
default:
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
