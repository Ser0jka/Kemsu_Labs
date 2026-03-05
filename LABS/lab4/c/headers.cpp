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
        if (n != 0 && n % 3 == 0) {
            fout << n << "\n";
            lenArr++;
        }
    }
    fout.close();  // Явно закрываем файл
}

int* makeArray(int& lenArr){
    int* arr = new int[lenArr];
    return arr;
}

void readArrayFromFile(int* arr, int size) {
    ifstream fin("temp.txt");
    if (fin.is_open()) {
        for (int i = 0; i < size; i++) {
            fin >> arr[i];
        }
        fin.close();
        remove("temp.txt");  // Удаляем временный файл
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