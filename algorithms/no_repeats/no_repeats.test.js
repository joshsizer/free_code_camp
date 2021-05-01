/*
 * Created on Fri Apr 30 2021
 *
 * Copyright (c) 2021 - Joshua Sizer
 *
 * This code is licensed under MIT license (see
 * LICENSE for details)
 */

const permAlone = require("./no_repeats")

test('permAlone("aab")', () => {
    expect(permAlone("aab")).toEqual(2)
})

test('permAlone("aabb")', () => {
    expect(permAlone("aabb")).toEqual(8)
})

test('permAlone("abcdefa")', () => {
    expect(permAlone("abcdefa")).toEqual(3600)
})

test('permAlone("abfdefa")', () => {
    expect(permAlone("abfdefa")).toEqual(2640)
})

test('permAlone("zzzzzzzz")', () => {
    expect(permAlone("zzzzzzzz")).toEqual(0)
})

test('permAlone("a")', () => {
    expect(permAlone("a")).toEqual(1)
})

test('permAlone("aaab")', () => {
    expect(permAlone("aaab")).toEqual(0)
})

test('permAlone("aaabb")', () => {
    expect(permAlone("aaabb")).toEqual(12)
})