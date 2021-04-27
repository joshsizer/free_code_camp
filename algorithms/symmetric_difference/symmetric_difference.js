/*
 * Created on Sun Apr 25 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Return the symmetric difference of two or more
 * sets. If only one set is input, the same set is
 * returned unmodified. If no set is input, null
 * is returned.
 *
 * @param {...number[]} args n different sets,
 * @returns The symmetric difference of two or
 * more sets.
 */
function sym(args) {
    // Return null if arguments.length is 0
    if (arguments.length == 0) {
        return null
    }

    // Simulate recursion with a stack
    let stack = []

    // Add each argument (set) onto the stack
    for (var terms of arguments) {
        stack.push(terms)
    }

    // The first set to compare
    let current = stack.pop()

    // Compare sets until our stack is empty
    while (!(stack.length == 0)) {
        // Get the set to compare to current
        let to_compare = stack.pop()

        // Calulate the symmetric difference
        // between these two particular elements.
        current = sym_pairwise(current, to_compare)
    }

    return current;
}

/**
 * Return the symmetric difference of two sets. 
 *
 * @param {number[]} arg1 The first set in the
 * calculation
 * @param {number[]} arg2 The second set in the
 * calculation
 * @returns {number[]} The symmetric difference of
 * two sets.
 */
function sym_pairwise(arg1, arg2) {
    let result = []

    // Add each element in arg1 to result as long as
    // the element is not in arg2 and not already
    // in result.
    for (let element of arg1) {
        if (arg2.indexOf(element) < 0 && next.indexOf(element) < 0) {
            next.push(element)
        }
    }

    // Add each element in arg2 to result as long as
    // the element is not in arg1 and not already
    // in result.
    for (let element of arg2) {
        if (arg1.indexOf(element) < 0 && next.indexOf(element) < 0) {
            next.push(element)
        }
    }

    return result
}

module.exports = sym