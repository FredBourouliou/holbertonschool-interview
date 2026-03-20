# Radix Sort

## Description

Implementation of the LSD (Least Significant Digit) Radix Sort algorithm in C. This algorithm sorts an array of non-negative integers by processing each digit from the least significant to the most significant, using counting sort as a stable subroutine.

## Prototype

```c
void radix_sort(int *array, size_t size);
```

## Complexity

| Case | Time | Space |
|------|------|-------|
| Best | O(nk) | O(n + k) |
| Average | O(nk) | O(n + k) |
| Worst | O(nk) | O(n + k) |

Where `n` is the number of elements and `k` is the number of digits in the maximum value.

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-radix_sort.c` | Implementation of the radix sort algorithm |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Example

```
$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Author

Frederic Bourouliou
