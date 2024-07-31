#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct format - to convert for printf
 * @str: declaring a char pointer variable
 * @func: conversion function for the specifier
 *
 */

typedef struct format
{
char *str;
int (*func)();
}
convert;

int _putchar(char c);
int _printf(const char *format, ...);
/*int print_binary(va_list val);*/
int print_binary(unsigned int n);

#endif /*MAIN_H*/
