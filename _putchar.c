#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes char to standard output
 * @c: char
 * Return: succes - 1, error - (-1)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
