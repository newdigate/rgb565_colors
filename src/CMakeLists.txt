cmake_minimum_required(VERSION 3.5)
project(rgb565_colors C CXX)
set(rgb565_colors_VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

option(OPT_BUILD_FOR_LINUX "Build for linux emulator" ON)
if (OPT_BUILD_FOR_LINUX)
	set(BUILD_FOR_LINUX 1)
endif()

#set(SOURCE_FILES TFTPianoDisplay.cpp)

set(HEADER_FILES
		rgb565_colors.h
		rgb565_alphaBlend.h)

if (DEFINED BUILD_FOR_LINUX)


	include(CMakeLists.linux.cmake.in)
	add_custom_target(installarduino
			"${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/install_arduino_library.cmake")
else()
	include(CMakeLists.teensy.cmake.in)
endif()