#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - checks whether a pattern matches a string.
 * @str: string to scan (cannot contain '.' or '*')
 * @pattern: regular expression, may contain '.' and '*'
 *
 * The match must cover the entire string.
 * '.' matches any single character.
 * '*' matches zero or more of the preceding character.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
