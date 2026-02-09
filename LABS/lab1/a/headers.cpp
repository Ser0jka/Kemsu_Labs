#include "headers.hpp"
#include <iostream>

int minus_div_7_counter(){
    int counter = 0;
    int crntNum = -1;
    while (crntNum < 0){
        std::cin >> crntNum;
        if (crntNum % 7 == 0) counter++;
    }
    return counter;
}