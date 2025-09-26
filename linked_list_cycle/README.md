# Linked List Cycle

## Description
This project implements a function to detect if a singly linked list has a cycle in it. The solution uses Floyd's cycle-finding algorithm (also known as the "tortoise and hare" algorithm) for optimal performance.

## Algorithm
The function uses two pointers moving at different speeds:
- **Slow pointer**: Moves one node at a time
- **Fast pointer**: Moves two nodes at a time

If there's a cycle, the fast pointer will eventually meet the slow pointer. If there's no cycle, the fast pointer will reach the end of the list (NULL).

## Complexity
- **Time Complexity**: O(n) where n is the number of nodes
- **Space Complexity**: O(1) - only two pointers are used

## Files
- `0-check_cycle.c`: Contains the implementation of the `check_cycle` function
- `lists.h`: Header file with structure definitions and function prototypes
- `0-linked_lists.c`: Helper functions for linked list operations
- `0-main.c`: Test file to verify the implementation

## Function Prototype
```c
int check_cycle(listint_t *list);
```
- **Parameters**: `list` - pointer to the head of the linked list
- **Return**:
  - `0` if there is no cycle
  - `1` if there is a cycle

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Usage
```bash
./cycle
```

## Expected Output
```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Requirements
- Ubuntu 14.04 LTS
- gcc 4.8.4
- Betty style compliance
- No global variables
- Maximum 5 functions per file
- Only allowed functions: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`