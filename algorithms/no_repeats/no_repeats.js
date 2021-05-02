/*
 * Created on Fri Apr 30 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Get the permutations of an input string that
 * don't have consecutive repeat letters.
 *
 * For example, cbc has permutations: cbc, cbc,
 * ccb, ccb, bcc, bcc. Only cbc and cbc have no
 * repeat letters, so 2 is returned.
 * 
 * Runtime is O(n*n!) where n is the length of the
 * string.
 * permutations is O(n*n!),
 * iterating over the permutations is n!,
 * so the total is O(n*n! + n!) which is just
 * O(n*n!)
 *
 * @param {String} str The string to compute this
 * special type of permutation count.
 * @returns {Number} the number of permutations containing
 * no repeat letters. 
 */
function permAlone(str) {
    // Let's get all the permutation for this
    // string. This is the difficult part
    // of the algorithm
    let perms = permutations(str)

    // Simply count how many of the permutations
    // don't contain any repeat characters. 
    let count = 0;
    for (let i = 0; i < perms.length; i++) {
        if (!containsRepeats(perms[i])) {
            count++;
        }
    }

    return count
}


/**
 * Generates all the permutations of a given
 * string.
 * 
 * The runtime is O(n*n!) where n is the length of
 * the string.
 * Outer loop runs (n-1).
 * Middle loop runs (n-1)!
 * Inner loop runs (n)
 * (n-1) * (n-1)! * (n) = (n-1) * n!
 * = n*n! - n! = O(n*n!). 
 *
 * @param {String} str The string to find the
 * permutations of
 * @return {String[]}An array of permutations of the given string.
 */
function permutations(str) {
    // Store all the partial permutations
    let partial_perms = [str]

    // For a 4 length string, the partial
    // permutations will be of size 1 -> 2 -> 3
    for (let i = 0; i < str.length - 1; i++) {
        // Since we shouldn't modify the length of
        // partial_perms while iterating over it,
        // create a temporary variable to hold the
        // next iteration of partial permutations.
        let temp = []

        // Basically, switch the character in
        // position i with the character at
        // position k, and this will be a new
        // permutation. You have to do this for
        // all partial permutations (j).
        for (let j = 0; j < partial_perms.length; j++) {
            let current_perm = partial_perms[j]
            for (let k = i; k < current_perm.length; k++) {
                // To swap characters it's easiest
                // to turn the string into an
                // array and perform a swap that way.
                let new_perm = current_perm.split('');
                let temp_char = new_perm[k];
                new_perm[k] = new_perm[i]
                new_perm[i] = temp_char
                temp.push(new_perm.join(''));
            }
        }
        partial_perms = temp
    }

    return partial_perms
}

/**
 * Determines if a string has repeat letters.
 * 
 * This function is worst case O(n) because it
 * must at worst check each character in the
 * string. n is the length of the string.
 * 
 * @param {String} str The string to examine for
 * repeat letters
 * @return true if the string contains at least
 * one repeat, false otherwise 
 */
function containsRepeats(str) {
    for (let i = 1; i < str.length; i++) {
        if (str[i] === str[i - 1]) {
            return true
        }
    }
    return false
}

module.exports = permAlone;
console.log(permAlone("aab"));