# Rain

Calculate rainwater retention given wall heights.

## Description

Given a list of non-negative integers representing wall heights, calculate how many square units of water will be retained after rain.

## Algorithm

For each position, water retained = min(max_left, max_right) - height

Uses two passes to precompute maximum heights from left and right.

## Usage

```python
rain = __import__('0-rain').rain
walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6
```

## Prototype

```python
def rain(walls)
```
