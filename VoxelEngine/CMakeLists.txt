# CMake entry point
cmake_minimum_required (VERSION 2.8)
project (VoxelEngine)

set(CMAKE_MODULE_PATH /usr/local/lib/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)

include_directories(
    /usr/local/include
    $(GLEW_INCLUDE_DIRS)
    $(glfw3_INCLUDE_DIRS)
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
    ${GLFW3_LIBRARY}
    ${GLEW_LIBRARY}
    ${COCOA_LIBRARY}
    ${COREVID_LIBRARY}
    ${IOKIT_LIBRARY}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Executable
add_executable(voxel_engine
	main.cpp
)
target_link_libraries(voxel_engine
	${ALL_LIBS}
)
