#pragma once

#include "variations/variation.hpp"

struct Fisheye : public Variation
{
    Fisheye() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto coeff = 2.0 / (r + 1.0);
        return {coeff * y, coeff * x};
    }
};
