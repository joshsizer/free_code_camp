/**
 * Created on Fri May 7 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Test the mergeSort function.
 */
const mergeSort = require("./merge_sort")

test("mergeSort([-530, 13, 593, -41, 66, 727, -259, -517, 851, -231])", () => {
    expect(mergeSort([-530, 13, 593, -41, 66, 727, -259, -517, 851, -231])).toEqual([-530, -517, -259, -231, -41, 13, 66, 593, 727, 851])
})

test("mergeSort([-111, 530, 761, -294, 671, 595, -109, 425, 685, 817])", () => {
    expect(mergeSort([-111, 530, 761, -294, 671, 595, -109, 425, 685, 817])).toEqual([-294, -111, -109, 425, 530, 595, 671, 685, 761, 817])
})

test("mergeSort([-919, -661, 263, -329, -672, -680, 629, 708, 717, 586])", () => {
    expect(mergeSort([-919, -661, 263, -329, -672, -680, 629, 708, 717, 586])).toEqual([-919, -680, -672, -661, -329, 263, 586, 629, 708, 717])
})

test("mergeSort([459, 129, 954, 179, 813, -769, -463, -218, 965, 882])", () => {
    expect(mergeSort([459, 129, 954, 179, 813, -769, -463, -218, 965, 882])).toEqual([-769, -463, -218, 129, 179, 459, 813, 882, 954, 965])
})