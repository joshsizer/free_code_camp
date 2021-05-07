"""
Created on Fri May 7 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def quick_sort(arr):
    """Sort the given array using quick sort.

    Arguments:
        arr: The array to sort.

    Returns:
        The given array, arr, but sorted.
    """
    stack = [(0, len(arr) - 1)]

    while stack:
        (low, high) = stack.pop()
        
        # If high is ever the same or less than low,
        # it means our subarray is of size 0 or 1, so we
        # just continue to the next item in the stack.
        if high - low <= 0:
            continue
        
        # Using the high index as a pivot (the end of
        # the sub array), divide the array so that
        # everything to the left of the pivot is less
        # than the pivot, and everything to the right
        # of pivot is greater than the pivot.
        partition_idx = partition(arr, low, high)

        # Simulate recursion by adding our
        # "function call arguments" to the stack.
        stack.append((low, partition_idx - 1))
        stack.append((partition_idx + 1, high))

    return arr

def partition(arr, low, high):
    """Semi-orders the given sub-array around the
    pivot value.

    The pivot value is the last element in the
    sub-array. At the end of this call, each
    element greater than pivot will come after
    pivot, and every element smaller than pivot
    will come before pivot.

    Arguments:
        arr: The array to partition.
        low: The start index of the sub-array.
        high: The end index of the sub-array.

    Returns: arr where the given sub-array is
             partitioned around the pivot.
    """
    pivot = high
    left = low
    right = high - 1

    while True:
        while arr[left] < arr[pivot]:
            left += 1

        while right > 0 and arr[right] > arr[pivot]:
            right -= 1

        if left >= right:
            break
        else:
            swap(arr, left, right)

    swap(arr, left, pivot)
    return left

def swap(arr, i, j):
    """Switches the element at position i with the
    element at position j in the given array.

    Arguments:
        arr: The array to swap elements.
        i: The first index to swap.
        j: The second index to swap.
    """
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

print(quick_sort([1, 4, -1, 2, -7]))