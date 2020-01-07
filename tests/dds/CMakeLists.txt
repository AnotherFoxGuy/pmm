cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)
pmm(DDS)

if(NOT EXISTS "${PROJECT_BINARY_DIR}/INDEX.lmi")
    message(FATAL_ERROR "No INDEX.lmi was generated")
endif()