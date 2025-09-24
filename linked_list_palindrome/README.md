# Linked List Palindrome

## Description
This project implements a function to check if a singly linked list is a palindrome.

## Files
- `0-is_palindrome.c` - Contains the implementation of the palindrome check function
- `lists.h` - Header file with function prototypes and structure definitions
- `linked_lists.c` - Helper functions for linked list operations
- `0-main.c` - Test file with the example from the problem
- `1-main.c` - Additional test cases

## Algorithm
The solution uses the following approach:
1. Find the middle of the linked list using the slow/fast pointer technique
2. Reverse the second half of the list
3. Compare the first half with the reversed second half
4. Restore the original list structure (reverse the second half back)
5. Return the result

## Time Complexity: O(n)
## Space Complexity: O(1)

## Function Prototype
```c
int is_palindrome(listint_t **head);
```

Returns:
- 1 if the linked list is a palindrome
- 0 if it is not a palindrome

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Usage
```bash
./palindrome
```