cmake_minimum_required(VERSION 3.5)

#add_definitions(-DWITH_NEON)
add_definitions(-DWITH_AVX2)

set(CMAKE_CXX_STANDARD 11)

project(dotp)

# https://stackoverflow.com/questions/18638051/using-avx-with-gcc-avxintrin-h-missing
# By default, GCC will not enable AVX instructions.
# new start for enable AVX instructions by qingzhongli2018@gmail.com
set(CXX_FLAGS
 -march=native
 )

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
# new end for enable AVX instructions by qingzhongli2018@gmail.com

ADD_EXECUTABLE(dotp main.cpp matoperation.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(dotp PUBLIC OpenMP::OpenMP_CXX)
endif()

