add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/)
include_directories(${gtest_SOURCE_DIR}/include ${test_SOURCE_DIR})


set(SOURCE_TEST_FILES runAllTests.cpp
        ShoppinItemTest.cpp
        ShoppingListTest.cpp
        ShoppingListFixture.cpp
        UserTest.cpp
        UserFixture.cpp
)
add_executable(runAllTests.cpp ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests.cpp gtest gtest_main core)