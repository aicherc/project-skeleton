

import unittest

class TestSecondMethods(unittest.TestCase):

    def test_equal(self):
        self.assertEqual(2, 2)
    
    def test_false(self):
        self.assertFalse(1 == 2)

    def test_true(self):
        self.assertTrue(2 == 2)
    
if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestSecondMethods)
    unittest.TextTestRunner(verbosity = 2).run(suite)

