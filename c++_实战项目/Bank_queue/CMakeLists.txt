# 工程名称
project(bank)

cmake_minimum_required(VERSION 3.5)
# 设置
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")



include_directories( 
    include

)



# 编译源码生成目标

add_executable(bank src/bank.cpp)