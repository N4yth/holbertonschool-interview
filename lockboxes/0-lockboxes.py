#!/usr/bin/python3
"""
Determine if all boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Returns True if all boxes can be opened, else False
    """
    n = len(boxes)
    opened = set([0])
    keys = [0]

    while keys:
        box = keys.pop()

        for key in boxes[box]:
            if key < n and key not in opened:
                opened.add(key)
                keys.append(key)

    return len(opened) == n
