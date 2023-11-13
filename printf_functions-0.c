#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;
char *str;
va_start(args, format);
for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
switch (*ptr)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
count += printf("%s", str);
break;
case '%':
count += putchar('%');
break;
default:
count += putchar('%') + putchar(*ptr);
}
}
else
{
count += putchar(*ptr);
}
}
va_end(args);
return (count);
}
