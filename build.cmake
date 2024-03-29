# VaSym Source Code
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

include_guard()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RelWithDebInfo) # good compromise
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD 20)  # Ask for Cxx20 but not required
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

function(vusym_build_options target_name)
  if (CMAKE_BUILD_TYPE MATCHES "Debug")
	target_compile_definitions(${target_name} PUBLIC RORDEBUG)
	set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
	set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
  else()
	set(CMAKE_CXX_FLAGS_DEBUG "-O3")
	set(CMAKE_C_FLAGS_DEBUG "-O3")
  endif (CMAKE_BUILD_TYPE MATCHES "Debug")

  # Be slightly more pedantic
  target_compile_options(${target_name} PRIVATE
	-Wall
	-Wextra
#	-Wmost
	-Wconversion
	-Wunreachable-code
	-Wuninitialized
	-Wno-gnu-zero-variadic-macro-arguments # Should fix this in long term, this is only needed for gtest typed tests at the moment
	-pedantic-errors
	-Wold-style-cast
	-Wno-error=unused-variable
	-Wshadow
	-Wfloat-equal)

endfunction(vusym_build_options)
