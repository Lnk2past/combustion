#pragma once

#include "variations/variation.hpp"

struct Cylinder : public Variation
{
    Cylinder() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {std::sin(x), y};
    }
};
