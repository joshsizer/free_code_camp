/**
 * Created on Fri May 7 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Sort the given sub-array using quick sort.
 * 
 * Runtime is O(nlog(n)) on average. Worst case
 * is O(n^2). Each partition call is order O(n).
 *
 * The number of partition calls will be about
 * log(n) with good choices of pivot. Random
 * pivots or static pivots on randomly ordered
 * datasets will tend to produce log(n) calls.
 * There are circumstances, though, where there
 * could be n partition calls, leading to the
 * O(n^2) runtime.
 * 
 * @param {Number[]} arr The array to sort.
 * @param {Number} low The beginning index of the sub-array.
 * @param {Number} high The ending index of the sub-array.
 * @returns The given array, arr, but sorted.
 */
function quickSort(arr, low, high) {
  // The first call to quickSort will likely not
  // have included low or high.
  if (typeof low === "undefined") {
    low = 0
  }
  if (typeof high === "undefined") {
    high = arr.length - 1
  }

  // If high is ever the same or less than low,
  // it means our subarray is of size 0 or 1, so
  // we just return.
  if (high - low <= 0) {
    return
  }

  // Using the high index as a pivot (the end of
  // the sub array), divide the array so that
  // everything to the left of the pivot is less
  // than the pivot, and everything to the right
  // of pivot is greater than the pivot.
  let partition_idx = partition(arr, low, high)

  // Recursively call quick_sort.
  quickSort(arr, low, partition_idx - 1)
  quickSort(arr, partition_idx + 1, high)

  return arr;
}

/**
 * Semi-orders the given sub-array around the
 * pivot value.
 *
 * The pivot value is the last element in the
 * sub-array. At the end of this call, each
 * element greater than pivot will come after
 * pivot, and every element smaller than pivot
 * will come before pivot.
 * 
 * @param {Number[]} arr The array to partition.
 * @param {Number} low The start index of the
 * sub-array.
 * @param {Number} high The end index of the
 * sub-array.
 * @returns arr where the given sub-array is
 * partitioned around the pivot.
 */
function partition(arr, low, high) {
  let pivot = high
  let left = low
  let right = high - 1

  while (true) {
    while (arr[left] < arr[pivot]) {
      left++
    }

    while (right > 0 && arr[right] > arr[pivot]) {
      right--
    }

    if (left >= right) {
      break
    } else {
      swap(arr, left, right)
    }
  }
  swap(arr, left, pivot)
  return left
}

/**
 * Switches the element at position i with the
 * element at position j in the given array.
 * 
 * @param {*} arr The array to swap elements.
 * @param {*} i The first index to swap.
 * @param {*} j The second index to swap.
 */
function swap(arr, i, j) {
  let temp = arr[i]
  arr[i] = arr[j]
  arr[j] = temp
}

module.exports = quickSort