# Vulkan Symbol loader

Use this to generate and use vulkan symbols from latest vulkan headers

## How to build and use

Unless you want to use the ones pre-genereated. First make sure you have the latest `./build/vkSymGen` genereated using 'vkSymGen' provided in this repo.

```bash
# To use as library in your application first build the project using
add_subdirectory(thirdparty/vusym)

# Then link to the library using
target_link_libraries(${YOUR_PROJECT_TARGET} PRIVATE vusym)
```

## License

The code is licensed under MIT.

## Project web sites:
[www.waZim.com](http://www.waZim.com/)
