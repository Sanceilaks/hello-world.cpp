cmake_minimum_required(VERSION 3.20)
project(hello_world_cpp)

set(vcpkg_path ${CMAKE_CURRENT_SOURCE_DIR}\\vcpkg\\)
if (NOT EXISTS ${vcpkg_path})
    message(FATAL_ERROR "First update submodules")
ENDIF()

message("-- Vcpkg path is ${vcpkg_path}")

IF (WIN32)
    if (NOT EXISTS ${vcpkg_path}vcpkg.exe)
        execute_process(
                COMMAND ${vcpkg_path}bootstrap-vcpkg.bat
        )
    ENDIF()
ELSE()
        if (NOT EXISTS ${vcpkg_path}vcpkg)
            execute_process(
                    COMMAND sh ${vcpkg_path}bootstrap-vcpkg.sh
            )
        ENDIF()
ENDIF()

message("Toolchain file is ${CMAKE_TOOLCHAIN_FILE}")

set(CMAKE_CXX_STANDARD 20)

add_executable(hello_world_cpp src/main.cpp src/hwcppstddef.h)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

target_link_libraries(hello_world_cpp PRIVATE nlohmann_json nlohmann_json::nlohmann_json spdlog::spdlog spdlog::spdlog_header_only)