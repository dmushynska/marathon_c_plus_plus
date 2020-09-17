cmake_minimum_required(VERSION 3.16)
project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
    -pipe
    # -Ofast
    # -march=native
    # -flto
    -O0
    -g3
    # -fsanitize=address,undefined
    -fno-omit-frame-pointer
)

add_subdirectory(3dparty)
add_subdirectory(app)
