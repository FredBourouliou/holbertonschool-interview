#!/usr/bin/python3
"""
Extended test file for UTF-8 validation
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

# Test 1: Single ASCII character (1-byte)
print("Test 1 - Single ASCII:", validUTF8([65]))  # Expected: True

# Test 2: Multiple ASCII characters (1-byte each)
print("Test 2 - Multiple ASCII:", validUTF8([80, 121, 116, 104, 111, 110]))  # Expected: True

# Test 3: Invalid sequence (3-byte start but no continuation)
print("Test 3 - Invalid sequence:", validUTF8([229, 65, 127, 256]))  # Expected: False

# Test 4: Valid 2-byte character
print("Test 4 - Valid 2-byte:", validUTF8([0xC2, 0xA9]))  # © symbol, Expected: True

# Test 5: Valid 3-byte character
print("Test 5 - Valid 3-byte:", validUTF8([0xE2, 0x82, 0xAC]))  # € symbol, Expected: True

# Test 6: Valid 4-byte character
print("Test 6 - Valid 4-byte:", validUTF8([0xF0, 0x9F, 0x98, 0x80]))  # Emoji, Expected: True

# Test 7: Incomplete 2-byte sequence
print("Test 7 - Incomplete 2-byte:", validUTF8([0xC2]))  # Expected: False

# Test 8: Invalid continuation byte
print("Test 8 - Invalid continuation:", validUTF8([0xC2, 0x20]))  # Expected: False

# Test 9: Empty data
print("Test 9 - Empty data:", validUTF8([]))  # Expected: True

# Test 10: Only least significant 8 bits matter
print("Test 10 - 8 LSB only:", validUTF8([456]))  # 456 & 0xFF = 200 = 11001000, Expected: False
