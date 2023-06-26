cmake_minimum_required (VERSION 3.12)

project(vkSymGen VERSION 1.1.0.0 LANGUAGES CXX C)
list(APPEND CMAKE_MESSAGE_CONTEXT Vulkan_Symbol_Generator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

# Find CMake file for Clang
find_package(Clang REQUIRED CONFIG)

# Add path to LLVM modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LLVM_CMAKE_DIR}")

# import LLVM CMake functions
include(AddLLVM)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})

add_definitions(${LLVM_DEFINITIONS})
add_definitions(${CLANG_DEFINITIONS})

add_llvm_executable(vkSymGen vk_sym_gen/sym_gen.cpp)
set_property(TARGET vkSymGen PROPERTY CXX_STANDARD 17)
target_link_libraries(vkSymGen PRIVATE clangTooling)
