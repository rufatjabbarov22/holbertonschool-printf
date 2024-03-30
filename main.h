#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct operations
{
	char *spec;
	int (*f)(va_list);
} ops;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_decimal(va_list args);
int print_integer(va_list args);
int (*get_function(char ch))(va_list);


#endif
