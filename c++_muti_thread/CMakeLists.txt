# 工程名称
project(muti_thread)

cmake_minimum_required(VERSION 3.5)
# 设置
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")



include_directories( 
    include

)



# 编译源码生成目标


add_executable(parallel_quick_sort  src/parallel_quick_sort.cpp)
target_link_libraries(parallel_quick_sort pthread)
