"""
Created on Sun Apr 25 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license
(see LICENSE for details)
"""

import unittest

from symmetric_difference import sym


class TestSym(unittest.TestCase):
    """Test the symmetric difference
    function.
    """

    def test_sym1(self):
        self.assertEqual(
            sym([1, 2, 3], [5, 2, 1, 4]).sort(),
            [3, 4, 5].sort(),
            "sym([1, 2, 3], [5, 2, 1, 4])",
        )

    def test_sym2(self):
        self.assertEqual(
            sym([1, 2, 3, 3], [5, 2, 1, 4]).sort(),
            [3, 4, 5].sort(),
            "sym([1, 2, 3, 3], [5, 2, 1, 4])",
        )

    def test_sym3(self):
        self.assertEqual(
            sym([1, 2, 3], [5, 2, 1, 4, 5]).sort(),
            [3, 4, 5].sort(),
            "sym([1, 2, 3], [5, 2, 1, 4, 5])",
        )

    def test_sym4(self):
        self.assertEqual(
            sym([1, 2, 5], [2, 3, 5], [3, 4, 5]).sort(),
            [1, 4, 5].sort(),
            "sym([1, 2, 5], [2, 3, 5], [3, 4, 5])",
        )

    def test_sym5(self):
        self.assertEqual(
            sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5]).sort(),
            [1, 4, 5].sort(),
            "sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5])",
        )

    def test_sym6(self):
        self.assertEqual(
            sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3]).sort(),
            [2, 3, 4, 6, 7].sort(),
            "sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3])",
        )

    def test_sym7(self):
        self.assertEqual(
            sym(
                [3, 3, 3, 2, 5],
                [2, 1, 5, 7],
                [3, 4, 6, 6],
                [1, 2, 3],
                [5, 3, 9, 8],
                [1],
            ).sort(),
            [1, 2, 4, 5, 6, 7, 8, 9].sort(),
            "sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1])",
        )


if __name__ == "__main__":
    unittest.main()
