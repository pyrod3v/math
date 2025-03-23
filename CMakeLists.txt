cmake_minimum_required(VERSION 3.10)

project(fib LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Os -Wall -pipe)

set(SRCDIR ${CMAKE_SOURCE_DIR}/src)
set(BINDIR ${CMAKE_BINARY_DIR}/bin)

find_library(GMP_LIBRARY NAMES gmp libgmp)
if(NOT GMP_LIBRARY)
    message(FATAL_ERROR "GMP library not found. Please install libgmp-dev or equivalent.")
endif()

add_executable(fib EXCLUDE_FROM_ALL
    ${SRCDIR}/fib.c
)
set_target_properties(fib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BINDIR}
)
target_link_libraries(fib PRIVATE ${GMP_LIBRARY})