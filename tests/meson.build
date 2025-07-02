# tests/meson.build

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

# Try to find glslangValidator
glslang_validator = find_program(
    'glslangValidator',
    required: false,
    dirs: [
        '/usr/bin',
        '/usr/local/bin',
        '/opt/vulkan-sdk/bin',
        '/usr/local/vulkan-sdk/bin',
    ],
)

# If not found, provide helpful error message
if not glslang_validator.found()
    error(
        '''glslangValidator not found!
  
Please install it via one of these methods:
  1. Install Vulkan SDK: https://vulkan.lunarg.com/
  2. Install via package manager:
     - Ubuntu/Debian: sudo apt install glslang-tools
     - Fedora: sudo dnf install glslang
     - Arch: sudo pacman -S glslang
  ''',
    )
endif

message('Found glslangValidator at: ' + glslang_validator.full_path())

# Compile shaders from main directory
vertex_spirv = custom_target(
    'vertex_shader',
    input: '../shaders/vertex.vert',
    output: 'vertex.spv',
    command: [glslang_validator, '-V', '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default: true,
)

fragment_spirv = custom_target(
    'fragment_shader',
    input: '../shaders/fragment.frag',
    output: 'fragment.spv',
    command: [glslang_validator, '-V', '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default: true,
)

# Create a dependency that ensures shaders are built
shader_dep = declare_dependency(sources: [vertex_spirv, fragment_spirv])

# Source files
gtest_tests_src = ['simple_test.cpp']
vulkan_tests_src = ['vulkan_test.cpp']

# Executables
gtest_exe = executable(
    'gtest-all',
    gtest_tests_src,
    dependencies: [gtest_dep, gmock_dep],
)

vulkan_exe = executable(
    'vulkan-test',
    vulkan_tests_src,
    dependencies: [vulkan_dep, sdl2_dep, shader_dep],
)

# Tests
test('gtest tests', gtest_exe)
test('vulkan tests', vulkan_exe)
