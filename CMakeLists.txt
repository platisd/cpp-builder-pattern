cmake_minimum_required(VERSION 3.13)
project(builder-pattern)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        -Wcast-align
        -Wpedantic
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wnon-virtual-dtor
        -Wmissing-include-dirs
        -Wdisabled-optimization
        -Winit-self
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wparentheses
        -Wredundant-decls
        -Wshadow
        -Wsign-promo
        -Wstrict-aliasing
        -Wall
        -Wextra
        -Werror
)

add_executable(basic_builder basic-builder.cpp)
add_executable(late_access_builder late-access-builder.cpp)
add_executable(builder_with_interfaces builder-with-interfaces.cpp)
