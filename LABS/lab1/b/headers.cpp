#include "headers.hpp"
#include <cmath>

bool is_point_upper(Line l, Point p){
    return p.y > (l.k * p.x + l.b);;
}

float is_inner_circle(Circle c, Point p){
    int dx = p.x - c.x;
    int dy = p.y - c.y;
    return (dx * dx + dy * dy) <= (c.radius * c.radius);
}

