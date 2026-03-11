#include <iostream>
#include <fstream>
#include "headers.hpp"
using namespace std;

void generator(int& lenArr) {
    ofstream fout("temp.txt");
    int n = -1;
    lenArr = 0;
    
    cout << "Введите число (0 = стоп): " << endl;
    while (n != 0) {
        cin >> n;
        fout << n << "\n";
        lenArr++;
    }
    fout.close();
}

int* makeArray(int& lenArr){
    int* arr = new int[lenArr];
    return arr;
}

void readArrayFromFile(int* arr, int size, string fileName) {
    ifstream fin(fileName);
    if (fin.is_open()) {
        for (int i = 0; i < size; i++) {
            fin >> arr[i];
        }
        fin.close();
        remove(fileName.c_str());  // Удаляем временный файл
    }
}

void printArray(const int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;
}