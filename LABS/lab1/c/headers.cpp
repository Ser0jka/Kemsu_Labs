#include "headers.hpp"
#include <algorithm> // для std::min и std::max

float Rectangle::get_square_on_first_quarter(Point a, Point b, Point c, Point d) {
    // 1. Находим общие границы прямоугольника
    float xMin = std::min({a.x, b.x, c.x, d.x});
    float xMax = std::max({a.x, b.x, c.x, d.x});
    float yMin = std::min({a.y, b.y, c.y, d.y});
    float yMax = std::max({a.y, b.y, c.y, d.y});

    // 2. Находим ширину и высоту части, попавшей в I четверть (x > 0, y > 0)
    float width = std::max(0.0f, xMax) - std::max(0.0f, xMin);
    float height = std::max(0.0f, yMax) - std::max(0.0f, yMin);

    return width * height;
}
