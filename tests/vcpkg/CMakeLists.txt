cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm(VCPKG
    REVISION e792d1c171a18d32401db0f95251515cc15056f5
    REQUIRES catch2
    DEBUG
    )

find_package(Catch2 CONFIG REQUIRED)

add_executable(dummy main.cpp)
target_link_libraries(dummy PRIVATE Catch2::Catch2)
