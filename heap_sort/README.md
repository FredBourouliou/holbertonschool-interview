# Heap Sort

Implementation of the Heap Sort algorithm in C using the sift-down approach.

## Description

Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. This implementation:

1. Builds a max-heap from the input array
2. Repeatedly extracts the maximum element and rebuilds the heap
3. Prints the array after each swap operation

## Files

- `sort.h` - Header file with function prototypes
- `0-heap_sort.c` - Implementation of heap sort using sift-down
- `0-O` - Big O notation for time complexity
- `print_array.c` - Helper function to print arrays

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

## Time Complexity

- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))

## Author

Holberton School
