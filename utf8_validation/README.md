# UTF-8 Validation

This project contains a method that determines if a given data set represents a valid UTF-8 encoding.

## Function

### `validUTF8`

```python
def validUTF8(data)
```

**Description:** Determines if a given data set represents a valid UTF-8 encoding.

**Parameters:**
- `data`: List of integers where each integer represents 1 byte of data

**Returns:**
- `True` if data is a valid UTF-8 encoding
- `False` otherwise

## UTF-8 Encoding Rules

UTF-8 is a variable-width character encoding that can use 1 to 4 bytes per character:

1. **1-byte character:** `0xxxxxxx` (0-127)
2. **2-byte character:** `110xxxxx 10xxxxxx`
3. **3-byte character:** `1110xxxx 10xxxxxx 10xxxxxx`
4. **4-byte character:** `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`

Continuation bytes always start with `10xxxxxx`.

## Algorithm

The function works by:

1. Iterating through each byte in the data
2. For the first byte of a character, determining how many bytes the character should have based on the leading bits
3. For continuation bytes, verifying they start with the correct bit pattern (`10`)
4. Ensuring all multi-byte sequences are complete

## Usage

```python
validUTF8 = __import__('0-validate_utf8').validUTF8

# Single ASCII character
data = [65]
print(validUTF8(data))  # True

# Multiple ASCII characters ("Python is cool!")
data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

# Invalid UTF-8 sequence
data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```

## Examples

```bash
$ ./0-main.py
True
True
False
```

## Files

- `0-validate_utf8.py` - Implementation of the validUTF8 function
- `0-main.py` - Test file (example)
