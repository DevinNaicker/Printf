#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_num - prints a number for the printf function.
 * @n: the number to print
 *
 * Return nothing
 */

int print_number(int n) {
    char buffer[12];
    int i = 0, j, count = 0;
    int is_negative = 0;

    if (n == -2147483648)
    {
        _putchar('-');
        _putchar('2');
        n = 147483648;
        count = 2;
    }

    if (n == 0)
    {
        _putchar('0');
        return 1;
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

    if (is_negative && count == 0)
    {
        _putchar('-');
        count++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        _putchar(buffer[j]);
        count++;
    }

    return count;
}
