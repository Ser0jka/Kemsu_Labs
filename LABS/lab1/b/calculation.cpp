#include <iostream>
#include "headers.hpp"

int main(){
    Circle a{3, 2, 1};
    Circle b{1, 2, 1};
    Line l{-1, 3};

    int x = 0; 
    std::cout << "x = ";
    std::cin >> x;

    int y = 0; 
    std::cout << "y = ";
    std::cin >> y;

    Point p{x,y};

    if (is_point_upper(l,p) && is_inner_circle(a,p) && !is_inner_circle(b,p)){
        std::cout << "точка p в зоне" << std::endl;
    }
    else{
        std::cout << "точка p не в зоне" << std::endl;
    }
}