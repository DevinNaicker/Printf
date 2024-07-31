#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
unsigned int i = 0;
int count = 0;
va_list args;

if (!format)
return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;

				case 's':
					{
						char *str = va_arg(args, char *);

						if (str)
						{
							while (*str)
							{
								_putchar(*str++);
								count++;
							}
						}

						else
						{
							char *null_str = "(null)";

							while (*null_str)
							{
								_putchar(*null_str++);
								count++;
							}
						}
						break;
					}

				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);

						count += print_number(num);
						break;
					}

				case '%':
					_putchar('%');
					count++;
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
		i++;
	}

	va_end(args);
	return (count);
}
