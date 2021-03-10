cmake_minimum_required(VERSION 3.10)
project(arduino_tftpianoview_example)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES palettes.cpp)
set(APP_NAME palettes)

option(OPT_BUILD_FOR_LINUX "Build the example for linux" ON)
option(OPT_BUILD_FOR_OPENGL_EMULATOR "Build the example for linux/opengl" ON)
option(OPT_BUILD_EXAMPLES_USING_INSTALLED_LIB "Build examples using installed teensy-libcurve" ON)

if (OPT_BUILD_FOR_LINUX)
    add_definitions(-DBUILD_FOR_LINUX)
    message(STATUS "BUILD_FOR_LINUX: Build the example for linux is ON")
    set(APP_SOURCES ${SOURCE_FILES})

    find_package(teensy_x86_stubs)
    include_directories(${teensy_x86_stubs_INCLUDE_DIR})

    find_package(teensy_st7735_linux_stubs)
    include_directories(${teensy_st7735_linux_stubs_INCLUDE_DIR})

    if (OPT_BUILD_FOR_OPENGL_EMULATOR)
        add_definitions(-DBUILD_FOR_OPENGL_EMULATOR)
        message(STATUS "BUILD_FOR_OPENGL_EMULATOR: Build the example for linux/opengl emulator is ON")
        include(../../cmake/opengl.cmake.in)
        find_package(teensy_st7735_linux_opengl)
        include_directories(${teensy_st7735_linux_extras_opengl_INCLUDE_DIR})
    endif()

    if (OPT_BUILD_EXAMPLES_USING_INSTALLED_LIB)
        message(STATUS "BUILD_EXAMPLES_USING_INSTALLED_LIB: Build the example for linux/opengl emulator using install teensy-libcurve is ON")
        find_package(rgb565_colors)
        include_directories(${rgb565_colors_INCLUDE_DIR})
    else()
        include_directories(../../src/)
        set(APP_SOURCES ${SOURCE_FILES} ../../src/TFTPianoDisplay.h ../../src/TFTPianoDisplay.cpp)
    endif()

    add_executable(${APP_NAME} ${APP_SOURCES})

    target_link_libraries(${APP_NAME} ${teensy_x86_stubs_LIBS})
    target_link_libraries(${APP_NAME} ${teensy_st7735_linux_stubs_LIBS})
    if (OPT_BUILD_FOR_OPENGL_EMULATOR)
        target_link_libraries(${APP_NAME} ${teensy_st7735_linux_extras_opengl_LIBS} ${LIBS})
    endif()
    if (OPT_BUILD_EXAMPLES_USING_INSTALLED_LIB)
        message(STATUS "OPT_BUILD_EXAMPLES_USING_INSTALLED_LIB: ${arduino_tftpianoview_LIBS}")
        target_link_libraries(${APP_NAME} ${arduino_tftpianoview_LIBS})
    endif()
else()

    include(../../teensy.options.cmake.in)
    include(../../teensy.build.cmake.in)
    include(../examples.cmake.in)

    import_arduino_library(${DEPSPATH} midi-smf-reader/src)
    import_arduino_library(${DEPSPATH} teensy-quencer/src)

    teensy_add_executable(arduino_tftpianoview_example_basic
            ${SOURCE_FILES})
endif()