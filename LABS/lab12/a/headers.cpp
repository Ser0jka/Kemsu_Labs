#include "headers.hpp"
#include <cmath>

void solve(double A[3][3], double b[3], double x[3]) {

    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            double koefficent = A[k][i] / A[i][i];
            b[k] -= koefficent * b[i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= koefficent * A[i][j];
            }
        }
    }

    for (int i = 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
}

void check(double A[3][3], double b[3], double x[3]) {
    std::cout << "\n--- Proverka ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        double res = A[i][0]*x[0] + A[i][1]*x[1] + A[i][2]*x[2];
        std::cout << "Uravnenie " << i + 1 << ": " << res << " == " << b[i] << std::endl;
    }
}
