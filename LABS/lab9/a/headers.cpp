#include <iostream>
#include <iomanip>
#include "headers.hpp"

using namespace std;

void generateMatrix(int** a,int n){

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = i+1;
}

void generateA1(int** a, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = i+1;

    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < n-1; j++)
                a[i][j] = 0;
}


void generateA2(int** a, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = 1;

    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < n-1; j++)
                a[i][j] = 0;
}

void generateA3(int** a, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = 0;

    for (int i = 0; i < n; i++){
        a[i][0] = 1;
        a[i][n-1] = -1;
    }
}

void generateA4(int** a, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
                a[i][j] = 0;

    for (int j = 0; j < n; j++){
        a[0][j] = 3;
        a[n-1][j] = 3*n;
    }
}

double srSumCol(int** a, int n, int k){
    int sum = 0;
    for (int j = 0; j < n; j++){
        sum += a[k-1][j];
    }
    return sum / n;
}

int countZeros(int**a, int n, int k){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (a[i][k-1] == 0){
            count += 1;
        }
    }
    return count;
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