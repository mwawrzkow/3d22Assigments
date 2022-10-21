#include <iostream>
#include "external/OpenGLStart.hpp"
#include "external/vertexHandler.hpp"
#include <fstream>
#include <sstream>
#include "external/vertexHandler.hpp"


float randd() {
  return (float)rand() / ((float)RAND_MAX + 1);
}

//Small implementation of reading the file
std::string readFile(const std::string &fileLoc)
{
    std::ifstream file;
    file.open(fileLoc, std::ios::in);
    std::stringstream contex;
    if (!file.fail())
    {
        contex << file.rdbuf();
    }
    file.close();
    return contex.str();
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    int width = 1280, height = 720; // Minimum window size 
    GLFWwindow *window = OpenGLInstance::InitWindow(width, height); // Creating instance 

    OpenGLInstance::setClearColor(0.0, 0.0, 0.0, 1); // Clear color to black 
    GLuint ShaderProgram = OpenGLInstance::CreateProgramAndLinkShaders(
        OpenGLInstance::CreateAndCompileShaders(
            readFile("./shaders/vertShader.vert").c_str(), // vert shader 
            readFile("./shaders/fragShader.frag").c_str())); // frag shade // lookup in CMakeLists
    glUseProgram(ShaderProgram); // "Instaling Shaders"

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    float alpha = 1;
    float vert[] = {
            /*    cords                                                                                              |    RGBA color     |    TexturePos        */
            -0.4f, -0.3f, 0.0f, randd(), randd(), randd(), alpha, 1.0f, 1.0f,
            0.4f, -0.3f, 0.0f,  randd(), randd(), randd(), alpha, 0.0f, 1.0f,
            -0.4f, 0.1f, 0.0f,  randd(), randd(), randd(), alpha, 0.0f, 0.0f,
            0.4f, 0.1f, 0.0f,   randd(), randd(), randd(), alpha, 1.0f, 0.0f,
            0.0f, 0.3f, 0.0f,   randd(), randd(), randd(), alpha, 1.0f, 0.0f,
            };
    unsigned int inc[] = {
            0, 1, 2,
            1, 2, 3,
            2, 4, 3
            };
    VertexHandler vertH(true);
    vertH.setVertexHandler(vert, sizeof(vert), inc, sizeof(inc));
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glfwPollEvents();
        for(int i = 1; i <= 5 ; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                vert[3+(i * 9) + j] -= 0.001;
                if(vert[3+(i * 9)+j] < 0.0f)
                    vert[3+(i * 9) + j] = 1; 
            }
        }
        vertH.setVertexHandler(vert, sizeof(vert), inc, sizeof(inc));

	    vertH.Display();
	    glfwSwapBuffers(window);
    }
    glDeleteProgram(ShaderProgram);
    glfwDestroyWindow(window);
    return EXIT_SUCCESS;
  return 0;
}
