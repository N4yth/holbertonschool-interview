#!/usr/bin/python3
"""
Main file for testing
"""

def validUTF8(data):
    """
    test if data is utf-8 encodage
    """
    idx = 0
    while (len(data) > idx):
        if (data[idx] > 255):
            return False
        idx+=1
    return True
