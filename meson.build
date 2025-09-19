project('rvivl', 'cpp', version: '0.1.0', default_options: ['cpp_std=c++23'])

# Vulkan dependencies
vulkan_headers_dep = dependency('vulkan', required: true)
vulkan_loader_dep = dependency('vulkan', required: true)

vulkan_dep = declare_dependency(
    dependencies: [vulkan_headers_dep, vulkan_loader_dep],
)

# Use system SDL2 instead of subproject
sdl2_dep = dependency('sdl2', required: true)

# Include source and tests
subdir('src')
subdir('tests')
