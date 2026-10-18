# Holberton School — Interview preparation (algorithms)

Coursework from Holberton School's software engineering program (2024–2026).

Algorithm and data-structure exercises in C, Python and JavaScript, one folder per problem. Each folder has its own README.

## Topics

- Sorting: `heap_sort`, `merge_sort`, `radix_sort`
- Searching: `advanced_binary_search`, `linear_skip`
- Linked lists: `insert_in_sorted_linked_list`, `linked_list_cycle`, `find_the_loop`, `linked_list_palindrome`, `double_circular_linked_list`
- Trees and heaps: `avl_trees`, `sorted_array_to_avl`, `heap_insert`, `heap_extract`
- Strings and parsing (C): `regex`, `wild_cmp`, `substring`, `infinite_multiplication`, `palindrome_integer`
- Grids and simulations (C): `menger`, `sandpiles`, `slide_line`
- Python: `lockboxes`, `minimum_operations`, `log_parsing`, `utf8_validation`, `nqueens`, `rotate_2d_matrix`, `making_change`, `island_perimeter`, `pascal_triangle`, `primegame`, `rain`, `count_it` (Reddit API)
- JavaScript: `starwars_api` (Node.js script using the Star Wars API)

## Build

C files compile with `gcc -Wall -Werror -Wextra -pedantic`, together with the folder's `*-main.c` when one is provided:

```sh
cd merge_sort && gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

Python scripts target Python 3.
