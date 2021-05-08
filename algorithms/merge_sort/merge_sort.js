/**
 * Created on Fri May 7 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Sort the given array using merge sort.
 * 
 * Runtime average and best case is O(nlog(n)).
 * 
 * @param {Number[]} arr The array to sort.
 * @param {Number} low The beginning of the sub-array.
 * @param {Number} high The end of the sub-array.
 * @returns {Number[]} arr, but sorted.
 */
function mergeSort(arr, low, high) {
    // The first time merge_sort is called, high
    // and low will likely be undefined because
    // the user wants to sort the entire array.
    if (typeof low === "undefined") {
        low = 0
    }
    if (typeof high === "undefined") {
        high = arr.length - 1
    }

    // Base case of recursion.
    if (low >= high) {
        return
    }

    // Find the middle index of the array. In the
    // case of an odd-sized array, the left
    // sub-array will be bigger than the right
    // sub-array.
    let middle = Math.floor(low + ((high - low) / 2))

    // Sort the left and right sub-arrays
    mergeSort(arr, low, middle)
    mergeSort(arr, middle + 1, high)

    // Merge the left and right sub-arrays.
    merge(arr, low, middle, high)

    return arr;
}

/**
 * Merge the given sub-arrays into one larger
 * sub-array that is in correct order.
 * 
 * @param {Number[]} arr The array whose sections
 * should be merged.
 * @param {Number} low the start index of the
 * first sub-array.
 * @param {Number} middle the end index of the first
 * sub-array.
 * @param {Number} high The end index of the
 * second sub-array.
 * @returns {Number[]} arr, where the values in
 * indices low to high are in sorted order.
 */
function merge(arr, low, middle, high) {
    // Need auxillary array so that no information
    // is lost in the merging process.
    let left = arr.slice(low, middle + 1)
    let right = arr.slice(middle + 1, high + 1)

    // i is the current position in the left
    // sub-array. j is the current position in the
    // right sub-array. k is the current position
    // in the original array.
    let i = 0, j = 0
    let k = low

    // Exhaust all elements in the left or right
    // array by adding them to the original array
    // in sequential, ascending order.
    while (i < left.length && j < right.length) {
        let to_add = null
        if (left[i] < right[j]) {
            to_add = left[i++]
        } else {
            to_add = right[j++]
        }
        arr[k++] = to_add
    }

    // If the left sub-array still has elements,
    // add the remaining to the original array.
    while (i < left.length) {
        arr[k++] = left[i++]
    }

    // If the right sub-array still has elements,
    // add the remaining to the original array
    while (j < right.length) {
        arr[k++] = right[j++]
    }
}

module.exports = mergeSort