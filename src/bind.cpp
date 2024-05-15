#include <pybind11/pybind11.h>
#include <pybind11/stl/filesystem.h>
#include <pybind11/stl.h>

#include "flame.hpp"
#include "transforms/transform.hpp"
#include "variations/all.hpp"

PYBIND11_MODULE(combustion, m)
{
    pybind11::class_<Flame>(m, "Flame")
        .def(pybind11::init<>())
        .def("compute", &Flame::compute);

    pybind11::class_<Transform>(m, "Transform")
        .def(pybind11::init<>())
        .def("compute", &Transform::compute)
        .def("add_variation", &Transform::add_variation)
        .def_readwrite("a", &Transform::a)
        .def_readwrite("b", &Transform::b)
        .def_readwrite("c", &Transform::c)
        .def_readwrite("d", &Transform::d)
        .def_readwrite("e", &Transform::e)
        .def_readwrite("f", &Transform::f)
        .def_readwrite("color", &Transform::color);

    pybind11::class_<Variation>(m, "Variation")
        .def("compute", &Variation::compute);

    pybind11::class_<Halve, Variation>(m, "Halve")
        .def(pybind11::init<>())
        .def("compute", &Halve::compute);

    pybind11::class_<Linear, Variation>(m, "Linear")
        .def(pybind11::init<>())
        .def("compute", &Linear::compute);

    pybind11::class_<Popcorn, Variation>(m, "Popcorn")
        .def(pybind11::init<>())
        .def("compute", &Popcorn::compute);

    pybind11::class_<Sierpinkski1, Variation>(m, "Sierpinkski1")
        .def(pybind11::init<>())
        .def("compute", &Sierpinkski1::compute);

    pybind11::class_<Sierpinkski2, Variation>(m, "Sierpinkski2")
        .def(pybind11::init<>())
        .def("compute", &Sierpinkski2::compute);

    pybind11::class_<Sinusoidal, Variation>(m, "Sinusoidal")
        .def(pybind11::init<>())
        .def("compute", &Sinusoidal::compute);

    pybind11::class_<Spherical, Variation>(m, "Spherical")
        .def(pybind11::init<>())
        .def("compute", &Spherical::compute);
}