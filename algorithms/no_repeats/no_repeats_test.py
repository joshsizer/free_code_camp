"""
Created on Fri Apr 30 2021

Copyright (c) 2021 - Joshua Sizer

This code is licensed under MIT license (see
LICENSE for details)
"""

from no_repeats import perm_alone

class TestPermAlone:

    def test_perm_alone1(self):
        assert perm_alone("aab") == 2

    def test_perm_alone2(self):
        assert perm_alone("aabb") == 8

    def test_perm_alone3(self):
        assert perm_alone("abcdefa") == 3600

    def test_perm_alone4(self):
        assert perm_alone("abfdefa") == 2640

    def test_perm_alone5(self):
        assert perm_alone("zzzzzzzz") == 0

    def test_perm_alone6(self):
        assert perm_alone("a") == 1

    def test_perm_alone6(self):
        assert perm_alone("aaab") == 0

    def test_perm_alone6(self):
        assert perm_alone("aaabb") == 12