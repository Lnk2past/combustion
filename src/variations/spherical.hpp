#pragma once

#include <array>
#include <cmath>

#include "variations/variation.hpp"

struct Spherical : public Variation
{
    Spherical() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const std::array<double, 4> &xyc) const -> std::array<double, 4> const
    {
        const auto r = xyc[0] * xyc[0] + xyc[1] * xyc[1];
        return {xyc[0] / r, xyc[1] / r};
    }
};
