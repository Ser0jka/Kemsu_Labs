#include "headers.hpp"

int main() {
    double A[3][3] = {
        {5, 2, 0},
        {4, 7, 1},
        {0, 6, 8}
    };

    double result = determinant(A);

    std::cout << "Matrix A:" << std::endl;
    std::cout << "5 2 0" << std::endl;
    std::cout << "4 7 1" << std::endl;
    std::cout << "0 6 8" << std::endl;
    
    std::cout << "\nDeterminant = " << result << std::endl;

    return 0;
}
