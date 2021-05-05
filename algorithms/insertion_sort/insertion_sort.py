"""
Created on Wed May 5 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def insertion_sort(arr):
    """Sorts the given array using insertion sort.

    Average/worst case is O(n^2).
    Best case is O(n).

    Arguments:
        arr: The array to sort.

    Returns:
        The array arr, but sorted.
    """
    # i keeps track of the end of the sorted
    # section. The element immediately after i is
    # moved into the correct position in the
    # sorted section by swapping it with its
    # previous element until it lands in the
    # correct place.
    for i in range(0, len(arr) - 1):
        for k in range(i+1, 0, -1):
            if arr[k] < arr[k-1]:
                temp = arr[k]
                arr[k] = arr[k-1]
                arr[k-1] = temp
            else:
                break

    return arr