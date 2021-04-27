"""
Created on Sun Apr 25 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""


def sym(*args):
    """Return the symmetric difference of two or
    more sets. If only one set is input, the same
    set is returned unmodified. If no set is
    input, null is returned.

    Arguments:
        args: n different sets

    Returns: The symmetric difference of two or
    more sets
    """
    # Return None if the length of args is 0
    if not args:
        return None

    # Simulate recursion with a stack
    stack = []

    # Add each argument (set) onto the stack
    for arg in args:
        stack.append(arg)

    # The first set to compare
    current = stack.pop()

    # Compare sets until our stack is empty
    while stack:
        # Get the set to compare to the current
        to_compare = stack.pop()

        # Calculate the symmetric difference
        # between these two particular elements.
        current = sym_pairwise(current, to_compare)

    return current


def sym_pairwise(arg1, arg2):
    """Calculates the symmetric difference of two
    sets.

    Arguments:
        arg1 -- the first set
        arg2 -- the second set

    Returns: the symmetric difference of two sets
    """
    result = []

    # Add each element in arg1 to result as long
    # as the element is not in arg2 and not
    # already in result.
    for element in arg1:
        if element not in arg2 and element not in result:
            result.append(element)

    # Add each element in arg2 to result as long
    # as the element is not in arg1 and not
    # already in result.
    for element in arg2:
        if element not in arg1 and element not in result:
            result.append(element)

    return result
