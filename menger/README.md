# 2D Menger Sponge

## Description

This project implements a function to draw a 2D Menger sponge. The Menger sponge is a three-dimensional fractal, but here we only draw a two-dimensional version.

## Concept

A level N Menger sponge is built recursively:

- **Level 0**: A simple square represented by the `#` character
- **Level 1**: A 3×3 square of level 0 sponges, except for the center one, which is left empty
- **Level 2**: A 3×3 square of level 1 sponges, except for the center one, which is left empty
- **Level N**: A 3×3 square of level N-1 sponges, except for the center one, which is left empty

### Size Formula

The size of a level N Menger sponge is: **3^N**

- Level 0: 3^0 = 1×1
- Level 1: 3^1 = 3×3
- Level 2: 3^2 = 9×9
- Level 3: 3^3 = 27×27
- Level 4: 3^4 = 81×81

## Algorithm

The algorithm checks for each position (row, column) whether it is in the center of a 3×3 block at any scale:

1. For each position, we check at different scales (3, 9, 27, etc.)
2. If `row % 3 == 1` AND `column % 3 == 1` at a given scale, it's a "hole" (space)
3. Otherwise, it's a solid block (`#`)

## Files

| File | Description |
|------|-------------|
| `menger.h` | Header file containing the function prototype |
| `0-menger.c` | Implementation of the `menger()` function |
| `0-main.c` | Main test file |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

**Note**: The `-lm` flag is required to link the math library (`pow` function).

## Usage

```bash
./0-menger [level]
```

### Examples

**Level 0**:
```bash
./0-menger 0
```
Output:
```
#
```

**Level 1**:
```bash
./0-menger 1
```
Output:
```
###
# #
###
```

**Level 2**:
```bash
./0-menger 2
```
Output:
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

**Level 3**:
```bash
./0-menger 3
```
Output: 27×27 grid with the Menger sponge fractal pattern

**Negative level**:
```bash
./0-menger -1
```
Output: (no output, the function does nothing)

## Prototype

```c
void menger(int level);
```

### Parameters

- `level`: The level of the Menger sponge to draw
  - If `level < 0`, the function does nothing
  - If `level >= 0`, draws the corresponding sponge

## Requirements

- **Compiler**: gcc 4.8.4
- **Flags**: `-Wall -Werror -Wextra -pedantic`
- **System**: Ubuntu 14.04 LTS
- **Style**: Betty
- **Library**: math library (`-lm`)

## Pattern Visualization

The Menger sponge pattern follows a fractal logic where each level repeats the pattern of the previous level:

```
Level 0:           Level 1:           Level 2:
#                  ###                #########
                   # #                # ## ## #
                   ###                #########
                                      ###   ###
                                      # #   # #
                                      ###   ###
                                      #########
                                      # ## ## #
                                      #########
```

We can observe that:
- Level 1 is composed of 9 level 0 blocks (3×3), with the center being empty
- Level 2 is composed of 9 level 1 blocks (3×3), with the center being empty
- And so on...

## Author

Project completed as part of the Holberton School curriculum - Interview Preparation
