#include <stdlib.h>
#include <string.h>

#include "substring.h"

typedef struct word_count
{
	char const	*word;
	int		count;
}	word_count_t;


/**
 * find_word_index - find the index of a word of length wlen inside a
 * word_count table, comparing wlen bytes at a time.
 *
 * @table: the table to look
 * @table_size: the size of the table
 *
 * Return: the index of the word
 */
static int find_word_index(word_count_t *table, int table_size,
	char const *word, int wlen)
{
	int i;

	for (i = 0; i < table_size; i++)
		if (memcmp(table[i].word, word, wlen) == 0)
			return (i);
	return (-1);
}


/**
 * build_needed_table - collapse `words` into a table of unique words
 * and how many times each one must appear.
 *
 * @words: the word to collapse
 * @nb_words: the number of word
 *
 * Return: the table or null 
 */
static word_count_t *build_needed_table(char const **words, int nb_words,
	int wlen, int *table_size)
{
	word_count_t *table;
	int size;
	int idx;
	int i;

	table = malloc(sizeof(*table) * nb_words);
	if (!table)
		return (NULL);
	size = 0;
	for (i = 0; i < nb_words; i++)
	{
		idx = find_word_index(table, size, words[i], wlen);
		if (idx >= 0)
			table[idx].count++;
		else
		{
			table[size].word = words[i];
			table[size].count = 1;
			size++;
		}
	}
	*table_size = size;
	return (table);
}


 /**
 * check_position - check whether s + pos is a valid concatenation of
 * all words in needed.
 *
 * @s: The string to scan
 * @pos: The pattern to check
 * @needed: the word to check
 *
 * Return: 1 if it s valid otherwise 0
 */
static int check_position(char const *s, int pos, word_count_t *needed,
	int needed_size, int wlen, int nb_words)
{
	int *seen;
	int i;
	int idx;
	int matched;

	seen = calloc(needed_size, sizeof(*seen));
	if (!seen)
		return (0);
	matched = 1;
	for (i = 0; i < nb_words; i++)
	{
		idx = find_word_index(needed, needed_size, s + pos + i * wlen, wlen);
		if (idx < 0 || ++seen[idx] > needed[idx].count)
		{
			matched = 0;
			break;
		}
	}
	free(seen);
	return (matched);
}


/**
 * push_index - append an index to the dynamically growing result array.
 * concatenation of every word in `words` occurs.
 *
 * @result: the result array to append
 * @count: the count
 * @capacity: the capacity of the array
 * @value: the value to add
 *
 * Returns 0 on success, -1 on allocation failure.
 */
static int push_index(int **result, int *count, int *capacity, int value)
{
	int *tmp;

	if (*count == *capacity)
	{
		*capacity = *capacity ? *capacity * 2 : 4;
		tmp = realloc(*result, sizeof(**result) * (*capacity));
		if (!tmp)
			return (-1);
		*result = tmp;
	}
	(*result)[(*count)++] = value;
	return (0);
}

/**
 * find_substring - find every starting index in `s` at which a
 * concatenation of every word in `words` occurs.
 *
 * @s: The string to scan
 * @words: the word to check
 * @nb_words: the number of time allowed
 * @n: 
 *
 * Return: every starting index
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int capacity;
	int count;
	word_count_t *needed;
	int needed_size;
	int wlen;
	int slen;
	int total_len;
	int i;

	if (!n)
		return (NULL);
	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);
	wlen = (int)strlen(words[0]);
	if (wlen == 0)
		return (NULL);
	total_len = wlen * nb_words;
	slen = (int)strlen(s);
	if (slen < total_len)
		return (NULL);
	needed = build_needed_table(words, nb_words, wlen, &needed_size);
	if (!needed)
		return (NULL);
	result = NULL;
	capacity = 0;
	count = 0;
	for (i = 0; i <= slen - total_len; i++)
	{
		if (check_position(s, i, needed, needed_size, wlen, nb_words))
		{
			if (push_index(&result, &count, &capacity, i) == -1)
			{
				free(result);
				free(needed);
				*n = 0;
				return (NULL);
			}
		}
	}
	free(needed);
	*n = count;
	return (result);
}
