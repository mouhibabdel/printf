#include "main.h"
/**
* print_from_to - prints a range of char addresses
* @start: starting address
* @stop: stopping address
* @except: except address
* Return: number bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
int count = 0;
while (start <= stop)
{
if (start != except)
count += _putchar (*start);
start++;
}
return (count);
}
/**
* print_rev - prints string in reverse
* @ap: string
* @params: the parameters struct
* Return: number bytes printed
*/
int print_rev(va_list ap, params_t *params)
{
int leng, summ = 0;

char *str = va_arg(ap, char *);
(void)params;
if (str)
{
for (leng = 0; *str; str++)
leng++;
str--;
for (leng > 0; leng--, str--)
summ += _putchar(*str);
}
return (summ);
}

/**
* print_rot13- prints string in rot13
* @ap: string
* @params: the parameters struct
* Return: number bytes printed
*/
int print_rot13(va_list ap, params_t *params)
{
int o, ind;
int coun = 0;
char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM noppqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;
o = 0;
ind = 0;
while (a[o])
{
if ((a[o] >= 'A' && a[o] <= 'Z') || (a[o] >= 'a' && a[o] <= 'z'))
{
ind = a[o] - 65;
coun += _putchar(arr[ind]);
}
else 
coun += _putchar(a[o]);
o++;
}
return (coun);
}
