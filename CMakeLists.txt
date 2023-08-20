cmake_minimum_required(VERSION 3.19)

project(LayoutReader LANGUAGES C CXX)


enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Initialization of common build parameters
set(BUILD_TYPE_LIST "Debug" "Release")
set(OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/Output")

set(OUTPUT_DEBUG_DIR "${CMAKE_CURRENT_LIST_DIR}/Debug")
set(OUTPUT_RELEASE_DIR "${CMAKE_CURRENT_LIST_DIR}/Release")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})

set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:\\qt\\5.12.12\\mingw73_64\\")

# find_package(Boost REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS})
# endif()


include(UnitTestModule)
include(CTest)

set(SHARED_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(Libs)