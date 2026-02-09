#include <iostream>
#include "headers.hpp"

int main() {
    Point p1 = {-2.0, -1.0}; 
    Point p2 = { 3.0, -1.0};
    Point p3 = { 3.0,  4.0};
    Point p4 = {-2.0,  4.0};

    Rectangle rect;
    rect.a = p1;
    rect.b = p2;
    rect.c = p3;
    rect.d = p4;

    float area = rect.get_square_on_first_quarter(rect.a, rect.b, rect.c, rect.d);

    // 4. Вывод результата
    std::cout << "Площадь в I четверти: " << area << std::endl;

}
