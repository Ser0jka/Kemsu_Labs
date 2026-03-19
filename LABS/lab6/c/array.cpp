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

void swap(int& a, int& b){
    
    int temp = a;
    a = b;
    b = temp;
}

void smartSwap(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (i % 2 != 0) {
            for (int j = size - 1; j > i; j--) {
                swap(*(arr + j), *(arr + j - 1));
            }
        }
    }
}
