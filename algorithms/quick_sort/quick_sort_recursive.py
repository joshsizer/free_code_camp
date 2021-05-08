"""
Created on Thu May 6 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def quick_sort(arr, low=0, high=None):
    """Sort the given sub-array using quick sort.

    Runtime is O(nlog(n)) on average. Worst case
    is O(n^2). Each partition call is order O(n).

    The number of partition calls will be about
    log(n) with good choices of pivot. Random
    pivots or static pivots on randomly ordered
    datasets will tend to produce log(n) calls.
    There are circumstances, though, where there
    could be n partition calls, leading to the
    O(n^2) runtime.

    Arguments:
        arr: The array to sort.
        low: The beginning index of the sub-array.
        high: The ending index of the sub-array.

    Returns:
        The given array, arr, but sorted.
    """
    # On the first call, high is not specified.
    if high is None:
        high = len(arr) - 1

    # If high is ever the same or less than low,
    # it means our subarray is of size 0 or 1, so we
    # just return.
    if high - low <= 0:
        return

    # Using the high index as a pivot (the end of
    # the sub array), divide the array so that
    # everything to the left of the pivot is less
    # than the pivot, and everything to the right
    # of pivot is greater than the pivot.
    partition_idx = partition(arr, low, high)

    # Recursively call quick_sort
    quick_sort(arr, low, partition_idx - 1)
    quick_sort(arr, partition_idx + 1, high)

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

