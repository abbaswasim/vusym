# VuSym Source Code
# Wasim Abbas
# http://www.waZim.com
# Copyright (c) 2020
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the 'Software'),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software
# is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Version: 1.0.0

cmake_minimum_required (VERSION 3.12)

project(VuSym VERSION 1.1.0.0 LANGUAGES CXX C)
list(APPEND CMAKE_MESSAGE_CONTEXT Vulkan_Symbols)

set(VUSYM_NAME vusym)

set(VUSYM_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}) # Always prefer the _LIST_ version FILES/DIRS instead of the _SOURCE_
set(VUSYM_SOURCE_DIR ${VUSYM_ROOT_DIR})

include(${VUSYM_ROOT_DIR}/build.cmake)

# Always generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Configure version source file vusym_version.cpp
configure_file(${VUSYM_SOURCE_DIR}/vusym_version.cpp.in vusym_version.cpp @ONLY)
add_library(vusym_version STATIC ${CMAKE_CURRENT_BINARY_DIR}/vusym_version.cpp)
target_include_directories(vusym_version PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Add vulkan
add_library(vulkan_headers INTERFACE)
set(VULKAN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/vulkan/include)
target_sources(vulkan_headers INTERFACE ${VULKAN_INCLUDE_DIR}/vulkan/vulkan.h)
target_include_directories(vulkan_headers INTERFACE ${VULKAN_INCLUDE_DIR})

set(VUSYM_HEADERS
  ${VUSYM_SOURCE_DIR}/vusym.hpp)

set(VUSYM_SOURCES
  ${VUSYM_SOURCE_DIR}/vusym.cpp)

add_library(${VUSYM_NAME} SHARED ${VUSYM_SOURCES} ${VUSYM_HEADERS})
# add_executable(${VUSYM_NAME} ${VUSYM_SOURCES} ${VUSYM_HEADERS})

set_target_properties(${VUSYM_NAME} PROPERTIES VERSION 1.0.0.0 SOVERSION 1)          # TODO: Fix the hardcoded version
set_target_properties(${VUSYM_NAME} PROPERTIES CMAKE_VISIBILITY_INLINES_HIDDEN true) # Don't export all of those C++ template generated symbols
set_target_properties(${VUSYM_NAME} PROPERTIES CMAKE_CXX_VISIBILITY_PRESET hidden)   # Set default to hide symbols visibility for VuSym
set_target_properties(${VUSYM_NAME} PROPERTIES CMAKE_C_VISIBILITY_PRESET hidden)     # Set default to hide symbols visibility for VuSym

set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)    # Set default to hide symbols visibility for all targets
set(CMAKE_C_VISIBILITY_PRESET hidden)      # Set default to hide symbols visibility for all targets

# Only use the below if building library
message(STATUS "Now generating vusym_export_import.h file")
include(GenerateExportHeader)
generate_export_header(${VUSYM_NAME}
  EXPORT_FILE_NAME vusym_export_import.hpp
  EXPORT_MACRO_NAME VUSYM_ITEM
  NO_EXPORT_MACRO_NAME VUSYM_PRIVATE)

target_include_directories(${VUSYM_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${VUSYM_NAME} PRIVATE ${VUSYM_SOURCE_DIR})
target_include_directories(${VUSYM_NAME} PRIVATE ${VUSYM_ROOT_DIR})

set(VUSYM_REQUIRED_LIBRARIES
  vusym_version)

target_link_libraries(${VUSYM_NAME} PRIVATE ${VUSYM_REQUIRED_LIBRARIES} vulkan_headers)

build_options(${VUSYM_NAME}) # Set common build options
