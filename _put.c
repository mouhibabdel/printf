#include <mian.h>
/**
* _puts - prints a string with newline
* @str: the string to print
* return: void
*/
int _puts(char *str)
{
char *o = str;
while (*str)
{
_putchar(*str++);
}
return (str - o)
}
/**
* _putchar - writes the character c to stdout
* @c: the character to print
* return: on success 1
*error, -1 returned, errno set appropiatel
*/
int _putchar(int c)
{
static int v;
static char buf[OUTPUT_BUF_SIZE];
if (c == BUF_FLUSH || v >= OUTPUT_BUF_SIZE)
{
write(1, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
{
buf[v++] = c;
}
return (1);
}
