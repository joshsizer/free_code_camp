"""
Created on Sun Apr 25 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""


def inventory_update(arr1, arr2):
    """Add the inventory from arr2 to arr1.

    If an item exists in both arr1 and arr2, then
    the quantity of the item is updated in arr1.
    If an item exists in only arr2, then the item
    is added to arr1. If an item only exists in
    arr1, then that item remains unaffected.

    Arguments:
        arr1: the destination inventory
        arr2: the inventory to add to the
        destination inventory

    Returns: a combined inventory
    """
    # Set longer to the longer of the two arrays
    longer = arr2
    if len(longer) > len(arr1):
        temp = arr1
        arr1 = longer
        longer = temp

    # Since longer is potentially modified, set it
    # to a copy of itself.
    longer = longer.copy()

    # Iterate over the shorter array, appending
    # items that don't exist in the longer array,
    # or updating the quantity of existing items.
    for tup in arr1:
        qty = tup[0]
        name = tup[1]

        # Funny way to get the index of an array
        # object based on the object's own indexed
        # elements.
        try:
            i = [x[1] for x in longer].index(name)
        except ValueError:
            i = -1

        if i < 0:
            longer.append(tup)
        else:
            longer[i][0] += qty

    # Man, why doesn't the index function accept a
    # key argument? Sort on the string description
    # of each inventory item.
    longer.sort(key=lambda x: x[1])

    return longer
