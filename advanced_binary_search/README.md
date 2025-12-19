# Advanced Binary Search

## Description

This project implements an advanced binary search algorithm that finds the **first occurrence** of a value in a sorted array of integers. Unlike a basic binary search which may return any index where the value appears, this implementation guarantees returning the index of the first occurrence when duplicates exist.

## Requirements

- Compiled on Ubuntu 14.04 LTS
- Compiled with `gcc 4.8.4` using flags `-Wall -Werror -Wextra -pedantic`
- Code follows Betty style
- No global variables
- No more than 5 functions per file
- Only `printf` from standard library is allowed (no `malloc`, `strdup`, etc.)
- Must use recursion
- Only one loop allowed (for printing the array)

## Files

| File | Description |
|------|-------------|
| `search_algos.h` | Header file with function prototype |
| `0-advanced_binary.c` | Implementation of advanced binary search |

## Function Prototype

```c
int advanced_binary(int *array, size_t size, int value);
```

### Parameters

- `array`: Pointer to the first element of the sorted array
- `size`: Number of elements in the array
- `value`: Value to search for

### Return Value

- Index of the **first occurrence** of `value` in the array
- `-1` if `value` is not found or if `array` is `NULL`

## Algorithm

The algorithm uses a recursive approach with the following logic:

1. Print the current subarray being searched
2. Calculate the middle index: `mid = (size - 1) / 2`
3. If `array[mid] == value`:
   - Continue searching in the left half (including mid) to find an earlier occurrence
   - If no earlier occurrence exists, return the current index
4. If `array[mid] < value`: Search the right half
5. If `array[mid] > value`: Search the left half

## Example

```c
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int main(void)
{
    int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
```

### Output

```
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(1) |
| Average | O(log n) |
| Worst | O(log n) |

## Space Complexity

O(log n) due to recursive call stack.

## Author

Holberton School
