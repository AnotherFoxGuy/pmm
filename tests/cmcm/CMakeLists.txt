cmake_minimum_required(VERSION 3.25)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(CMakeCM ROLLING)

include(CMakeRC)

cmrc_add_resource_library(test ALIAS test::rc test.txt)

add_executable(test-program main.cpp)
target_link_libraries(test-program PRIVATE test::rc)
