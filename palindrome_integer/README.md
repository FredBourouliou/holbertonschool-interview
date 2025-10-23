# Palindrome Integer

This project contains a function that checks whether or not a given unsigned integer is a palindrome.

## Function

### `is_palindrome`

```c
int is_palindrome(unsigned long n);
```

**Description:** Checks whether or not a given unsigned integer is a palindrome.

**Parameters:**
- `n`: The number to be checked

**Return:**
- `1` if n is a palindrome
- `0` otherwise

## Algorithm

The function works by:
1. Storing the original number
2. Reversing the number by extracting digits one by one (using modulo 10 and division by 10)
3. Comparing the reversed number with the original
4. Returning 1 if they match, 0 otherwise

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

## Usage

```bash
./palindrome <number>
```

## Examples

```bash
$ ./palindrome 1
1 is a palindrome.

$ ./palindrome 121
121 is a palindrome.

$ ./palindrome 112
112 is not a palindrome.

$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
```

## Files

- `palindrome.h` - Header file containing function prototype
- `0-is_palindrome.c` - Implementation of the is_palindrome function
- `0-main.c` - Test file (example)
