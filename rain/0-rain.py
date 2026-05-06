#!/usr/bin/python3
"""
code that return Integer indicating total amount of rainwater retained.
"""


def rain(walls):
    """return Integer indicating total amount of rainwater retained."""
    result = 0
    tmp = 0
    if not walls:
        return 0
    for i in range(len(walls)):
        if walls[i] > 0 and walls[tmp] > 0 and i > 0:
            if walls[i] > walls[tmp]:
                result += walls[tmp] * (i - tmp - 1)
            else:
                result += walls[i] * (i - tmp - 1)
        if walls[i] > 0:
            tmp = i
            
    return result
