#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Function that produces output according to a format
 *
 * @format: the parameter that represents character string
 *
 * Return: returns the count of character that have been printed
 *
 *
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;
	int i;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				count += write(1, "%", 1);
				i++;
			}

			else
			{
				int (*fc)(va_list) = get_function(format[i+1]);

				if (fc)
				{
					count += fc(list);
					i++;
				}

				else
					count += write(1, "%", 1);
			}
		}

		else
			count += write(1, &format[i], 1);
	}

	va_end(list);
	return (count);
}
