#!/usr/bin/python3
"""
N Queens Problem Solver

This module solves the N queens puzzle using backtracking.
The N queens puzzle is the challenge of placing N non-attacking
queens on an N×N chessboard.
"""
import sys


def is_safe(board, row, col):
    """
    Check if it's safe to place a queen at board[row][col]

    Args:
        board: List of queen positions where index is row, value is column
        row: Current row to check
        col: Current column to check

    Returns:
        True if position is safe, False otherwise
    """
    for i in range(row):
        # Check if same column
        if board[i] == col:
            return False
        # Check diagonal (row - col is constant on diagonal)
        if board[i] - i == col - row:
            return False
        # Check anti-diagonal (row + col is constant on anti-diagonal)
        if board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n, row, board, solutions):
    """
    Recursively solve N queens problem using backtracking

    Args:
        n: Size of the chessboard
        row: Current row to place queen
        board: List of queen positions
        solutions: List to store all solutions
    """
    if row == n:
        # All queens placed successfully, add solution
        solutions.append([[i, board[i]] for i in range(n)])
        return

    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(n, row + 1, board, solutions)
            # Backtrack (no need to explicitly remove, will be overwritten)


def main():
    """Main function to handle input and print solutions"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    board = [-1] * n
    solve_nqueens(n, 0, board, solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
