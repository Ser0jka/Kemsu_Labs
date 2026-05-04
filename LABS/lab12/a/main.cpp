#include "headers.hpp"

int main() {
    double A[3][3] = {
        {2, 4, 1},
        {5, 2, 1},
        {2, 3, 4}
    };
    double b[3] = {36, 47, 37};
    double x[3] = {0};
    double A_copy[3][3];
    double b_copy[3];
    for(int i=0; i<3; i++) {
        b_copy[i] = b[i];
        for(int j=0; j<3; j++) A_copy[i][j] = A[i][j];
    }

    solve(A_copy, b_copy, x);

    std::cout << "Result:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }

    check(A, b, x);

    return 0;
}
