#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

class VulkanRenderer
{
public:
    VulkanRenderer();
    int init(GLFWwindow * newWindow);


private:
    GLFWwindow* window;

    //vulkanComponents

    VkInstance instance;

    //Vulkan Functions
    void createInstance();
};

#endif // VULKANRENDERER_H
