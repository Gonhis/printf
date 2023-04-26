#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list inputs;

	int printed_chars = 0;

	int i;

	va_start(inputs, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += handle_conversion(format, &i, inputs);
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}

	va_end(inputs);
	return (printed_chars);
}
