#pragma once

#include "variations/variation.hpp"

struct NAME : public Variation
{
    NAME() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto coeff = p2 / (p2 - y * std::sin(p1));
        return {coeff * x, coeff * y * std::cos(p1)};
    }

    double p1{}; // angle
    double p2{}; // dist
};
