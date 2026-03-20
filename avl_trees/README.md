# AVL Trees

## Description

C function that checks whether a binary tree is a valid AVL Tree. An AVL Tree must satisfy three properties: it is a valid Binary Search Tree (BST), the height difference between left and right subtrees is at most 1 for every node, and both subtrees are themselves AVL trees.

## Prototype

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

Returns `1` if the tree is a valid AVL, `0` otherwise. Returns `0` if `tree` is `NULL`.

## Data Structure

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
```

## Files

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file with struct definitions and function prototypes |
| `0-binary_tree_is_avl.c` | Implementation of the AVL validation function |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
```

## Example

```
$ ./0-is_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
```

## Author

Frederic Bourouliou
