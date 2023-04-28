#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 *
 * @types: List a of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculate flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[j--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in octal
 *
 * @types: List of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculate flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[j--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = '0';
	}
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 *
 * @types: List of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculate flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal
 *
 * @types: List of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculate flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 *
 * @types: List of arg
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculate flags
 * @flag_ch: Calculate flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[j--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}
	j++;
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
