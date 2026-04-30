#include "headers.hpp"

double determinant(double A[3][3]) {
    double det = 1.0;

    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            double koefficent = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= koefficent * A[i][j];
            }
        }
        det *= A[i][i];
    }
    
    return det;
}
