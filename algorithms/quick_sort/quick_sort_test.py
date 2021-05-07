"""
Created on Thu May 6 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from quick_sort_recursive import quick_sort as qsr
from quick_sort_iterative import quick_sort as qsi

class TestQuickSort:
    """Test the quick_sort function"""

    def test_quick_sort_recursive1(self):
        assert (qsr([957, -785, 617, -38, -39, 266, 705, -651, -535, 438]) 
            == [-785, -651, -535, -39, -38, 266, 438, 617, 705, 957])
            
    def test_quick_sort_iterative1(self):
        assert (qsi([957, -785, 617, -38, -39, 266, 705, -651, -535, 438]) 
            == [-785, -651, -535, -39, -38, 266, 438, 617, 705, 957])

    def test_quick_sort_recursive2(self):
        assert (qsr([315, -927, 828, 437, 958, 951, -753, -98, -354, -292])
            == [-927, -753, -354, -292, -98, 315, 437, 828, 951, 958])
        
    def test_quick_sort_iterative2(self):
        assert (qsi([315, -927, 828, 437, 958, 951, -753, -98, -354, -292])
            == [-927, -753, -354, -292, -98, 315, 437, 828, 951, 958])

    def test_quick_sort_recursive3(self):
        assert (qsr([27, 295, -30, 911, -48, 623, -805, 695, 737, -894])
            == [-894, -805, -48, -30, 27, 295, 623, 695, 737, 911])
    
    def test_quick_sort_iterative3(self):
        assert (qsi([27, 295, -30, 911, -48, 623, -805, 695, 737, -894])
            == [-894, -805, -48, -30, 27, 295, 623, 695, 737, 911])

    def test_quick_sort_recursive4(self):
        assert (qsr([866, 988, 421, 609, -19, 686, -268, 434, -459, 800])
            == [-459, -268, -19, 421, 434, 609, 686, 800, 866, 988])
           
    def test_quick_sort_iterative4(self):
        assert (qsi([866, 988, 421, 609, -19, 686, -268, 434, -459, 800])
            == [-459, -268, -19, 421, 434, 609, 686, 800, 866, 988])
            