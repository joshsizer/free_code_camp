"""
Created on Fri May 7 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from merge_sort import merge_sort

class TestMergeSort:
    """Test the merge_sort function"""

    def test_merge_sort1(self):
        assert merge_sort([-530, 13, 593, -41, 66, 727, -259, -517, 851, -231]) == [-530, -517, -259, -231, -41, 13, 66, 593, 727, 851]

    def test_merge_sort2(self):
        assert merge_sort([-111, 530, 761, -294, 671, 595, -109, 425, 685, 817]) == [-294, -111, -109, 425, 530, 595, 671, 685, 761, 817]

    def test_merge_sort3(self):
        assert merge_sort([-919, -661, 263, -329, -672, -680, 629, 708, 717, 586]) == [-919, -680, -672, -661, -329, 263, 586, 629, 708, 717]

    def test_merge_sort4(self):
        assert merge_sort([459, 129, 954, 179, 813, -769, -463, -218, 965, 882]) == [-769, -463, -218, 129, 179, 459, 813, 882, 954, 965]