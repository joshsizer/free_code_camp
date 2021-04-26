/*
 * Created on Sun Apr 25 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

/*
 * Test the symmetric difference function.
 */
const sym = require("./symmetric_difference")

test("sym([1, 2, 3], [5, 2, 1, 4])", () => {
    expect(sym([1, 2, 3], [5, 2, 1, 4]).sort()).toEqual([3, 4, 5].sort())
})

test("sym([1, 2, 3, 3], [5, 2, 1, 4])", () => {
    expect(sym([1, 2, 3, 3], [5, 2, 1, 4]).sort()).toEqual([3, 4, 5].sort())
})

test("sym([1, 2, 3], [5, 2, 1, 4, 5])", () => {
    expect(sym([1, 2, 3], [5, 2, 1, 4, 5]).sort()).toEqual([3, 4, 5].sort())
})

test("sym([1, 2, 5], [2, 3, 5], [3, 4, 5])", () => {
    expect(sym([1, 2, 5], [2, 3, 5], [3, 4, 5]).sort()).toEqual([1, 4, 5].sort())
})

test("sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5])", () => {
    expect(sym([1, 2, 5], [2, 3, 5], [3, 4, 5]).sort()).toEqual([1, 4, 5].sort())
})

test("sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3])", () => {
    expect(sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3]).sort()).toEqual([2, 3, 4, 6, 7].sort())
})

test("sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1])", () => {
    expect(sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1]).sort()).toEqual([1, 2, 4, 5, 6, 7, 8, 9].sort())
})