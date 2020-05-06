cmake_minimum_required(VERSION  3.8.0)

project (LeetcodePlayground VERSION 1.0.0 LANGUAGES C CXX)

set(FILE_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)
file (GLOB_RECURSE problem_files ${FILE_ROOT}/Problems/*.h)
file (GLOB srcs ${FILE_ROOT}/*.cpp)

add_executable(${PROJECT_NAME} ${srcs} ${problem_files})