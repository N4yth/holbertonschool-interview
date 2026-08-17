#!/usr/bin/python3
"""
module that returns a list of lists of integers
representing the Pascal's triangle of n
"""


def pascal_triangle(n):
    """
    function that returns a list of lists of integers
    representing the Pascal's triangle of n
    """
    List = []
    if n <= 0:
        return List

    past_row = []
    row = []
    len_list = 1
    for y in range(0, n):
        for i in range(0, len_list):
            if i == 0 or i == len_list - 1:
                row.append(1)
            else:
                row.append(past_row[i - 1] + past_row[i])
        len_list += 1
        List.append(row[:])
        past_row = row[:]
        row = []
    return List
