"""
Created on Tue May 4 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from bubble_sort import bubble_sort

class TestBubbleSort:
    """Test bubble sort"""

    def test_bubble_sort1(self):
        assert (bubble_sort([873, -3, -988, -49, -916, -552, -966, 830, -389, -539]) 
                == [-988, -966, -916, -552, -539, -389, -49, -3, 830, 873])

    def test_bubble_sort2(self):
        assert (bubble_sort([-672, 139, -537, 832, 968, 625, -907, 683, -401, 728])
                == [-907, -672, -537, -401, 139, 625, 683, 728, 832, 968])

    def test_bubble_sort3(self):
        assert (bubble_sort([-624, 251, -107, -412, -836, -260, 603, 47, -837, -997])
                == [-997, -837, -836, -624, -412, -260, -107, 47, 251, 603])

    def test_bubble_sort4(self):
        assert (bubble_sort([-372, 926, 466, 37, -839, -380, -647, -63, -206, -967])
                == [-967, -839, -647, -380, -372, -206, -63, 37, 466, 926])