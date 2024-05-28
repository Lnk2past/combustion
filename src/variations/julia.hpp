#pragma once

#include "variations/variation.hpp"

struct Julia : public Variation
{
    Julia() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto sqrt_r = std::sqrt(std::sqrt(x * x + y * y));
        const auto theta_over_2 = 0.5 * std::atan(x / y);
        const auto omega = std::bernoulli_distribution{}(std::random_device{}());
        const auto theta_over_2_plus_omega = theta_over_2 + omega;
        return {sqrt_r * std::cos(theta_over_2_plus_omega), sqrt_r * std::sin(theta_over_2_plus_omega)};
    }
};
