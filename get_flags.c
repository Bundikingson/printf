

#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @format: formatted string in which to print the arguments
 * @j: takes a parameter.
 * Return: flags:
 */
int get_flags(const char *format, int *j)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *j + 1; format[curr_i] != '\0'; curr_j++)
	{
		for (k = 0; FLAGS_CH[j] != '\0'; k++)
			if (format[curr_j] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*j = curr_k - 1;

	return (flags);
}
