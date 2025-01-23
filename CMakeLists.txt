cmake_minimum_required(VERSION 3.30)
project(GalagaPlus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (APPLE)
    enable_language(OBJC)
endif ()

add_executable(GalagaPlus src/main.cpp)

set(SDLMIXER_VENDORED ON)
set(SDLTTF_VENDORED ON)

add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_image)
add_subdirectory(vendor/SDL_mixer)
add_subdirectory(vendor/SDL_ttf)

target_link_libraries(
        GalagaPlus PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
)

target_include_directories(
        GalagaPlus PRIVATE
        src
        vendor/SDL/include
        vendor/SDL_image/include
        vendor/SDL_mixer/include
        vendor/SDL_ttf
)
