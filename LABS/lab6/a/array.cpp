#include <iostream>
#include <fstream>
#include "array.hpp"
using namespace std;

int generator(){
    ofstream fout("temp.txt");
    int count = 0;
    int n = -1;
    cout << "Введите число (0 = стоп): " << endl;
    cin >> n;
    while (n != 0){
        fout << n << "\n";
        count++;
        cin >> n;
    }
    return count;
}

void printArray(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;
}

void swapFirstLast(int* arr, int size) {
    if (size < 2) return;
    int temp = *(arr);
    *(arr) = *(arr + size - 1);
    *(arr + size - 1) = temp;
}

void swapMaxMin(int* arr, int size) {
    int maxIdx = 0;
    int minIdx = 0;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *(arr + maxIdx)) {
            maxIdx = i;
        }
        if (*(arr + i) < *(arr + minIdx)) {
            minIdx = i;
        }
    }

    int temp = *(arr + maxIdx);
    *(arr + maxIdx) = *(arr + minIdx);
    *(arr + minIdx) = temp;
}