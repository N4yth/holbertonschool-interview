#!/usr/bin/python3
"""
code that return the minimum number of operations to reach nH
"""


def minOperations(n):
    """return the minimum number of operations to reach nH"""
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
