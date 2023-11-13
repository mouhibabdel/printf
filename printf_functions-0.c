#include "main.h"

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
va_start(args, format);
while (*format != '\0')
{
if (*format == '%' && *(format + 1) != '\0')
{
format++;
if (*format == 'c')
{
count += putchar(va_arg(args, int));
}
else if (*format == 's')
{
count += fputs(va_arg(args, char *), stdout);
}
else if (*format == '%')
{
count += putchar('%');
}
else
{
count += putchar('%') + putchar(*format);
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(args);
return (count);
}
