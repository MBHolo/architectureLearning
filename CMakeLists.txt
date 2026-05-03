cmake_minimum_required(VERSION 3.14)
project(ArchitectureLearning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# --- БИБЛИОТЕКА (один раз) ---
add_library(MathFuncLib
    src/MathFunc/MathFunc.cpp
)
target_include_directories(MathFuncLib PUBLIC src)

# --- ОСНОВНАЯ ПРОГРАММА ---
add_executable(${PROJECT_NAME}
    ArchitectureLearning/ArchitectureLearning.cpp
    src/MathFunc/MathFunc.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE MathFuncLib)

# --- ТЕСТЫ ---
add_executable(myTests
    test.cpp
)
target_link_libraries(myTests PRIVATE
    MathFuncLib
    gtest_main
    gmock_main
)
target_include_directories(myTests PRIVATE src)

gtest_discover_tests(myTests)