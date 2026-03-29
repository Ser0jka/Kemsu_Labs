#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "headers.hpp"

using namespace std;

int** CreateMatr(int n, int m) {
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[m];
    }
    return M;
}

void FreeMatr(int** M, int n) {
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete[] M;
}

bool InputFileMatr(int** M, int n, int m) {
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

void OutputFileMatr(int** M, int n, int m) {
    ofstream f("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            f << M[i][j] << " ";
        f << endl;
    }
    f.close();
}

void InputDescMatr(int** M, int n, int m) {
    cout << "Enter elements for matrix " << n << "x" << m << ":" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
}

void OutputDescMatr(int** M, int n, int m) {
    cout << "Current Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(3) << M[i][j] << " ";
        cout << endl;
    }
}

void RandomMatr(int** M, int n, int m, int A, int B) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = rand() % (B - A + 1) + A;
}