cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(CMakeCM ROLLING)

include(cotire)

add_executable(dummy-program main.cpp)

cotire(dummy-program)
