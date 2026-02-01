# Rotate 2D Matrix

This project implements an in-place 90-degree clockwise rotation of an n x n 2D matrix.

## Requirements

- Python 3.4.3+
- PEP 8 style
- No module imports allowed

## Files

- `0-rotate_2d_matrix.py` - Main implementation

## Function

```python
def rotate_2d_matrix(matrix):
```

Rotates an n x n 2D matrix 90 degrees clockwise in-place.

## Algorithm

1. **Transpose**: Swap elements across the main diagonal (matrix[i][j] with matrix[j][i])
2. **Reverse rows**: Reverse each row of the transposed matrix

## Example

```python
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

rotate_2d_matrix(matrix)
# Result: [[7, 4, 1],
#          [8, 5, 2],
#          [9, 6, 3]]
```

## Usage

```bash
./main_0.py
```
