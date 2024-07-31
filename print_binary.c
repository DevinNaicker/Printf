#include "main.h"
#include "_putchar.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - Prints an unsigned integer as binary
 * @n: The unsigned integer to print
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
int count = 0;

if (n == 0)
{
_putchar('0');
return (1);
}

while (n > 0)
{
_putchar((n & 1) + '0');
n >>= 1;
count++;
}

return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;

int i, count = 0;

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;

switch (format[i])
{
case 'b':
count += print_binary(va_arg(args, unsigned int));
break;
default:
_putchar('%');
_putchar(format[i]);
count += 2;
break;
}
}
else
{
_putchar(format[i]);
count++;
}
}

va_end(args);
return (count);
}
