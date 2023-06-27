#include "main.h"

/**
 * get_width - calculates the width for printing
 * @format: formatted string in which to print the arguments.
 * @j: list of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *j, va_list list)
{
	int curr_j;
	int width = 0;

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (width);
}
