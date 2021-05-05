/**
 * Created on Wed May 5 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/**
 * Test the selection sort function.
 */
const selectionSort = require("./selection_sort")

test("selectionSort([95, 521, -179, 606, -78, -547, 557, 682, 298, -417]", () => {
    expect(selectionSort([95, 521, -179, 606, -78, -547, 557, 682, 298, -417])).toEqual([-547, -417, -179, -78, 95, 298, 521, 557, 606, 682])
})

test("selectionSort([680, 295, 934, -883, -82, -293, 919, 784, -231, -943])", () => {
    expect(selectionSort([680, 295, 934, -883, -82, -293, 919, 784, -231, -943])).toEqual([-943, -883, -293, -231, -82, 295, 680, 784, 919, 934])
})

test("selectionSort([-812, -245, 117, -670, -926, -578, 837, -70, -243, 223])", () => {
    expect(selectionSort([-812, -245, 117, -670, -926, -578, 837, -70, -243, 223])).toEqual([-926, -812, -670, -578, -245, -243, -70, 117, 223, 837])
})

test("selectionSort([871, 232, 800, 276, 95, 341, 358, -276, -962, 462])", () => {
    expect(selectionSort([871, 232, 800, 276, 95, 341, 358, -276, -962, 462])).toEqual([-962, -276, 95, 232, 276, 341, 358, 462, 800, 871])
})