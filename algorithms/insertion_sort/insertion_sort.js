/**
 * Created on Wed May 5 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Sorts the given array using insertion sort.
 * 
 * Average/worst case is O(n^2).
 * Best case is O(n).
 *  
 * @param {Number[]} arr The array to sort.
 * @returns {Number[]} The array arr, but sorted.
 */
function insertionSort(arr) {
    // i keeps track of the end of the sorted
    // section. The element immediately after i is
    // moved into the correct position in the
    // sorted section by swapping it with its
    // previous element until it lands in the
    // correct place.
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = i + 1; j > 0; j--) {
          if (arr[j] < arr[j-1]) {
            let temp = arr[j]
            arr[j] = arr[j-1]
            arr[j-1] = temp
          } else {
            break
          }
        }
    }
    
    return arr;
}

module.exports = insertionSort;