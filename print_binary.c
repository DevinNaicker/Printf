#include "main.h"

/**
 * print_binary - prints binary number.
 * @val: parameter.
 * Return: integer
 */
int print_binary(va_list val)
{
int count = 0;
unsigned int num = va_arg(val, unsigned int);

if (num == 0)
{
_putchar('0');
return (1);
}

for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
{
if (num & (1 << i))
{
_putchar('1');
count++;
}
else
{
_putchar('0');
}
}

return (count);
}
