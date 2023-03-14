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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
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
