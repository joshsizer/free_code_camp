"""
Created on Sun May 2 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

def perm_alone(str):
    """
    Get the permutations of an input string that
    don't have consecutive repeat letters.
    For example, cbc has permutations: cbc, cbc,
    ccb, ccb, bcc, bcc. Only cbc and cbc have no
    repeat letters, so 2 is returned.

    Runtime is O(n*n!) where n is the length of the
    string.
    permutations is O(n*n!),
    so the total is O(n*n! + n!) which is just
    iterating over the permutations is n!,
    O(n*n!)

    Arguments:
        str: The string to compute this special
        type of permutation count.
    
    Returns:
        the number of permutations containing
        no repeat letters. 
    """
    # Let's get all the permutation for this
    # string. This is the difficult part
    # of the algorithm
    perms = permutations(str)
    
    # Simply count how many of the permutations
    # don't contain any repeat characters. 
    count = 0
    for perm in perms:
        if not contains_repeats(perm): count += 1

    return count

def permutations(str):
    """Generates all the permutations of a given
    string.

    The runtime is O(n*n!) where n is the length of
    the string.
    Outer loop runs (n-1).
    Middle loop runs (n-1)!
    Inner loop runs (n).
    (n-1) * (n-1)! * (n) = (n-1) * n!
    = n*n! - n! = O(n*n!). 

    Arguments:
        str: The string to find the permutations of
    
    Returns:
        An array of permutations of the given string.
    """
    # Store all the partial permutations
    partial_perms = [str]

    # For a 4 length string, the partial
    # permutations will be of size 1 -> 2 -> 3
    for i in range(len(str) - 1):
        # Since we shouldn't modify the length of
        # partial_perms while iterating over it,
        # create a temporary variable to hold the
        # next iteration of partial permutations.
        temp = []

        # Basically, switch the character in
        # position i with the character at
        # position k, and this will be a new
        # permutation. You have to do this for
        # all partial permutations (j).
        for j in range(len(partial_perms)):
            current_perm = partial_perms[j]
            for k in range(i, len(current_perm)):
                # To swap characters it's easiest
                # to turn the string into an
                # array and perform a swap that way.
                new_perm = list(current_perm)
                temp_char = new_perm[k]
                new_perm[k] = new_perm[i]
                new_perm[i] = temp_char
                temp.append(''.join(new_perm))
        
        partial_perms = temp

    return partial_perms

def contains_repeats(str):
    """Determines if a string has repeat letters.
 
    This function is worst case O(n) because it
    must at worst check each character in the
    string. n is the length of the string.
    
    Arguments:
        str: the string to examine for
        repeat letters

    Returns:
        True if the string contains at least
        one repeat, False otherwise 
    """
    for i in range(1, len(str)):
        if str[i] == str[i-1]:
            return True

    return False

print(perm_alone("dabc"))