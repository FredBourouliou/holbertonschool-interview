# Sorted Array to AVL Tree

This project implements a function that builds an AVL tree from a sorted array.

## Description

The function `sorted_array_to_avl` takes a sorted array of integers and constructs a balanced AVL tree without using any rotation operations. This is achieved by recursively selecting the middle element of each subarray as the root of the subtree.

## Algorithm

1. Find the middle element of the array - this becomes the root
2. Recursively build the left subtree from elements before the middle
3. Recursively build the right subtree from elements after the middle

This divide-and-conquer approach naturally creates a balanced tree.

## Files

- `binary_trees.h` - Header file with data structures and prototypes
- `0-sorted_array_to_avl.c` - Implementation of the sorted_array_to_avl function

## Prototype

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Usage

```c
int array[] = {1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98};
size_t n = sizeof(array) / sizeof(array[0]);
avl_t *tree = sorted_array_to_avl(array, n);
```
