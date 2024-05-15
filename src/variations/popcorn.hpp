#pragma once

#include <array>
#include <cmath>

#include "variations/variation.hpp"

struct Popcorn : public Variation
{
    Popcorn() = default;

    auto compute(const double, const double, const double c, const double, const double, const double f, const std::array<double, 4> &xyc) const -> std::array<double, 4> const
    {
        return {
            xyc[0] + c * std::sin(std::tan(3.0 * xyc[1])),
            xyc[1] + f * std::sin(std::tan(3.0 * xyc[0]))};
    }
};
