#!/usr/bin/python3
"""
UTF-8 Validation module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data: List of integers where each integer represents 1 byte of data

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    num_bytes = 0

    for num in data:
        # Get only the 8 least significant bits
        byte = num & 0xFF

        if num_bytes == 0:
            # Determine how many bytes in this UTF-8 character
            if (byte >> 7) == 0b0:
                # 1-byte character (0xxxxxxx)
                num_bytes = 0
            elif (byte >> 5) == 0b110:
                # 2-byte character (110xxxxx)
                num_bytes = 1
            elif (byte >> 4) == 0b1110:
                # 3-byte character (1110xxxx)
                num_bytes = 2
            elif (byte >> 3) == 0b11110:
                # 4-byte character (11110xxx)
                num_bytes = 3
            else:
                # Invalid start byte
                return False
        else:
            # This should be a continuation byte (10xxxxxx)
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1

    # All characters should be complete
    return num_bytes == 0
