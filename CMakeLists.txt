project(ks)
cmake_minimum_required(VERSION 2.6)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
find_package(LibUrfkillQt REQUIRED)

include_directories(
    ${KDE4_INCLUDES} 
    ${LibUrfkillQt_INCLUDE_DIR}
)

# subdirs
add_subdirectory(src)
