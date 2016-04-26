#!/usr/bin/env python
"""
Unit Tests for PyRectangle
"""
# Author Information
__author__ = "Christopher Aicher"

# Import Modules
from rect import PyRectangle
import unittest


# Tests
class TestPyRectangle(unittest.TestCase):

    def test_equal(self):
        self.assertEqual(1, 1)

    def test_false(self):
        self.assertFalse(2 == 1)

    def test_true(self):
        self.assertTrue(1 == 1)

# Code to execute if called from command-line
if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestPyRectangle)
    unittest.TextTestRunner(verbosity=2).run(suite)

# EOF
