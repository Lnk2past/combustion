add_library(transforms SHARED transform.cpp)
target_link_libraries(transforms PUBLIC spdlog::spdlog)
