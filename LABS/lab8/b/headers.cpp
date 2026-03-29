#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "headers.hpp"

using namespace std;

bool InputFileMatr(double** M, int n, int m) {
    ifstream f("input.txt");
    if (!f) {
        cout << "Error: file not found" << endl;
        return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!(f >> M[i][j])) {
                cout << "Error: not enough data in file" << endl;
                f.close();
                return false;
            }
    f.close();
    return true;
}

void OutputFileMatr(double** M, int n, int m) {
    ofstream f("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            f << M[i][j] << " ";
        f << endl;
    }
    f.close();
}

void InputDescMatr(double** M, int n, int m) {
    cout << "Enter elements for matrix " << n << "x" << m << ":" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
}

void OutputDescMatr(double** M, int n, int m) {
    cout << "Current Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << M[i][j] << " ";
        cout << endl;
    }
}

void RandomMatr(double** M, int n, int m, double A, double B) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = A + (double)rand() / RAND_MAX * (B - A);
}