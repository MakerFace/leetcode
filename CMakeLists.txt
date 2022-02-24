cmake_minimum_required(VERSION 3.5)
project(LeetCode)

set(std=c++11)

# include_directories(include)

##############
##   Build  ##
##############
file(GLOB LEETCODE_LIST src/*.cpp)

foreach(LC IN LISTS LEETCODE_LIST)
    message(STATUS "add_leetcode_exec=${LC}") # fatal用于停止构建
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" LC_EXEC ${LC}})
    add_executable(
        ${LC_EXEC}
        ${LC}
    )
endforeach(LC IN ${LEETCODE_LIST})

