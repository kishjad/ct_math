link_directories("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/ext/Catch2
)

add_executable(test_floor
    floor_test.cpp
)

target_link_libraries(test_floor
    catch_main
)