# Minimum Operations

## Description
This project implements a solution to calculate the minimum number of operations needed to achieve exactly n H characters in a text file, starting with a single H character. The only allowed operations are:
- Copy All: Copy all the H characters present in the file
- Paste: Paste the copied characters

## Algorithm
The solution uses prime factorization to determine the minimum number of operations. The key insight is that the minimum number of operations to reach n characters equals the sum of the prime factors of n.

## Files
- `0-minoperations.py`: Contains the main function `minOperations(n)` that calculates the minimum number of operations
- `0-main.py`: Test file to verify the implementation

## Usage
```bash
./0-main.py
```

## Example
For n = 9:
- H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
- Number of operations: 6

For n = 12:
- The prime factorization of 12 is 2² × 3
- Minimum operations = 2 + 2 + 3 = 7