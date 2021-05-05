/**
 * Created on Wed May 5 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Sort the given array using selection sort.
 * 
 * @param {Number[]} arr The array to sort.
 * @returns The same array, arr, but sorted in
 *          increasing order.
 */
function selectionSort(arr) {
    // The array is separated into the sorted
    // section, with indices less than i, and the
    // unsorted, with indices greater than or
    // equal to i. Each pass of the array finds
    // the minimum in the unsorted section, and
    // appends it to the end of the sorted section.
    for (let i = 0; i < arr.length - 1; i++) {
        let min_idx = i
        for (let j = i + 1; j < arr.length; j++) {
          if (arr[j] < arr[min_idx]) {
            min_idx = j
          }
        }
        let temp = arr[i]
        arr[i] = arr[min_idx]
        arr[min_idx] = temp
    }
    return arr;
}

module.exports = selectionSort;