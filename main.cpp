#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
//This includes are for finding and including vulkan into our projects

#include <stdexcept>
#include <vector>

#include <iostream>

#include "vulkanrenderer.h"



GLFWwindow* window;
VulkanRenderer VulkanRenderer;
void initwindow(std::string wName= "Test Window", const int width = 800, const int height = 600)
{
    glfwInit();

    //set GLFW to not work with OpenGL
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main( )
{
    initwindow("Test window", 800, 600);

    //create vulkan renderer intanse
    if(VulkanRenderer.init(window) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    //loop until close
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    //Destroy GLFW window and stop it
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
