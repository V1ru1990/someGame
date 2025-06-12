#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int glfw_windowSizeX = 640;
int glfw_windowSizeY = 480;

void glfw_WindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    glfw_windowSizeX = width;
    glfw_windowSizeY = height;
    glViewport(0, 0, glfw_windowSizeX, glfw_windowSizeY);
}

void glfw_WindowKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(pWindow, GL_TRUE); }
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit() failed\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int WIDTH = 640;
    const int HEIGHT = 480;
        

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(glfw_windowSizeX, glfw_windowSizeY, "Some Game", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed\n";
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfw_WindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfw_WindowKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "Can't load GLAD\n";
        return -1;
    }

    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
    std::cout << glGetString(GL_RENDERER) << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 0, 0, 1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}