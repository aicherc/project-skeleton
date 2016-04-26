find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(rectangle_test RectangleTestSuite.cc
		${CMAKE_CURRENT_SOURCE_DIR}/RectangleTestSuite.h)
    target_link_libraries(rectangle_test rectangle)
endif()
