#include <iostream>
#include <iomanip>
#include "headers.hpp"

using namespace std;

void generateMatrix(int** a,int n, int c, int b){

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = 1.*rand()/RAND_MAX*(c-b)+b;;
}

void OutputDescMatr(int** a, int n, int m) {
    cout << "Current Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(2) << a[i][j] << " ";
        cout << endl;
    }
}

void FreeMatr(int** M, int n) {
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
}