# Generator program for vusym.hpp and vusym.cpp

This is a simple libTooling tool to generate vusym.[hpp/cpp] that can be used in your Vulkan projects for symbol loading.

## How to build and use

Make sure you have LLVM/Clang installed. Then use the following command for llvm@16 installed via homebrew to build the generator.

```bash
Clang_DIR=/usr/local/Cellar/llvm/16.0.6/lib/cmake cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release && cmake --build build --config Release -- -j8
```

This will build `./build/vkSymGen`. Which you need to run with the vulkan headers you want to use.

```bash
./build/vkSymGen /path/to/where/the/vulkan/headers/are/include/vulkan.h -- -I /path/to/where/the/vulkan/headers/are/include
```

This will generate `vusym.[hpp/cpp]` in the current folder that you can then use in your project. For fairly recent versions of vulkan.h `vusym.[hpp/cpp]` are also provided in the repository.

## License

The code is licensed under MIT.

## Project web sites:
[www.waZim.com](http://www.waZim.com/)
