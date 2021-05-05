"""
Created on Wed May 5 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from selection_sort import selection_sort

class TestSelectionSort:
    """Test the selection_sort function."""

    def test_selection_sort1(self):
        assert (selection_sort([95, 521, -179, 606, -78, -547, 557, 682, 298, -417])
            == [-547, -417, -179, -78, 95, 298, 521, 557, 606, 682])

    def test_selection_sort2(self):
        assert (selection_sort([680, 295, 934, -883, -82, -293, 919, 784, -231, -943])
            == [-943, -883, -293, -231, -82, 295, 680, 784, 919, 934])

    def test_selection_sort3(self):
        assert (selection_sort([-812, -245, 117, -670, -926, -578, 837, -70, -243, 223]) 
            == [-926, -812, -670, -578, -245, -243, -70, 117, 223, 837])

    def test_selection_sort4(self):
        assert (selection_sort([871, 232, 800, 276, 95, 341, 358, -276, -962, 462])
            == [-962, -276, 95, 232, 276, 341, 358, 462, 800, 871])
