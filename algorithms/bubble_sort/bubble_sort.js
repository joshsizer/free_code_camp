/**
 * Created on Tue May 4 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Sort the array using bubble sort.
 * 
 * Runtime is O(n^2).
 * 
 * @param {Number[]} arr The array to sort.
 * @returns The array, but sorted.
 */
function bubbleSort(arr) {
    // I would normally comment, but it's bubble
    // sort.
    for (let i = 0; i < arr.length; i++) {
        // The only thing of note is that we
        // optimize it a little. Each iteration,
        // the next highest value is bubbled to
        // the sorted section. We stop looking at
        // the elements we've already bubbled into
        // sorted position.
        for (let j = 1; j < arr.length - i; j++) {
          if (arr[j] < arr[j-1]) {
            let temp = arr[j]
            arr[j] = arr[j-1]
            arr[j-1] = temp
          }
        }
      }
      return arr;
}

module.exports = bubbleSort;