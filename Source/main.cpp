#include "ApplicationDefines.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main()
{
    if (!glfwInit())
    {
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
    GLFWwindow* window = glfwCreateWindow(720, 480, "HelloOpenGL", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
        return EXIT_FAILURE;

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}
