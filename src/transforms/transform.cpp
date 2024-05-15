#include <spdlog/spdlog.h>

#include "transforms/transform.hpp"
#include "variations/variation.hpp"

Transform::Transform() = default;

Transform::Transform(const Transform &o)
    : a(o.a),
      b(o.b),
      c(o.c),
      d(o.d),
      e(o.e),
      f(o.f),
      color(o.color),
      variations(o.variations)
{
}

Transform::Transform(Transform &&o)
    : a(std::move(o.a)),
      b(std::move(o.b)),
      c(std::move(o.c)),
      d(std::move(o.d)),
      e(std::move(o.e)),
      f(std::move(o.f)),
      color(std::move(o.color)),
      variations(std::move(o.variations))
{
}

Transform::~Transform() = default;

auto Transform::operator=(const Transform &o) -> Transform &
{
    a = o.a;
    b = o.b;
    c = o.c;
    d = o.d;
    e = o.e;
    f = o.f;
    color = o.color;
    variations = o.variations;
    return *this;
}

auto Transform::compute(const std::array<double, 4> &xyc) const -> std::array<double, 4>
{
    const auto x = a * xyc[0] + b * xyc[1] + c;
    const auto y = d * xyc[0] + e * xyc[1] + f;
    auto result = std::array<double, 4>{x, y};
    for (const auto &v : variations)
    {
        auto value = v->compute(a, b, c, d, e, f, xyc);
        result[0] += value[0];
        result[1] += value[1];
    }

    result[2] = (xyc[2] + color) / 2.0;
    result[3] = xyc[3] + 1.0;

    return result;
}

auto Transform::add_variation(Variation *variation) -> void
{
    variations.push_back(variation);
}