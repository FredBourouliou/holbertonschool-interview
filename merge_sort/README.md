# Merge Sort

Implementation of the top-down merge sort algorithm in C.

## Prototype

```c
void merge_sort(int *array, size_t size);
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

## Complexity

- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))
