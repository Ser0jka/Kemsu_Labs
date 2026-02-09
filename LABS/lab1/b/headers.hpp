#pragma once


struct Circle {
    int radius;
    int x;
    int y;

};

struct Line {
    int k;
    int b;
};

struct Point
{
    int x;
    int y;

};

bool is_point_upper(Line l, Point p);
float is_inner_circle(Circle c, Point p);
