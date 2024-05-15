#pragma once

#include <array>

#include "variations/variation.hpp"

struct Linear : public Variation
{
    Linear() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const std::array<double, 4> &xyc) const -> std::array<double, 4> const
    {
        return xyc;
    }
};
