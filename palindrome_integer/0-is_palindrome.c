#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - test if the number is a palindrome
 *
 * @n: number to test
 *
 * Return: true or false
 */
int is_palindrome(unsigned long n);
{
	unsigned long temp = n;
	unsigned long reversed = 0;

	while (temp > 0)
	{
		reversed = reversed * 10 + (temp % 10);
		temp /= 10;
	}
	if (n == reversed)
		return (1);
	return (0);
}
