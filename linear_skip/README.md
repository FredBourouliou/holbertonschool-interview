# Linear Skip List Search

Implementation of a linear search in a skip list data structure.

## Description

A skip list is a singly linked list with an "express lane" that allows for faster searching. The express lane connects nodes at indices that are multiples of the square root of the list size.

## Algorithm

1. Traverse the express lane until finding a node with value >= target
2. Linear search within the identified range
3. Return pointer to node if found, NULL otherwise

## Files

- `search.h` - Header file with skiplist structure and prototypes
- `0-linear_skip.c` - Implementation of linear_skip function

## Prototype

```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```
