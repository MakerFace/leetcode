cmake_minimum_required(VERSION 3.5)
project(LeetCode)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)    
endif()

set(std=c++11)
add_compile_options(-Wall -Werror -fsanitize=address)

# include_directories(include)

##############
##   Build  ##
##############
file(GLOB_RECURSE LEETCODE_LIST src/*.cpp)
include_directories(include)

foreach(LC IN LISTS LEETCODE_LIST)
    message(STATUS "add_leetcode_exec=${LC}") # fatal用于停止构建
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" LC_EXEC ${LC})
    add_executable(
        ${LC_EXEC}
        ${LC}
    )
    target_link_libraries(${LC_EXEC} -lpthread -fsanitize=address)
endforeach(LC IN ${LEETCODE_LIST})

