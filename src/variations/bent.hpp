#pragma once

#include "variations/variation.hpp"

struct Bent : public Variation
{
    Bent() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        if (x >= 0.0 and y >= 0.0)
        {
            return {x, y};
        }
        if (x < 0.0 and y >= 0.0)
        {
            return {2.0 * x, y};
        }
        if (x >= 0.0 and y < 0.0)
        {
            return {x, y / 2.0};
        }
        if (x < 0.0 and y < 0.0)
        {
            return {2.0 * x, y / 2.0};
        }
    }
};
