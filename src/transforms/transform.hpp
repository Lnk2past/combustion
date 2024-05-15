#pragma once

#include <array>
#include <memory>
#include <vector>

class Variation;
class Transform
{
public:
    Transform();
    Transform(const Transform &o);
    Transform(Transform &&o);
    ~Transform();
    auto operator=(const Transform &o) -> Transform &;

    auto compute(const std::array<double, 4> &xyc) const -> std::array<double, 4>;

    auto add_variation(Variation *variation) -> void;

    double a{};
    double b{};
    double c{};
    double d{};
    double e{};
    double f{};

    double color{};

private:
    std::vector<Variation *> variations;
};
