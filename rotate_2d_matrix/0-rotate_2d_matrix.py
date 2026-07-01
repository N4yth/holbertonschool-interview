#!/usr/bin/python3
"""
module that turn a matrix 90°
"""

def rotate_2d_matrix(matrix):
    """function that turn a matrix 90°"""
    n = len(matrix)

    for stage in range(n // 2):
        first = stage
        last = n - 1 - stage

        for i in range(first, last):
            gap = i - first

            temp = matrix[first][i]
            matrix[first][i] = matrix[last - gap][first]
            matrix[last - gap][first] = matrix[last][last - gap]
            matrix[last][last - gap] = matrix[i][last]
            matrix[i][last] = temp
