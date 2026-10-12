cmake_minimum_required(VERSION 3.20)

project(cpp_hft_engine
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(project_options INTERFACE)

target_compile_options(project_options INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)

add_library(hft_core
    src/OrderBook.cpp
)

target_include_directories(hft_core
    PUBLIC include
)

target_link_libraries(hft_core
    PRIVATE project_options
)

add_executable(hft_engine
    src/main.cpp
)

target_link_libraries(hft_engine
    PRIVATE hft_core project_options
)

enable_testing()

add_executable(test_order
    tests/test_order.cpp
)

target_include_directories(test_order
    PRIVATE include
)

target_link_libraries(test_order
    PRIVATE project_options
)

add_test(
    NAME order_model_test
    COMMAND test_order
)

add_executable(test_order_book
    tests/test_order_book.cpp
)

target_link_libraries(test_order_book
    PRIVATE hft_core project_options
)

add_test(
    NAME order_book_test
    COMMAND test_order_book
)