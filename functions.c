#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(types, int);

	return (handle_write_char(b, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - prints a string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percentage sign
 * @types: list of arguments
 * @buffer: Buffer array to handle the print
 * @flags:  Calculates active flags
 * @width: Gets the width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: number of characters printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Prints int
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculates the active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: size specifier
 * Return: number of characters printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - prints an unsigned number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: gets the width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, p, j, sum;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	b[0] = m / p;
	for (j = 1; j < 32; j++)
	{
		p /= 2;
		b[j] = (m / p) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; i++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char x = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
