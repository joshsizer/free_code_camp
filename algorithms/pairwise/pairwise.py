"""
Created on Mon May 3 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def pairwise(arr, arg):
    """Get the sum of all index pairs, where
    the values at the index pairs add up to arg.
    For example, pairwise([1, 4, 2, 3, 0, 5], 7)
    finds the index pairs [1, 3] because arr[1] +
    arr[3] = 7 as well as index pairs [2, 5]
    because arr[2] + arr[5] = 7. The total sum of
    all index pairs is 1 + 3 + 2 + 5 = 11.

    Arguments:
        arr: an array of numbers
        arg: the target sum to look for

    Returns:
        The total sum of all index pairs, where
        each index pair's values add up to arg.
    """
    # We keep a running sum and an auxillary array
    # to keep track of which indices have already
    # been used in an index pair.
    idx_sum = 0
    taken = [False for _ in range(len(arr))]
    
    # Grab the first index pair.
    (i, j) = single_pairwise(arr, arg, taken)

    # Sum of 0 is returned if no pairs were found
    # yet. Otherwise, we accumulate our index
    # pairs into idx_sum and update our auxillary
    # array.
    while (i != -1):
        idx_sum += i + j

        # No index may be used in more than one
        # pair, so we have to mark which indices
        # have already been used.
        taken[i] = True
        taken[j] = True

        # Try to find another index pair.
        (i, j) = single_pairwise(arr, arg, taken)

    return idx_sum

def single_pairwise(arr, arg, taken):
    """Get a single index pair (i, j), where
    arr[i] + arr[j] == arg. 

    Arguments:
        arr: an array of numbers
        arg: the target sum to look for
        taken: an array as long as arr designating
            if a particular index can be in a new
            index pair.
    """
    i = -1
    j = -1

    # Compare the sum of every pair of values in
    # arr to arg, and return the first set of
    # indices where the pair of values add to arg.
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == arg and taken[i] == taken[j] == False:
                return (i, j)

    # If no pair of values sum to arg, then we
    # indicate that with special value -1.
    return (-1, -1)