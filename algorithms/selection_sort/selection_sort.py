"""
Created on Wed May 5 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def selection_sort(arr):
    """Sort the given array using selection sort.

    Arguments:
        arr: The array to sort.

    Returns:
        The same array, arr, but sorted in
        increasing order.
    """
    # The array is separated into the sorted
    # section, with indices less than i, and the
    # unsorted, with indices greater than or
    # equal to i. Each pass of the array finds
    # the minimum in the unsorted section, and
    # appends it to the end of the sorted section.
    for i in range(len(arr) - 1):
        min_idx = i 
        for k in range(i + 1, len(arr)):
            if arr[k] < arr[min_idx]:
                min_idx = k
        
        temp = arr[i]
        arr[i] = arr[min_idx]
        arr[min_idx] = temp

    return arr