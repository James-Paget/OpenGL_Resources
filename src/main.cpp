#include<iostream>
#include "glad.h"
#include<GLFW/glfw3.h>

int main() {
    /*
    ADDITIONAL NOTES**
        . Must add new src files to CMakeLists to compile together correctly
        . GLFW for window creation, GLAD for OpenGL rendering extras it appears
            +Include GLAD before GLFW to prevent errors
    */
    std::cout << "Program Start..." << std::endl;

    GLFWwindow* window;

    if( !glfwInit() ) {     // Initialise GLFW, else leave with error code
        std::cout << "GLFW failed to load" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800,800, "WINDOW_NAME", NULL, NULL);
    glfwMakeContextCurrent(window);

    // **NOTE; Must be done AFTER GLFW initialised (hence must terminate too if there is an error)
    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) ) {        // Loading GLAD info, else leave with error code
        std::cout << "GLAD failed to load" << std::endl;                // Must also be run AFTER making the window current, otherwise will NOT load correctly
        glfwTerminate();   
        return -1;
    }

    glClearColor(0.2f, 0.8f, 0.2f, 1.0f);

    while(!glfwWindowShouldClose(window)) {     // Loop while the specified window is open
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();    // Stop GLFW before program end - clean-up
    return 0;
}