cmake_minimum_required(VERSION 3.10)
project(yocto-build)

find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)

add_subdirectory(lib-display)

include_directories(lib-display
    ${GLIB_INCLUDE_DIRS}
)

link_directories(${GLIB_LIBRARY_DIRS})

add_executable(exec main.cpp)

target_link_libraries(exec ldisplay ${GLIB_LIBRARIES})
