# 工程名称
project(MemoryPool)

cmake_minimum_required(VERSION 3.5)
# 设置
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")



include_directories( 
    include

)



# 编译源码生成目标

add_library(LeakDetector  src/LeakDetector.cpp)
add_executable(LeakDetector_test  src/test.cpp)
target_link_libraries(LeakDetector_test LeakDetector)