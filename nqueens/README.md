# N Queens Problem

## Description

The N queens puzzle is the challenge of placing N non-attacking queens on an N×N chessboard. This project implements a solution to the N queens problem using backtracking algorithm.

## Background

The N queens problem is a classic puzzle in computer science and mathematics. The challenge is to place N chess queens on an N×N chessboard so that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.

## Algorithm

This implementation uses **backtracking** to find all possible solutions:

1. Place queens one by one in different rows
2. For each row, try placing a queen in each column
3. Check if the placement is safe (no conflicts with previously placed queens)
4. If safe, recursively try to place the rest of the queens
5. If all N queens are placed successfully, record the solution
6. Backtrack if a queen cannot be placed in any column

### Safety Check

A position is considered safe if:
- No other queen is in the same column
- No other queen is on the same diagonal (where `row - col` is constant)
- No other queen is on the same anti-diagonal (where `row + col` is constant)

## Files

| File | Description |
|------|-------------|
| `0-nqueens.py` | Main program that solves the N queens problem |

## Usage

```bash
./0-nqueens.py N
```

Where `N` is an integer representing the size of the chessboard (and the number of queens).

### Requirements

- `N` must be an integer greater than or equal to 4
- Only the `sys` module is imported

## Examples

### N = 4

```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

This finds 2 solutions for a 4×4 board. Each solution is represented as a list of `[row, column]` pairs.

### N = 6

```bash
$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

This finds 4 solutions for a 6×6 board.

## Error Handling

The program handles the following error cases:

### Wrong Number of Arguments

```bash
$ ./0-nqueens.py
Usage: nqueens N
```

### Non-Integer Input

```bash
$ ./0-nqueens.py abc
N must be a number
```

### N Less Than 4

```bash
$ ./0-nqueens.py 3
N must be at least 4
```

## Output Format

Each solution is printed on a separate line in the format:
```
[[row0, col0], [row1, col1], [row2, col2], ..., [rowN-1, colN-1]]
```

Where:
- `row` is the row index (0 to N-1)
- `col` is the column index (0 to N-1)
- Each `[row, col]` pair represents the position of a queen

## Visualization

For the solution `[[0, 1], [1, 3], [2, 0], [3, 2]]` on a 4×4 board:

```
. Q . .    (row 0, queen at column 1)
. . . Q    (row 1, queen at column 3)
Q . . .    (row 2, queen at column 0)
. . Q .    (row 3, queen at column 2)
```

No two queens can attack each other in this configuration.

## Time Complexity

The time complexity of this backtracking solution is O(N!) in the worst case, as we explore all possible placements of queens.

## Requirements

- **Interpreter**: Python 3 (version 3.4.3)
- **System**: Ubuntu 14.04 LTS
- **Style**: PEP 8 (version 1.7.*)
- **Shebang**: `#!/usr/bin/python3`
- **Executable**: File must be executable

## Author

Project completed as part of the Holberton School curriculum - Interview Preparation
