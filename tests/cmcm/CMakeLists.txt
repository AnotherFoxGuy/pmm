cmake_minimum_required(VERSION 3.25)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(CMakeCM ROLLING)

add_executable(dummy-program main.cpp example.cpp log.cpp log.h example.h)

cotire(dummy-program)
