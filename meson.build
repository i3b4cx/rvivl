project('rvivl', 'cpp', version: '0.1.0', default_options: ['cpp_std=c++23'])

vulkan_headers_dep = dependency('vulkanheaders')  # matches [provide] in wrap
vulkan_loader_dep = dependency('vulkan', required: true)

vulkan_dep = declare_dependency(
    dependencies: [vulkan_headers_dep, vulkan_loader_dep],
)

sdl2_proj = subproject('sdl2')
sdl2_dep = sdl2_proj.get_variable('sdl2_dep')

subdir('src')
subdir('tests')
