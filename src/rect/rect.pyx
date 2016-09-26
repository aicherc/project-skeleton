# distutils: language = c++
# distutils: sources = cython/src/rectangle.cpp

# ^ distutils lines are important (do not delete)

# Pythonic redefinition of rectangle class header for Cython
cdef extern from "../cython/src/rectangle.h" namespace "shapes":
    cdef cppclass Rectangle:
        Rectangle() except+
        Rectangle(int, int, int, int) except+
        Rectangle operator+(Rectangle)
        int x0, y0, x1, y1
        int getLength()
        int getHeight()
        int getArea()
        void move(int, int)

# Definition of python class
cdef class CRectangle:
    """ CRectangle DocString

    Attributes:
      x0 - (int)
      y0 - (int)
      x1 - (int)
      y1 - (int)

    Warning inappropriate types (e.g. doubles) are converted to int.

    """
    cdef Rectangle _rectangle

    def __init__(self, x0=0, y0=0, x1=0, y1=0):
        self._rectangle = Rectangle(x0, y0, x1, y1)

    @staticmethod
    cdef create(Rectangle r):
        ret = CRectangle()
        ret._rectangle = r
        return ret

    def __repr__(self):
        """ String representation of CRectangle """
        rep = "CRectangle: \n"
        rep += "x0 = " + str(self._rectangle.x0) + "\n"
        rep += "y0 = " + str(self._rectangle.y0) + "\n"
        rep += "x1 = " + str(self._rectangle.x1) + "\n"
        rep += "y1 = " + str(self._rectangle.y1) + "\n"
        return rep

    def __add__(CRectangle left, CRectangle right):
        """ Rectangle Addition """
        answer = CRectangle.create(left._rectangle + right._rectangle)
        return answer

    def getLength(self):
        """ getLength docstring """
        return self._rectangle.getLength()

    def getHeight(self):
        """ getHeight docstring """
        return self._rectangle.getHeight()

    def getArea(self):
        """ getArea docstring """
        return self._rectangle.getArea()

    def move(self, dx, dy):
        """ move docstring """
        self._rectangle.move(dx, dy)

    property x0:
        # Expose the public member x0
        def __get__(self):
            return self._rectangle.x0
        def __set__(self, value):
            self._rectangle.x0 = <int>value

    property y0:
        # Expose the public member y0
        def __get__(self):
            return self._rectangle.y0
        def __set__(self, value):
            self._rectangle.y0 = <int>value

    property x1:
        # Expose the public member x1
        def __get__(self):
            return self._rectangle.x1
        def __set__(self, value):
            self._rectangle.x1 = <int>value

    property y1:
        # Expose the public member y1
        def __get__(self):
            return self._rectangle.y1
        def __set__(self, value):
            self._rectangle.y1 = <int>value



