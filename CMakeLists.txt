cmake_minimum_required(VERSION 3.7.2)
PROJECT(ASSIGMENTS)

include(FetchContent)

FetchContent_Declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
)
FetchContent_Declare(glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
        )
FetchContent_Declare(
                stb
                GIT_REPOSITORY https://github.com/nothings/stb.git
                GIT_TAG master
                CONFIGURE_COMMAND ""
                BUILD_COMMAND ""
                )
FetchContent_MakeAvailable(glfw)
FetchContent_MakeAvailable(glew)
FetchContent_MakeAvailable(stb)
set(GL_DEF glfw libglew_static)

add_subdirectory(house)

