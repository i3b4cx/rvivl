gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

gtest_tests_src = ['simple_test.cpp']

vulkan_tests_src = ['vulkan_test.cpp']

gtest_exe = executable(
    'gtest-all',
    gtest_tests_src,
    dependencies: [gtest_dep, gmock_dep],
)

vulkan_exe = executable(
    'vulkan-test',
    vulkan_tests_src,
    dependencies: [vulkan_dep],
)
test('gtest tests', gtest_exe)
