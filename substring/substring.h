#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - finds every starting index in @s of a substring
 *                  which is the concatenation of every word of @words
 *                  exactly once, in any order, with no gap.
 * @s: string to scan
 * @words: array of words (all of the same length)
 * @nb_words: number of elements in @words
 * @n: address at which to store the number of indices in the result
 *
 * Return: a newly allocated array holding each matching index, or
 * NULL if no match was found or on allocation failure. The caller is
 * responsible for freeing the returned array.
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n);

#endif /* SUBSTRING_H */
