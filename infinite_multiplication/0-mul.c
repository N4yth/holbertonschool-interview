#include "holberton.h"
#include <stdlib.h>

/**
 * heapify_down - print error
 *
 * Return: Nothing
*/
void print_error(void)
{
	char *s = "Error";
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - returns length of a string
 * @s: string
 *
 * Return: length
*/
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 *
 * Return: 1 if true, 0 otherwise
*/
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, j, n1, n2, carry, *result;
	int started = 0;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		print_error();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';

			carry = result[i + j + 1] + (n1 * n2) + carry;
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}

		result[i] += carry;
	}

	for (i = 0; i < len; i++)
	{
		if (result[i] != 0)
			started = 1;

		if (started)
			_putchar(result[i] + '0');
	}

	if (!started)
		_putchar('0');

	_putchar('\n');

	free(result);
	return (0);
}
