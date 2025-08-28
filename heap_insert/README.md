# Heap Insert

This project implements a Max Binary Heap with insertion functionality.

## Files

- `binary_trees.h` - Header file with structure definitions and function prototypes
- `0-binary_tree_node.c` - Function to create a binary tree node
- `1-heap_insert.c` - Function to insert a value into a Max Binary Heap
- `binary_tree_print.c` - Utility function to print binary trees (for visualization)

## Tasks

### 0. New node
Creates a binary tree node with a given parent and value.

### 1. Heap - Insert
Inserts a value into a Max Binary Heap while maintaining heap properties.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
gcc -Wall -Werror -Wextra -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
```

## Usage

```bash
./0-node
./1-heap_insert
```