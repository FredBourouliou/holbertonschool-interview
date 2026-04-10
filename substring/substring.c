#include <stdlib.h>
#include "substring.h"

/**
 * str_length - computes the length of a null-terminated string.
 * @s: string to measure
 *
 * Return: number of characters before the terminating null byte.
 */
static int str_length(char const *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * block_equal - tests whether the first @len bytes of @a and @b
 *               are identical.
 * @a: first buffer
 * @b: second buffer
 * @len: number of bytes to compare
 *
 * Return: 1 if the buffers are equal on @len bytes, 0 otherwise.
 */
static int block_equal(char const *a, char const *b, int len)
{
	int i;

	for (i = 0; i < len; i++)
		if (a[i] != b[i])
			return (0);
	return (1);
}

/**
 * match_concat - checks whether the window starting at @s is a
 *                concatenation of every word of @words exactly once.
 * @s: start of the window inside the scanned string
 * @words: array of words to place
 * @nb_words: number of words in @words
 * @word_len: length of every word (all words share the same length)
 * @used: scratch buffer of @nb_words bytes used to track which word
 *        of @words has already been consumed
 *
 * Return: 1 if the window matches, 0 otherwise.
 */
static int match_concat(char const *s, char const **words, int nb_words,
			int word_len, char *used)
{
	int i, j;

	for (i = 0; i < nb_words; i++)
		used[i] = 0;
	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
			    block_equal(s + i * word_len, words[j], word_len))
			{
				used[j] = 1;
				break;
			}
		}
		if (j == nb_words)
			return (0);
	}
	return (1);
}

/**
 * find_substring - finds every starting index in @s of a substring
 *                  which is the concatenation of every word of @words
 *                  exactly once, in any order, with no gap.
 * @s: string to scan
 * @words: array of words (all sharing the same length)
 * @nb_words: number of elements in @words
 * @n: address at which to store the number of indices in the result
 *
 * Return: a newly allocated array of matching indices, or NULL if
 * no match is found or on allocation failure. ``*n`` is always set.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, i, count = 0;
	int *indices = NULL;
	char *used;

	if (n)
		*n = 0;
	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);
	word_len = str_length(words[0]);
	total_len = word_len * nb_words;
	s_len = str_length(s);
	if (word_len <= 0 || s_len < total_len)
		return (NULL);
	indices = malloc(sizeof(*indices) * (s_len - total_len + 1));
	used = malloc(nb_words);
	if (!indices || !used)
	{
		free(indices);
		free(used);
		return (NULL);
	}
	for (i = 0; i <= s_len - total_len; i++)
		if (match_concat(s + i, words, nb_words, word_len, used))
			indices[count++] = i;
	free(used);
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	*n = count;
	return (indices);
}
