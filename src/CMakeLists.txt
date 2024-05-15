add_subdirectory(transforms)

pybind11_add_module(combustion bind.cpp flame.cpp)

target_link_libraries(combustion PUBLIC spdlog::spdlog transforms)
