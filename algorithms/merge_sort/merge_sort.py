"""
Created on Fri May 7 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def merge_sort(arr, low=0, high=None):
    """Sort the given array using merge sort.

    Runtime average and best case is O(nlog(n)).

    Arguments:
        arr: The array to sort.
        low: The beginning of the sub-array.
        high: The end of the sub-array.

    Returns:
        arr, but sorted.
    """

    # The first time merge_sort is called, high
    # will likely be None because the user wants
    # to sort the entire array.
    if high is None:
        high = len(arr) - 1

    # Base case of recursion.
    if high-low <= 0:
        return

    # Find the middle index of the array. In the
    # case of an odd-sized array, the left
    # sub-array will be bigger than the right
    # sub-array.
    middle = int(low + ((high-low) / 2))

    # Sort the left and right sub-arrays
    merge_sort(arr, low, middle)
    merge_sort(arr, middle+1, high)

    # Merge the left and right sub-arrays
    merge(arr, low, middle, high)

    return arr

def merge(arr, low, middle, high):
    """Merge the given sub-arrays into one larger
    sub-array that is in correct order.

    Arguments:
        arr: The array whose sections should be
            merged.
        low: The start index of the first
            sub-array.
        middle: The end index of the first
            sub-array.
        high: The end index of the second
            sub-array.
        
    Returns:
        arr, where the values in indices low to
        high are in sorted order.
    """
    # Need auxillary array so that no information
    # is lost in the merging process.
    left = arr[low:middle + 1]
    right = arr[middle + 1:high+1]

    # i is the current position in the left
    # sub-array. j is the current position in the
    # right sub-array. k is the current position
    # in the original array.
    i = j = 0
    k = low

    # Exhaust all elements in the left or right
    # array by adding them to the original array
    # in sequential, ascending order.
    while i < len(left) and j < len(right):
        to_add = None
        if left[i] < right[j]:
            to_add = left[i]
            i += 1
        else:
            to_add = right[j]
            j += 1

        arr[k] = to_add
        k += 1

    # If the left sub-array still has elements,
    # add the remaining to the original array.
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    # If the right sub-array still has elements,
    # add the remaining to the original array
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

print(merge_sort([-919, -661, 263, -329, -672, -680, 629, 708, 717, 586]))