cmake_minimum_required(VERSION 3.10)
project(Studentai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(studentai main.cpp funkcijos.cpp zmogus.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_zmogus tests/test_zmogus.cpp zmogus.cpp funkcijos.cpp)
target_link_libraries(test_zmogus gtest)
add_test(NAME ZmogusTests COMMAND test_zmogus)

add_executable(test_studentas tests/test_studentas.cpp zmogus.cpp funkcijos.cpp)
target_link_libraries(test_studentas gtest)
add_test(NAME StudentasTests COMMAND test_studentas)