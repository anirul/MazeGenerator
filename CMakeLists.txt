cmake_minimum_required(VERSION 2.8)

project(MazeGenerator)

include("cmake/FindCXXFeatures.cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_COMPILER_FLAGS}")

if(APPLE)
	set(CMAKE_C_COMPILER clang)
	set(CMAKE_CXX_COMPILER clang++)
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD c++11)
	set(CMAKE_XCODE_ATTRIBURE_CLANG_CXX_LIBRARY libc++)
	set(CMAKE_OSX_ARCHITECTURES x86_64)
	set(CMAKE_LIBRARY_PREFIX /opt/local /usr/local)
endif(APPLE)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
	program_options
	filesystem
	system
	)

include_directories(
	/opt/local/include
	/usr/local/include
	/usr/include
	)

if(NOT Boost_FOUND)
       message(FATAL_ERROR "Boost not found")
endif()

add_executable(MazeGenerator
	Sources/maze_generator.cpp
	Sources/maze_generator.hpp
	Sources/maze_main.cpp
	)

target_link_libraries(MazeGenerator
	${Boost_LIBRARIES}
	)
