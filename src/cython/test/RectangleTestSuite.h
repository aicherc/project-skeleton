// Rectangle Test Suite
#include <cxxtest/TestSuite.h>
#include <rectangle.h>

using namespace shapes;

class RectangleTestSuite : public CxxTest::TestSuite {
  public:
    void testDefault(void){
      TS_ASSERT(true);
    }

    void testAddOperator(void){
      Rectangle rect1 = Rectangle(0,0,1,1);
      Rectangle rect2 = Rectangle(0,1,1,3);

      auto rect_sum = rect1 + rect2;

      TS_ASSERT(rect_sum.x0 == 0);
      TS_ASSERT(rect_sum.y0 == 1);
      TS_ASSERT(rect_sum.x1 == 2);
      TS_ASSERT(rect_sum.y1 == 4);
    }

    void testGetLength(void){
      Rectangle rect1 = Rectangle(0,0,1,1);
      Rectangle rect2 = Rectangle(0,1,1,3);

      TS_ASSERT(rect1.getLength() == 1-0);
      TS_ASSERT(rect2.getLength() == 1-0);
    }

    void testGetHeight(void){
      Rectangle rect1 = Rectangle(0,0,1,1);
      Rectangle rect2 = Rectangle(0,1,1,3);

      TS_ASSERT(rect1.getHeight() == 1-0);
      TS_ASSERT(rect2.getHeight() == 3-1);
    }

    void testGetArea(void){
      Rectangle rect1 = Rectangle(0,0,1,1);
      Rectangle rect2 = Rectangle(0,1,1,3);

      TS_ASSERT(rect1.getArea() == (1-0)*(1-0));
      TS_ASSERT(rect2.getArea() == (1-0)*(3-1));
    }

};
