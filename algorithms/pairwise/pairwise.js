/**
 * Created on Mon May 3 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Get the sum of all index pairs, where the
 * values at the index pairs add up to arg. For
 * example, pairwise([1, 4, 2, 3, 0, 5], 7) finds
 * the index pairs [1, 3] because arr[1] + arr[3]
 * = 7 as well as index pairs [2, 5] because
 * arr[2] + arr[5] = 7. The total sum of all index
 * pairs is 1 + 3 + 2 + 5 = 11.
 *       
 * @param {Number[]} arr an array of numbers
 * @param {Number} arg the target sum to look for
 * @returns The total sum of all index pairs,
 *          where each index pair's values add up
 *          to arg.
 */
function pairwise(arr, arg) {
    // We keep a running sum and an auxillary array
    // to keep track of which indices have already
    // been used in an index pair.
    let idx_sum = 0
    let taken = []
    for (let i = 0; i < arr.length; i++) {
      taken.push(false)
    }
    
    // Grab the first index pair.
    let {i,j} = pairwise_single(arr, arg, taken)
    
    // Sum of 0 is returned if no pairs were found
    // yet. Otherwise, we accumulate our index
    // pairs into idx_sum and update our auxillary
    // array.
    while (i != -1) {
      idx_sum += i + j

      // No index may be used in more than one
      // pair, so we have to mark which indices
      // have already been used.
      taken[i] = true
      taken[j] = true;

      // Try to find another index pair.
      ({i, j} = pairwise_single(arr, arg, taken))
    }
    return idx_sum
}
  
/**
 * Get a single index pair (i, j), where
 * arr[i] + arr[j] == arg. 
 * 
 * @param {Number[]} arr an array of numbers
 * @param {Number} arg the target sum to look for
 * @param {Boolean[]} taken 
 * @returns an array as long as arr designating
 *          if a particular index can be in a new
 *          index pair.
 */
function pairwise_single(arr, arg, taken) {
    let i, j

    // Compare the sum of every pair of values in
    // arr to arg, and return the first set of
    // indices where the pair of values add to arg.
    for (i = 0; i < arr.length; i++) {
        for (j = i + 1; j < arr.length; j++) {
          if (arr[i] + arr[j] == arg && taken[i] == false &&  taken[j] == false) {
              return {i, j}
          }
        }
    }

    // If no pair of values sum to arg, then we
    // indicate that with special value -1.
    return {i: -1, j: -1}
}

module.exports = pairwise