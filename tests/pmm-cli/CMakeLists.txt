cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(PMM_ALWAYS_DOWNLOAD TRUE)
set(PMM_URL "file://${PROJECT_SOURCE_DIR}/../../pmm")
set(PMM_DEBUG TRUE)

include(../../pmm.cmake)

pmm()


if (WIN32)
    set(PMM_CLI_COMMAND "${CMAKE_BINARY_DIR}/pmm-cli.bat")
else ()
    set(PMM_CLI_COMMAND "${CMAKE_BINARY_DIR}/pmm-cli.sh")
endif ()


add_custom_target(
        pmm_help
        ALL
        COMMAND ${PMM_CLI_COMMAND} /Help
        VERBATIM COMMENT "Testing help command"
)

add_custom_target(
        conan_install
        ALL
        COMMAND ${PMM_CLI_COMMAND} /Conan /Install
        VERBATIM COMMENT "Testing Conan Install command"
)

add_custom_target(
        conan_version
        ALL
        COMMAND ${PMM_CLI_COMMAND} /Conan /Version
        DEPENDS conan_install
        VERBATIM COMMENT "Testing Conan Version command"
)
