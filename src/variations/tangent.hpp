#pragma once

#include "variations/variation.hpp"

struct Tangent : public Variation
{
    Tangent() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {x, y};
    }
};
