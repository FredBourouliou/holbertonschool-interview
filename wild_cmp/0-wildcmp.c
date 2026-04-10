#include "holberton.h"

/**
 * wildcmp - compares two strings, allowing '*' in s2 as a wildcard.
 * @s1: first string
 * @s2: second string, may contain the special character '*' which can
 *      replace any string (including an empty string)
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*s1 == '\0')
			return (0);
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
