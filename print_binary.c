#include "main.h"

/**
 * print_binary - prints binary number.
 * @val: parameter.
 * Return: integer
 */
int print_binary(va_list val)
{
int sign = 0;
int count = 0;
int i, a = 1, b;
unsigned int num = va_arg(val, unsigned int);
unsigned int v;

for (i = 0; i < 32; i++)
{
v = ((a << (31 - i)) & num);
if (v >> (31 - i))
sign = 1;
if (sign)
{
b = v >> (31 - i);
_putchar(b + 48);
count++;
}
}
if (count == 0)
{
count++;
_putchar('0');
}
return (count);
}
