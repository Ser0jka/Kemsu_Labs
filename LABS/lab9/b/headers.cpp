#include <iostream> 
#include <iomanip>
#include "headers.hpp"
using namespace std;

void OutputDescMatr(int** a, int n, int m) {
    cout << "Current Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(2) << a[i][j] << " ";
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int n) {
    if (matrix == nullptr || n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

int** createAndFillDiagonalMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (i == j) {
                matrix[i][j] = i + 1; // на главной диагонали стоят числа от 1 до n
            } else {
                matrix[i][j] = 0; 
            }
        }
    }
    return matrix;
}
void calculateAverageByRows(int** matrix, int n) {
    if (n <= 0) {
        std::cout << "Невозможно вычислить среднее для пустой матрицы." << endl;
        return;
    }

    cout << "\n--- Вычисление среднего арифметического по строкам" << endl;
    for (int i = 0; i < n; i++) {
        long long sum = 0; 
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j]; 
        }
        double average = (double)sum / n;
        cout << "Среднее для строки " << (i + 1) << ": " << average << endl;
    }
}
void countZerosByColumns(int** matrix, int n) {
    if (n <= 0) {
        cout << "Невозможно посчитать нули для пустой матрицы." << endl;
        return;
    }
    cout << "\n--- Подсчет нулей по столбцам" << endl;
    for (int j = 0; j < n; j++) { 
        int zeroCount = 0;
        for (int i = 0; i < n; i++) { 
            if (matrix[i][j] == 0) { 
                zeroCount++; 
            }
        }
        cout << "Количество нулей в столбце " << (j + 1) << ": " << zeroCount << endl;
    }
}