#include "main.h"
/** get_specifier - finds the format func
* @s: the format string
* Return: the number of bytes printed
*/
int(*get_specifier(char *s)) (va_list ap, params_t *params)
{
specifier_t specifiers[] = {
("c", print char),
("d", print_int),
("i", print_int),
{"s", print_string),
("", print percent),
{"b", print_binary),
("o", print_octal),
("u", print_unsigned),
("x", print_hex),
("x", print_HEX),
("p", print_address},
("s", print_s),
("r", print_rev),
("R", print_rot13},
(NULL, NULL)
};
int u = 0;
while (specifiers[u].specifier)
{
if (*s == specifiers[u].specifier[0])
{
return (specifiers[u].f);
}
u++;
}
return (NULL);
}
/**
* get_print_func - finds the format func
* @s: the format string
* @ap: argument pointer
* Return: numb of byts  
**/
int get_print_func(char *s, va_list ap, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);
if (f)
{
return (f(ap, params));
}
return(0);
}
/**
* get_flag - finds the flag func
* @s: the format string
* @params: the parameters struct
* Return: if flag was valid
*/
int get_flag(char *s, params_t *params)
{
int o = 0;
switch (*s)
{
case '+':
o = params->plus_flag = 1;
break;
case ' ':
o = params->space_flag = 1;
break;
case '#':
o = params->hashtag_flag = 1;
break;
case '-':
o = params->minus_flag = 1;
break;
case 0:
o = params->zero_flag = 1;
break;
}
return (o);
}
/**
* get_modifier - finds the modifier func
* @s: the format string
* @params: the parameters struct
* Return: if modifier  valid
*/
int get_modifier(char *s, params_t *params)
{
int v = 0;
switch (*s)
{
case 'h':
v = params->h_modifier = 1;
break;
case 'l':
v = params->l_modifier = 1;
break;
}
return (v);

}
/**
* get_width - gets the width from the format string
* @s: the format string
* @params: the parameters struct
* @ap: the argument pointer
* Return: new pointer
*/
char *get_width(char *s, params_t *params, va_list ap)
{
int b = 0;
if (s == '*')
{
b = va_arg(ap, int);
S++;
}
else
{
while (isdigit (*s))
{
b = b * 10 + (*s++ - '0');
}
}
params->width = b;
return (s);
}
