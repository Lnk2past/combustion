from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake

class combustion(ConanFile):
    name = "combustion"
    version = "0.0.1"
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'CMakeToolchain', 'CMakeDeps'

    def requirements(self):
        self.requires("fmt/10.2.1")
        self.requires("nlohmann_json/3.11.3")
        self.requires("spdlog/1.14.1")
        self.requires("pybind11/2.12.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)
