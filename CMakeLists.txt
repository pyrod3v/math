cmake_minimum_required(VERSION 3.10)

project(math LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Os -mavx2 -mfma -Wall -pipe)

set(BIN ${CMAKE_BINARY_DIR}/bin)

find_library(GMP_LIBRARY NAMES gmp libgmp)
if(NOT GMP_LIBRARY)
    message(FATAL_ERROR "GMP library not found. Please install libgmp-dev or equivalent.")
endif()

add_executable(fib EXCLUDE_FROM_ALL
    ${CMAKE_SOURCE_DIR}/fib/fib.c
)
set_target_properties(fib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN}
)
add_executable(sqr EXCLUDE_FROM_ALL
    ${CMAKE_SOURCE_DIR}/sqr/test.c
        sqr/sqr.c
        sqr/sqr.h
)
set_target_properties(sqr PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN}
)
target_link_libraries(fib PRIVATE ${GMP_LIBRARY})