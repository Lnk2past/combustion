#pragma once

#include "variations/variation.hpp"

struct Noise : public Variation
{
    Noise() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        auto rd = std::random_device{};
        auto psi_dis = std::uniform_real_distribution<double>{0.0, 1.0};
        const auto psi1 = psi_dis(rd);
        const auto psi2 = psi_dis(rd);
        return {psi1 * x * std::cos(2.0 * pi * psi2), psi1 * y * std::sin(2.0 * pi * psi2)};
    }
};
