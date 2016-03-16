cmake_minimum_required(VERSION 2.8.11)
project(OgreTest)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug)
endif()

# State directories for modules and binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

#Location of source files
file(GLOB SOURCE src/*.cpp src/*.hpp)

find_package(OGRE REQUIRED)
if(NOT OGRE_FOUND)
	message(FATAL_ERROR "Package Ogre3D is required, but not found!")
endif(NOT OGRE_FOUND)

# Specify include directories
include_directories(
	${OGRE_INCLUDE_DIRS}
)

# Create the binary
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
	${OGRE_LIBRARIES}
)
