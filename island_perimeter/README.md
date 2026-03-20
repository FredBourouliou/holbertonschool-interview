# Island Perimeter

## Description

Python function that computes the perimeter of an island represented in a 2D grid. Each cell is a square of side length 1. Land cells are `1`, water cells are `0`.

## Prototype

```python
def island_perimeter(grid):
```

## Algorithm

For each land cell, start with 4 sides. For each adjacent land neighbor (above or to the left), subtract 2 (the shared edge is counted once per cell). This runs in O(n*m) time with O(1) extra space.

## Files

| File | Description |
|------|-------------|
| `0-island_perimeter.py` | Implementation of the `island_perimeter` function |

## Example

```python
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
print(island_perimeter(grid))  # Output: 12
```

```
$ ./0-main.py
12
```

## Author

Frederic Bourouliou
