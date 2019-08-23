cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(CONAN DEBUG)

add_executable(dummy main.cpp)
target_link_libraries(dummy PRIVATE CONAN_PKG::Catch2)

add_test(dummy dummy)
