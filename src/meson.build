rvivl_sources = ['rvivl.cpp']

rvivl_inc = include_directories('../include')

rvivl_lib = library(
    'rvivl',
    rvivl_sources,
    include_directories: rvivl_inc,
    install: true,
)

rvivl_dep = declare_dependency(
    link_with: rvivl_lib,
    include_directories: rvivl_inc,
)
