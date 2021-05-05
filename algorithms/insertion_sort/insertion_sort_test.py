"""
Created on Wed May 5 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from insertion_sort import insertion_sort

class TestInsertionSort:
    """Test the insertion sort function."""

    def test_insertion_sort1(self):
        assert (insertion_sort([583, -381, 457, -792, -956, -381, -249, -456, 935, 199]) 
            == [-956, -792, -456, -381, -381, -249, 199, 457, 583, 935])

    def test_insertion_sort2(self):
        assert (insertion_sort([-249, 366, 520, -35, -877, 512, -921, 597, 39, 980])
            == [-921, -877, -249, -35, 39, 366, 512, 520, 597, 980])

    def test_insertion_sort3(self):
        assert (insertion_sort([-879, -846, 96, 389, -925, -191, 288, -892, -980, -637])
            == [-980, -925, -892, -879, -846, -637, -191, 96, 288, 389])

    def test_insertion_sort4(self):
        assert (insertion_sort([910, -151, 861, 33, 803, 821, -659, -269, -974, -978])
            == [-978, -974, -659, -269, -151, 33, 803, 821, 861, 910])
