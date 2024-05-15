#pragma once

#include <array>

#include "variations/variation.hpp"

struct Sierpinkski2 : public Variation
{
    Sierpinkski2() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const std::array<double, 4> &xyc) const -> std::array<double, 4> const
    {
        return {xyc[0] / 2, (xyc[1] + 1) / 2};
    }
};
