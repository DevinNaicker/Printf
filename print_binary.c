#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned int.
 * @val: the argument list containing the unsigned int to print.
 *
 * Return: the number of characters printed.
 */
int print_binary(va_list val)
{
unsigned int num = va_arg(val, unsigned int);
int bit;
int count = 0;
int leading_zero = 1;

for (int i = 31; i >= 0; i--)
{
bit = (num >> i) & 1;
if (bit)
leading_zero = 0;
if (!leading_zero)
{
_putchar(bit + '0');
count++;
}
}
if (count == 0)
{
_putchar('0');
count++;
}
return (count);
}
