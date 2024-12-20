#include "vulkanrenderer.h"

VulkanRenderer::VulkanRenderer()
{}

int VulkanRenderer::init(GLFWwindow * newWindow)
{
    window = newWindow;
    try{
        createInstance();
    }
    catch(const std::runtime_error &e)
    {
        printf("ERROR: %s\n", e.what());
        return EXIT_FAILURE;
    }

    return 0;
}

void VulkanRenderer::createInstance()
{
    //INformation about the application itself
    //Most of the data here doesn't affect the program an dis for developer convenience
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "vulkan APp";
    appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Creating Information for a vkInstance(Vulkan Instance)
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    //create list to hold instance extension

    std::vector<const char*> instanceExtensions = std::vector<const char*>();
    uint32_t glfwExtensionCount = 0;        //GLFW may require multiple extensions
    const char** glfwExtensions;    //Extensions passed as array of cstrings, so need pointer (the array) to pointer (The cstring)

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);


    //add GLFW exyensions to list of extensions
    for(size_t i = 0; i < glfwExtensionCount; i++)
    {
        instanceExtensions.push_back(glfwExtensions[i]);
    }

    createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
    createInfo.ppEnabledExtensionNames = instanceExtensions.data();

    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = nullptr;

    //create Instance

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if(result != VK_SUCCESS)
    {

    }
}
