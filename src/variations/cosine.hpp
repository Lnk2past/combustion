#pragma once

#include "variations/variation.hpp"

struct Cosine : public Variation
{
    Cosine() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {std::cos(pi * x) * std::cosh(y), std::sin(pi * x) * std::sinh(y)};
    }
};
