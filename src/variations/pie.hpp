#pragma once

#include "variations/variation.hpp"

struct Pie : public Variation
{
    Pie() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {x, y};
    }
};
