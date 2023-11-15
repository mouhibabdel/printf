#include "main.h"

/**
* _isdigit - checks if character is digit
* @c: the character to check
* Return: 1 if digit, 0 otherwise
*/
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}
/**
* strlen - returns the length of a string
* @s: the string whose length to check
* Return: integer length of string
*/
int strlen (char *s)
{
int o = 0;
while (*s++)
o++;
return (o);
}
/**
* print_number prints a number with options
*@str: the base number as a string
* @params: the parameter struct *
* Return: chars printed
*/
int print_number(char *str, params_t *params)
{
unsigned int v = _strlen(str);
int neg = (!params->unsign && *str == '-');
if (!params->precision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
v--;
}
if (params->precision != UINT_MAX)
while (v++ < params->precision)
*--str = '0';
if (neg)
*--str = '-';
if (!params->minus_flag)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}
/** print number right shift - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
* Return: chars printed
*/
int print_number_right_shift(char *str, params_t *params)
{
unsigned int b = 0, neg, neg2, u = _strlen(str);
char pad_char = ' ';
if (params->zero_flag && !params->minus_flag)
pad_char = 0;
neg = neg2 = (!params->unsign && *str == '-');
if (neg && u < params->width && pad_char == '0' && !params->minus_flag)
str++;
else
neg=0;
if ((params->plus flag && !neg2) || (!params->plus_flag && params->space_flag && !neg2))
u++;
if (neg && pad_char == '0')
b += _putchar('-');
if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
b += _putchar ('+');
else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign && params->zero_flag)
b+_putchar(' ');
while (u++ < params->width)
b += _putchar(pad_char);
if (neg && pad_char == ' ')
b += _putchar ('-');
if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
b += putchar ('+');
else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign && !params->zero_flag)
b += _putchar(' ');
b += puts (str);
return (b);
}
/**
* print_number_left_shift prints a number with options
* @str: the base number as a string
* @params: the parameter struct
* Return: chars printed
*/
int print_number_left_shift(char *str, params_t *params)
{
unsigned int v = 0, neg, neg2, i = _strlen(str);
char pad_char = ' ';
if (params->zero_flag && !params->minus_flag)
pad_char = '0';
neg = neg2 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
str++;
else
neg = 0;
if (params->plus_flag && !neg2 && !params->unsign)
v += _putchar('+'), i++;
else if (params->space_flag && !neg2 && !params->unsign)
v +=_putchar(' '), i++;
v += puts (str);
while (i++ < params->width)
v += _putchar(pad_char);
return (v);
}
