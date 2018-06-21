cmake_minimum_required(VERSION 2.8)

find_package(Boost 1.5 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-cpp")
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
    /usr/include/python2.7
)
link_directories(
    /usr/lib/x86_64-linux-gnu
    /usr/lib
    /usr/local/lib
)
add_library(libs SHARED 
    src/a.cpp
    src/b.cpp 
    src/the_a.cpp
    )
add_library(inner_member_pointer SHARED inner_member_pointer.cpp)
target_link_libraries(inner_member_pointer libs libboost_python.so libpython2.7.so)
set_target_properties(inner_member_pointer PROPERTIES PREFIX "")

add_library(string_member_pointer SHARED string_member_pointer.cpp)
target_link_libraries(string_member_pointer  libboost_python.so libpython2.7.so)
set_target_properties(string_member_pointer PROPERTIES PREFIX "")

add_library(design_member_pointer SHARED design_member_pointer.cpp)
target_link_libraries(design_member_pointer  libboost_python.so libpython2.7.so)
set_target_properties(design_member_pointer PROPERTIES PREFIX "")

add_executable(main main.cpp)
target_link_libraries(main libs)

