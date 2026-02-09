#include "headers.hpp"
#include <iostream>

int main(){
    std::cout << "Введите n в терминал" << std::endl;
    int n = minus_div_7_counter();
    std::cout << "Кол-во чисел (n%7==0 and n<0) -> " << n << std::endl;
}