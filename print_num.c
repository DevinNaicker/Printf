#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_num - prints a number for the printf function.
 * @n: the number to print
 *
 * Return nothing
 */

void print_number(int n) 
{
    char buffer[12];
    int i = 0;
    int is_negative = 0;

    if (n == 0)
    {
        putchar('0');
        return;
    }

    if (n < 0)
    {
        is_negative = 1;
        n = -n;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (is_negative)
    {
        putchar('-');
    }

    while (i > 0)
    {
        putchar(buffer[--i]);
    }
}
