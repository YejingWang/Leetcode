#
# Created By: Weiyuyijin 2020/06/16
#

cmake_minimum_required(VERSION  3.8.0)

IF (UNIX)
	set(CMAKE_C_COMPILER "/usr/bin/clang")
	set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -I/usr/include/libcxxabi")
	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
ENDIF()

add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)

# top project
project (LeetCodePlayground VERSION 1.0.0 LANGUAGES C CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)

IF (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
ENDIF()

add_definitions(-DNOMINMAX)
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

# global settings
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

set(FILE_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

file(GLOB_RECURSE srcs "${FILE_ROOT}/Problems/*.h" "${FILE_ROOT}/Problems/*.hpp" "${FILE_ROOT}/LeetCodePlayground.cpp")

source_group(TREE ${FILE_ROOT} FILES ${srcs})

add_executable(${PROJECT_NAME} ${srcs})