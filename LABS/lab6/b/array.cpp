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
        cout << *(arr + i);
    }
    cout << "]" << endl;
}

void swapKthMax(int* arr, int size, int k) {
    if (k < 0 || k >= size)return;
    int* maxPtr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *maxPtr) maxPtr = arr + i;
    }
    int temp = *(arr + k);
    *(arr + k) = *maxPtr;
    *maxPtr = temp;
}
