#!/usr/bin/python3

'''
This module contain 2 function that return a bool
use to konw if all given boxes is openable
'''


def canUnlockAll(boxes):
    '''
    This function is the main function of this module
    '''
    length = len(boxes)
    list_check = [True]
    for i in range(length - 1):
        list_check.append(False) 
    list_check = recursive(boxes, 0, list_check)
    bilan_check = list_check.count(True)
    if (bilan_check == length):
        return(True)
    return(False)

def recursive(boxes, idx, list_check):
    '''
    This function is the recursion function to go throught the boxes
    '''
    if list_check[idx] == False or idx == 0:
        if boxes[idx]:
            ele = 0
            for i in boxes[idx]:
                list_check[idx] = True
                list_check = recursive(boxes, boxes[idx][ele], list_check)
                ele+=1
    list_check[idx] = True
    return list_check
