#pragma once

#include "variations/variation.hpp"

struct PDJ : public Variation
{
    PDJ() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {std::sin(p1 * y) - std::cos(p2 * x), std::sin(p3 * x) - std::cos(p4 * y)};
    }

    double p1{}; // a ???
    double p2{}; // b ???
    double p3{}; // c ???
    double p4{}; // d ???
};
