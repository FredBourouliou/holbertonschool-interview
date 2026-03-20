# Double Circular Linked List

## Description

Implementation of a double circular linked list in C, with functions to add nodes at the beginning and at the end of the list.

In a double circular linked list, every node has a `prev` and `next` pointer. The last node's `next` points back to the first node, and the first node's `prev` points to the last node.

## Prototype

```c
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
```

## Data Structure

```c
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
```

## Files

| File | Description |
|------|-------------|
| `list.h` | Header file with struct definition and function prototypes |
| `0-add_node.c` | Implementation of `add_node_end` and `add_node_begin` |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c -o dcll
```

## Example

```
$ ./dcll
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```

## Author

Frederic Bourouliou
