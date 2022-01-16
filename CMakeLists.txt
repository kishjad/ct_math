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
set(LIB_OUTPUT_PATH ${BUILD_OUTPUT_PATH}/lib)

file(MAKE_DIRECTORY ${BUILD_OUTPUT_PATH})
file(MAKE_DIRECTORY ${LIB_OUTPUT_PATH})

#

# file(STRINGS "${GCEM_INCLUDE_DIR}/gcem_incl/gcem_options.hpp" gcem_version_defines
#      REGEX "#define GCEM_VERSION_(MAJOR|MINOR|PATCH)")

# foreach(ver ${gcem_version_defines})
#     if(ver MATCHES "#define GCEM_VERSION_(MAJOR|MINOR|PATCH) +([^ ]+)$")
#         set(GCEM_VERSION_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
#     endif()
# endforeach()

# set(${PROJECT_NAME}_VERSION
#     ${GCEM_VERSION_MAJOR}.${GCEM_VERSION_MINOR}.${GCEM_VERSION_PATCH})
# message(STATUS "GCE-Math version ${${PROJECT_NAME}_VERSION}")

#

if(NOT MSVC)
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
    
    if(COMPILER_SUPPORTS_CXX17)
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has C++17 support.")
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_CXX_COMPILER} "
            "CT_MATH requires a C++11-compatible compiler.")
    endif()
endif()


## Enable and run tests
## enable with `cmake -DCT_MATH_TESTS`
# OPTION(CT_MATH_TESTS "test suite" OFF)


# add_library(ct_math INTERFACE)
# target_include_directories(gcem INTERFACE $<BUILD_INTERFACE:${CT_MATH_INCLUDE}>
#                                           $<INSTALL_INTERFACE:include>)

# if(CT_MATH_TESTS)
#     add_subdirectory(tests)
# endif()

# #

# include(CMakePackageConfigHelpers)
# include(GNUInstallDirs)

# install(
#     TARGETS gcem
#     EXPORT ${PROJECT_NAME}-targets
# )

# export(EXPORT ${PROJECT_NAME}-targets
#        FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

# install(DIRECTORY ${GCEM_INCLUDE_DIR}/
#         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# #

# set(GCEM_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for gcemConfig.cmake")

# configure_package_config_file(cmake_files/${PROJECT_NAME}Config.cmake.in
#                               "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
#                               INSTALL_DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})

# write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
#                                  VERSION ${${PROJECT_NAME}_VERSION}
#                                  COMPATIBILITY SameMajorVersion)

# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
#               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
#         DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})

# install(EXPORT ${PROJECT_NAME}-targets
#         FILE ${PROJECT_NAME}Targets.cmake
#         DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})