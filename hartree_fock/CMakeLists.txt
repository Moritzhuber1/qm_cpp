#This file tells CMake how to build the Hartree-Fock module
# read more : https://cmake.org/cmake/help/book/mastering-cmake/chapter/Writing%20CMakeLists%20Files.html

#minimum cmake version
cmake_minimum_required(VERSION 3.20) 

#project name and language
project(hf LANGUAGES CXX)

#cmake variables  
# using c++20 and stop if the compiler not using 20 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#this let cmake generate a compile_commands.json file 
#with the exact compiler calls
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_library builds a bibliothec out of .cpp files
# with INTERFACE can you add the hf_options to different targets
add_library(hf_options INTERFACE)

# Warnings for the compiler 
#       -Wall enable the most common Warnings
#       -Wextra enable addtional warnings 
#       -Wpedantic warn about not standard c++
#       -Wshadow warn when a variable hides another one with same name
#       Wconversion warn about implicit conversion that my lose data 
#Sanitizer, checks at run time 
#       address        detect out-of-bounds and other memory errors
#       undefined      detect undefined behavior
target_compile_options(hf_options INTERFACE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion
    $<$<CONFIG:Debug>:-fsanitize=address,undefined -fno-omit-frame-pointer>)

#sanitizers also need their runtime library at link time
target_link_options(hf_options INTERFACE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>)

#from these data, the hf_lib library is build 
# every addtional .cpp file is added here 
add_library(hf_lib src/molecule.cpp)


# Add include/ to the header search path (-I flag), so code can write
# #include "hf/vec3.hpp". PUBLIC: targets linking hf_lib get this path too.
target_include_directories(hf_lib PUBLIC include)

#hf_lib takes the warnings and sanitizer of hf_options
target_link_libraries(hf_lib PUBLIC hf_options)

# programm "hf" consists of only main.cpp
add_executable(hf app/main.cpp)

# main.cpp uses the library 
target_link_libraries(hf PRIVATE hf_lib)

