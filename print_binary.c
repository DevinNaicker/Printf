#include "main.h"

/**
 * print_binary - prints binary number.
 * @val: parameter.
 * Return: integer
 */

int print_binary(va_list val)
{
 unsigned int num;
 unsigned int i;
 int count = 0;
 int leading_zero = 1;

 num = va_arg(val, unsigned int);

if (num == 0)
{
_putchar('0');
return (1);
}

for (i = sizeof(num) * 8 - 1; i < sizeof(num) * 8; i--)
    {
        if (num & (1 << i))
        {
            _putchar('1');
            count++;
            leading_zero = 0;
        }
        else
        {
            if (!leading_zero)
            {
                _putchar('0');
                count++;
            }
        }
    }

    return (count);
}
