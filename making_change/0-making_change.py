#!/usr/bin/python3
"""
main file for fonction to make change
"""


def makeChange(coins, total):
    """
    Main fonction to make change
    """
    nb_coin = 0
    result = 0
    coins.sort(reverse=True)
    for i in range(len(coins)):
        while (coins[i] < total and result + coins[i] <= total):
            result += coins[i]
            nb_coin += 1
        if (result == total):
            return nb_coin
    return -1
