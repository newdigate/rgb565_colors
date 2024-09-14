cmake_minimum_required(VERSION 3.5)
project(rgb565_colors C CXX)
set(rgb565_colors_VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

option(OPT_BUILD_FOR_LINUX "Build for linux emulator" ON)
if (OPT_BUILD_FOR_LINUX)
	set(BUILD_FOR_LINUX 1)
endif()

set(HEADER_FILES
		rgb565_colors.h
		rgb565_alphaBlend.h)

if (DEFINED BUILD_FOR_LINUX)
	add_library(rgb565_colors INTERFACE ${HEADER_FILES})
else()
	message("building for teensy...")
	include(../teensy.options.cmake.in)
	include(../teensy.build.cmake.in)
	teensy_add_library(
			rgb565_colors
			${HEADER_FILES})
endif()