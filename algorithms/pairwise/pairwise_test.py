"""
Created on Mon May 3 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from pairwise import pairwise

class TestPairwise:

    def test_pairwise1(self):
        assert pairwise([1, 4, 2, 3, 0, 5], 7) == 11

    def test_pairwise2(self):
        assert pairwise([1, 3, 2, 4], 4) == 1

    def test_pairwise3(self):
        assert pairwise([1, 1, 1], 2) == 1

    def test_pairwise4(self):
        assert pairwise([0, 0, 0, 0, 1, 1], 1) == 10
        
    def test_pariwise5(self):
        assert pairwise([], 100) == 0