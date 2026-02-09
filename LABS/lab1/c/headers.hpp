#pragma once

struct Point
{
    float x;
    float y;
};

struct Rectangle
{
    Point a;
    Point b;
    Point c;
    Point d;

    float get_square_on_first_quarter(Point a, Point b, Point c, Point d);
};

