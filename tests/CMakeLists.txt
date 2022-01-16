link_directories("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/ext/Catch2
)

add_executable(rounding_and_remainder rounding_and_remainder.cpp)

target_link_libraries(rounding_and_remainder
    catch_main
)