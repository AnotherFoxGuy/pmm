cmake_minimum_required(VERSION 3.25)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(CONAN DEBUG)

find_package(Catch2 REQUIRED CONFIG)

add_executable(test_exe main.cpp)
target_link_libraries(test_exe PRIVATE Catch2::Catch2WithMain)

add_test(test_exe test_exe)
