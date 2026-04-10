#include "regex.h"

/**
 * regex_match - checks whether a pattern matches a string.
 * @str: string to scan
 * @pattern: regular expression, may contain '.' and '*'
 *
 * The whole string must be consumed by the pattern for the match
 * to be successful.
 * '.'  matches any single character.
 * 'c*' matches zero or more occurrences of character ``c`` (or of
 *      any character when ``c`` is '.').
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return (regex_match(str + 1, pattern));
		return (0);
	}

	if (*str != '\0' && (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
