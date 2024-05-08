cmake_minimum_required(VERSION 3.10)
project(yocto-build)

find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GLIB REQUIRED glib-2.0)
# PKG_CHECK_MODULES(SDL2 REQUIRED libsdl2)

add_subdirectory(lib-display)
add_subdirectory(lib-win)

include_directories(
    lib-display
    lib-win
    ${GLIB_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

link_directories(${GLIB_LIBRARY_DIRS} ${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS})

add_executable(exec main.cpp Application.h Application.cpp)

target_link_libraries(exec ldisplay lwin ${GLIB_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
