#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """
    test if data is utf-8 encodage
    """
    remaining = 0

    for num in data:
        byte = num & 0xFF
        if remaining == 0:
            mask = 0b10000000
            count = 0
            while mask & byte:
                count += 1
                mask >>= 1
            if count == 0:
                continue

            if count == 1 or count > 4:
                return False

            remaining = count - 1
        else:
            if (byte & 0b11000000) != 0b10000000:
                return False
            remaining -= 1
    return remaining == 0
