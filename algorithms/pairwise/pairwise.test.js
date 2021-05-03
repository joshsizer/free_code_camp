/**
 * Created on Mon May 3 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

const pairwise = require("./pairwise")

test("pairwise([1, 4, 2, 3, 0, 5], 7)", () => {
    expect(pairwise([1, 4, 2, 3, 0, 5], 7)).toEqual(11)
})

test("pairwise([1, 3, 2, 4], 4)", () => {
    expect(pairwise([1, 3, 2, 4], 4)).toEqual(1)
})

test("pairwise([1, 1, 1], 2)", () => {
    expect(pairwise([1, 1, 1], 2)).toEqual(1)
})

test("pairwise([0, 0, 0, 0, 1, 1], 1)", () => {
    expect(pairwise([0, 0, 0, 0, 1, 1], 1)).toEqual(10)
})

test("pairwise([], 100) == 0", () => {
    expect(pairwise([], 100)).toEqual(0)
})