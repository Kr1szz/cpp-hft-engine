
cmake_minimum_required(VERSION 3.20)

project(cpp_hft_engine
    VERSION 0.1.0
    DESCRIPTION "A beginner-friendly C++ matching engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executable for the exchange simulator
add_executable(hft_engine
    src/main.cpp
)

target_include_directories(hft_engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Compiler warnings
target_compile_options(hft_engine
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wshadow
)

# Enable testing
include(CTest)

if(BUILD_TESTING)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_order.cpp")
        add_executable(test_order
            tests/test_order.cpp
        )

        target_include_directories(test_order
            PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

        target_compile_options(test_order
            PRIVATE
                -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wshadow
        )

        add_test(
            NAME order_model_test
            COMMAND test_order
        )
    endif()
endif()
