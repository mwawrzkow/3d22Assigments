PROJECT(HOUSE)

#I'm bored so why not
add_compile_options(-Wall)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall)
add_compile_options(-Wextra)


include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(house 
  main.cpp 
  external/OpenGLStart.cpp
  external/OpenGLArrays/ArrayHandler.cpp
  external/WindowProperties.cpp
  external/vertexHandler.cpp
  )

target_link_libraries(house PRIVATE ${GL_DEF})
target_include_directories(house PUBLIC ${CMAKE_BINARY_DIR}/_deps/stb-src)
target_include_directories(house PUBLIC ${CMAKE_BINARY_DIR}/_deps/glew-src/include)
target_include_directories(house PUBLIC ${CMAKE_BINARY_DIR}/_deps/glfw-src/include)


target_include_directories(house PUBLIC ${CMAKE_BINARY_DIR}/_deps/glew-src/include)
target_include_directories(house PUBLIC ${CMAKE_BINARY_DIR}/_deps/glfw-src/include)

file(COPY "shaders/" DESTINATION "shaders/")
configure_file(shaders/vertShader.vert shaders/vertShader.vert COPYONLY)
configure_file(shaders/fragShader.frag shaders/fragShader.frag COPYONLY)

