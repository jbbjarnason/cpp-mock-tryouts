
# CppUTest
include(FetchContent)
FetchContent_Declare(
        CppUTest
        GIT_REPOSITORY https://github.com/cpputest/cpputest.git
        GIT_TAG        latest-passing-build # or use release tag, eg. v3.8
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)



add_executable(cppumock_test
    UnitTest1.cpp
    main.cpp
)
target_link_libraries(cppumock_test
    PRIVATE
        CppUTest
        CppUTestExt

        Smurf
)
