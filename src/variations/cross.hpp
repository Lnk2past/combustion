#pragma once

#include "variations/variation.hpp"

struct Cross : public Variation
{
    Cross() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {x, y};
    }
};
