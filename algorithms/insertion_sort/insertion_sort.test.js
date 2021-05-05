/**
 * Created on Wed May 5 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Test the insertionSort function.
 */
const insertionSort = require("./insertion_sort")

test("insertionSort([583, -381, 457, -792, -956, -381, -249, -456, 935, 199])", () => {
    expect(insertionSort([583, -381, 457, -792, -956, -381, -249, -456, 935, 199])).toEqual([-956, -792, -456, -381, -381, -249, 199, 457, 583, 935])
})

test("insertionSort([-249, 366, 520, -35, -877, 512, -921, 597, 39, 980])", () => {
    expect(insertionSort([-249, 366, 520, -35, -877, 512, -921, 597, 39, 980])).toEqual([-921, -877, -249, -35, 39, 366, 512, 520, 597, 980])
})

test("insertionSort([-879, -846, 96, 389, -925, -191, 288, -892, -980, -637])", () => {
    expect(insertionSort([-879, -846, 96, 389, -925, -191, 288, -892, -980, -637])).toEqual([-980, -925, -892, -879, -846, -637, -191, 96, 288, 389])
})

test("insertionSort([910, -151, 861, 33, 803, 821, -659, -269, -974, -978])", () => {
    expect(insertionSort([910, -151, 861, 33, 803, 821, -659, -269, -974, -978])).toEqual([-978, -974, -659, -269, -151, 33, 803, 821, 861, 910])
})