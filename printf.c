#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

void print_char(char c, int *count)
{
	_putchar(c);
	(*count)++;
}

void print_str(char *str, int *count)
{
	if (str)
	{
		while (*str)
		{
			_putchar(*str++);
			(*count)++;
		}
	}

	else
	{
		char *null_str = "(null)";
		
		while (*null_str)
		{
			_putchar(*null_str++);
			(*count)++;
		}
	}
}

int handle_format(const char *format, va_list args, int *count, unsigned int *i)
{
	(*i)++;

	if (format[*i] == '\0')
	{
		return -1;
	}

	switch (format[*i])
	{
		case 'c':
			print_char(va_arg(args, int), count);
			break;
		
		case 's':
			print_str(va_arg(args, char *), count);
			break;

		case '%':
			print_char('%', count);
			break;
		default:
			print_char('%', count);
			print_char(format[*i], count);
			(*count)++;
			break;
	}

	return 0;
}

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
			if (handle_format(format, args, &count, &i) == -1)
			{
				va_end(args);
				return (-1);
			}
		}

		else
		{
			print_char(format[i], &count);
		}
		i++;
	}

	va_end(args);
	return (count);
}
