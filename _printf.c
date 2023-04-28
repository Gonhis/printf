#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - function that produces output according to a format
 *
 * @format: pointer
 *
 * Return: Printed_chars.
 */
int _printf(const char *format, ...)
{
	int j, flags, width, precision, size;

	int printed = 0, printed_chars = 0, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - print the content of buffer
 *
 * @buffer: array
 * @buff_ind: pointer
 *
 * Return: empty
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
