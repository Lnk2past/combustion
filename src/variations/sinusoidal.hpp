#pragma once

#include <array>
#include <cmath>

#include "variations/variation.hpp"

struct Sinusoidal : public Variation
{
    Sinusoidal() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const std::array<double, 4> &xyc) const -> std::array<double, 4> const
    {
        return {std::sin(xyc[0]), std::sin(xyc[1])};
    }
};
