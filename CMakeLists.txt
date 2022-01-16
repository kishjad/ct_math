################################################################################
##
##   Copyright (C) 2022 Kish Jadhav
##
##   This file is part of the CT_MATH C++ library
##
##   Licensed under MIT License
##
################################################################################


cmake_minimum_required(VERSION 3.5)
project(ct_math)

set(CT_MATH_INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(BUILD_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

file(MAKE_DIRECTORY ${BUILD_OUTPUT_PATH})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


if(NOT MSVC)
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
    
    if(COMPILER_SUPPORTS_CXX17)
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has C++17 support.")
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_CXX_COMPILER} "
            "CT_MATH requires a C++17-compatible compiler.")
    endif()
endif()

add_library(ct_math INTERFACE)
target_include_directories(ct_math INTERFACE $<BUILD_INTERFACE:${CT_MATH_INCLUDE}>
                                          $<INSTALL_INTERFACE:include>)


# Enable and run tests
# enable with `cmake -DCT_MATH_TESTS`
OPTION(CT_MATH_TESTS "test suite" ON)

if(CT_MATH_TESTS)
    # add_subdirectory(tests)
    add_subdirectory(ext)
endif()
