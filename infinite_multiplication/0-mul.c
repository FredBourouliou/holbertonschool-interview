#include "holberton.h"
#include <stdlib.h>

/**
 * print_error - Prints "Error" and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * is_digit - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * multiply - Multiplies two number strings
 * @num1: First number as string
 * @num2: Second number as string
 * @len1: Length of num1
 * @len2: Length of num2
 *
 * Return: Pointer to result array
 */
int *multiply(char *num1, char *num2, int len1, int len2)
{
	int *result;
	int i, j, mul, n1, n2;

	result = malloc(sizeof(int) * (len1 + len2));
	if (!result)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			mul = n1 * n2;
			mul += result[i + j + 1];
			result[i + j + 1] = mul % 10;
			result[i + j] += mul / 10;
		}
	}
	return (result);
}

/**
 * print_result - Prints the result array
 * @result: Array containing result digits
 * @len: Length of the array
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;

	if (i == len)
	{
		_putchar('0');
	}
	else
	{
		while (i < len)
		{
			_putchar(result[i] + '0');
			i++;
		}
	}
	_putchar('\n');
}

/**
 * main - Entry point, multiplies two numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int len1, len2;
	int *result;

	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	result = multiply(argv[1], argv[2], len1, len2);
	print_result(result, len1 + len2);

	free(result);
	return (0);
}
