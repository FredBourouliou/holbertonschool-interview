# Heap Extract

This project implements a function to extract the root node from a Max Binary Heap.

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4
- Betty style compliant

## Files

- `binary_trees.h` - Header file with data structures and function prototypes
- `0-heap_extract.c` - Implementation of heap_extract function

## Function

```c
int heap_extract(heap_t **root);
```

Extracts the root node of a Max Binary Heap:
- Returns the value stored in the root node
- The root node is freed and replaced with the last level-order node
- The heap is rebuilt to maintain the max heap property
- Returns 0 on failure

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -o heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
```
