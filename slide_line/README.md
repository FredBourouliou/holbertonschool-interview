# Slide Line

## Description
This project implements the sliding and merging mechanics of the 2048 game on a single horizontal line. The `slide_line` function slides and merges an array of integers either to the left or to the right.

## Algorithm
The implementation uses a three-step process:

### For SLIDE_LEFT:
1. **Compact left**: Move all non-zero elements to the left
2. **Merge left**: Merge adjacent identical numbers from left to right
3. **Compact left**: Remove zeros created by merging

### For SLIDE_RIGHT:
1. **Compact right**: Move all non-zero elements to the right
2. **Merge right**: Merge adjacent identical numbers from right to left
3. **Compact right**: Remove zeros created by merging

## Key Rules
- Identical numbers are merged only once per pass
- After merging, the resulting value is doubled
- Zeros between identical numbers don't prevent merging
- The merge happens in one direction based on the slide direction

## Files
- `slide_line.h`: Header file with function prototype and direction macros
- `0-slide_line.c`: Implementation of the slide_line function
- `0-main.c`: Test file (not required to push)

## Usage
```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
./0-slide_line L 2 2 0 0
./0-slide_line R 2 2 2 2
```

## Examples
```bash
# Slide left with merge
$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0

# Slide right with multiple merges
$ ./0-slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
```
