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
handle_s_t handlers[] =
{
{'c', h_char},
{'s', h_string},
{'%', h_percentage},
};
int found = 0;
for (size_t i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++)
{
if (*format == handlers[i].sp_f)
{
count += handlers[i].f(args);
found = 1;
break;
}
}
if (!found)
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
