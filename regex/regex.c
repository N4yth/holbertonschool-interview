#include "regex.h"

/**
 * regex_match - Check whether a string matche a given pattern
 *
 * @str: The string to scan
 * @pattern: The pattern to check
 *
 * Return: 1 if the pattern matche the str otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');
	first_match = (*str != '\0') &&
		(*pattern == *str || *pattern == '.');
	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		return (first_match && regex_match(str + 1, pattern));
	}

	return (first_match && regex_match(str + 1, pattern + 1));
}
