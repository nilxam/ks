project(ks)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(Qt4 REQUIRED)

add_definitions(${QT_DEFINITIONS})

set(LIB_SUFFIX "" CACHE STRING "Define suffix for lib directory (32/64)")

set(BIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/bin)
set(LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX})

add_subdirectory(liburfkill-qt)
add_subdirectory(ks)

