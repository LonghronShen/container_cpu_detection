cmake_minimum_required(VERSION 3.1)
project(container_cpu_detection C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Threads REQUIRED)

if(UNIX)
    find_package(DL REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 17 CACHE STRING "Set to 11 or 14 to enable C++11 or C++17 builds, respectively." FORCE)
set(CMAKE_C_STANDARD 11 CACHE STRING "Set to 99 or 11 to enable C99 or C11 builds, respectively." FORCE)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

add_compile_definitions("__STDC_WANT_LIB_EXT1__=1")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(UNIX)
    if(APPLE)
        message(FATAL_ERROR "Mac OS X is not supported.")
    else()
        add_compile_options("-fPIC" )
        if(CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
            add_compile_options("-m64" "-march=westmere")
        endif()
    endif()
else()
    message(FATAL_ERROR "Not supported OS: Linux only.")
endif()

add_subdirectory(src)
