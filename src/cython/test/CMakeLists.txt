find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    # rectangle test
    CXXTEST_ADD_TEST(rectangle_test RectangleTestSuite.cc
		${CMAKE_CURRENT_SOURCE_DIR}/RectangleTestSuite.h)
    target_link_libraries(rectangle_test rectangle)
    # eigen_ex test
    CXXTEST_ADD_TEST(eigen_ex_test eigen_ex_test.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/eigen_ex_test.h)
    target_link_libraries(eigen_ex_test eigen_ex)
endif()
