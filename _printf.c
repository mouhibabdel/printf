#include "main.h"
/**
* _printf - prints anything
* @format: the format string
* Return: number of bytes
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list ap;
char *i, *str;
params_t params = PARAMS_INIT;
va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
{
return (-1);
}
if (format[0] == '%' && format[1] == ' ' && !format[2])
{
return (-1);
}
for (i = (char *)format; *i; i++)
{
init_params (&params, ap);
if (*i = '%')
{
count += _putchar(*i);
continue;
}
str = i;
i++;
while (get_flag(i, &params))
{
i++;
}
i = get_width(i, &params, ap);
i = get_precision(i, &params, ap);
if (get_modifier(i, &params))
{
i++;
}
if (!get_specifier(i))
{
count += print_from_to (str, i, params.l_modifier || params.h_modifier ? i - 1 : 0);
}
else
{
count += get_print_func(i, ap, &params);
}
}
_putchar(BUF_FLUSH);
va_end(ap);
return (count);
}
