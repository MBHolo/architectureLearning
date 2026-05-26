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

# --- БИБЛИОТЕКА MathFunc ---
add_library(MathFuncLib
    src/MathFunc/MathFunc.cpp
)
target_include_directories(MathFuncLib PUBLIC src)

# --- БИБЛИОТЕКА SpaceSShipMove ---
add_library(MovingObject
    "src/SpaceBattle/Move/MovingObject.cpp"
    "src/SpaceBattle/Move/RotatingObject.cpp"
    "src/SpaceBattle/Objects/SpaceShipObject.cpp"
)
target_include_directories(MovingObject PUBLIC src)

# --- ОСНОВНАЯ ПРОГРАММА ---
add_executable(${PROJECT_NAME}
    ArchitectureLearning/ArchitectureLearning.cpp
    src/MathFunc/MathFunc.cpp
    src/SpaceBattle/Move/MovingObject.cpp
    src/SpaceBattle/Move/RotatingObject.cpp
    src/SpaceBattle/Objects/SpaceShipObject.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    MathFuncLib
    MovingObject
)

# --- ТЕСТЫ ---
add_executable(myTestsMathFunc
    "tests/mathFunc/testMathFunc.cpp")

target_link_libraries(myTestsMathFunc PRIVATE
    MathFuncLib
    gtest_main
    gmock_main
)
target_include_directories(myTestsMathFunc PRIVATE src)

gtest_discover_tests(myTestsMathFunc)

add_executable(myTestsSpaceBattleMove
    "tests/spaceBattle/testSpaceBattleMove.cpp")

target_link_libraries(myTestsSpaceBattleMove PRIVATE
    MovingObject
    gtest_main
    gmock_main
)
target_include_directories(myTestsSpaceBattleMove PRIVATE src)

gtest_discover_tests(myTestsSpaceBattleMove)
