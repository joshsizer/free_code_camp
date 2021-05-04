"""
Created on Tue May 4 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def bubble_sort(arr):
    """Sort the array using bubble sort.

    Runtime is O(n^2).
    
    Arguments:
        arr: The array to sort.

    Returns:
        arr, but sorted.
    """
    # I would normally comment, but it's bubble
    # sort.
    for i in range(len(arr)):
        # The only thing of note is that we
        # optimize it a little. Each iteration,
        # the next highest value is bubbled to the
        # sorted section. We stop looking at the
        # elements we've already bubbled into
        # sorted position.
        for j in range(1, len(arr)-i):
            if arr[j] < arr[j-1]:
                temp = arr[j]
                arr[j] = arr[j-1]
                arr[j-1] = temp

    return arr