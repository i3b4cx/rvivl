#define VK_USE_PLATFORM_XLIB_KHR // Example: if you target X11 on Linux, define
                                 // platform macro (optional)
#include <vulkan/vulkan.h>

#include <iostream>

int main() {
    VkInstance instance;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = nullptr;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance!" << std::endl;
        return -1;
    }

    std::cout << "Vulkan instance created successfully." << std::endl;

    vkDestroyInstance(instance, nullptr);
    return 0;
}
