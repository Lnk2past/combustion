#pragma once

#include "variations/variation.hpp"

struct Halve : public Variation
{
    Halve() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {point[0] / 2, point[1] / 2};
    }
};
