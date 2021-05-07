/**
 * Created on Fri May 7 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Test the quickSort function
 */
const quickSort = require("./quick_sort")

test("quickSort([957, -785, 617, -38, -39, 266, 705, -651, -535, 438])", () => {
    expect(quickSort([957, -785, 617, -38, -39, 266, 705, -651, -535, 438])).toEqual([-785, -651, -535, -39, -38, 266, 438, 617, 705, 957])
})

test("quickSort([315, -927, 828, 437, 958, 951, -753, -98, -354, -292])", () => {
    expect(quickSort([315, -927, 828, 437, 958, 951, -753, -98, -354, -292])).toEqual([-927, -753, -354, -292, -98, 315, 437, 828, 951, 958])
})

test("quickSort([27, 295, -30, 911, -48, 623, -805, 695, 737, -894])", () => {
    expect(quickSort([27, 295, -30, 911, -48, 623, -805, 695, 737, -894])).toEqual([-894, -805, -48, -30, 27, 295, 623, 695, 737, 911])
})

test("quickSort([866, 988, 421, 609, -19, 686, -268, 434, -459, 800])", () => {
    expect(quickSort([866, 988, 421, 609, -19, 686, -268, 434, -459, 800])).toEqual([-459, -268, -19, 421, 434, 609, 686, 800, 866, 988])
})