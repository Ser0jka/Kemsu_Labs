#include <iostream>
#include <fstream>
#include "headers.hpp"
using namespace std;

void generator(int& lenMinusArr, int& lenPlusArr) {
    ofstream fout("tempAll.txt");
    int n = -1;
    lenMinusArr = 0;
    lenPlusArr = 0;
    
    cout << "Введите число (0 = стоп): " << endl;
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        fout << n << "\n";
        if (n < 0) lenMinusArr++;
        if (n > 0) lenPlusArr++;
    }
    fout.close();
}

int* makeArray(int& lenArr){
    return new int[lenArr];
}

void readArrayFromFile(int* arr, int size, string fileName) {
    ifstream fin(fileName);
    if (fin.is_open()) {
        for (int i = 0; i < size; i++) {
            fin >> arr[i];
        }
        fin.close();
        remove(fileName.c_str());
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

void MaxMinus(int* arr, int& maxMinusNum, int& pos, int& lenMinusArr) {
    bool found = false;
    // Ищем первое отрицательное для инициализации
    for (int i = 0; i < lenMinusArr; i++) {
        if (arr[i] < 0) {
            maxMinusNum = arr[i];
            pos = i;
            found = true;
            break;
        }
    }

    if (found) {
        for (int i = 0; i < lenMinusArr; i++) {
            if (arr[i] < 0 && arr[i] > maxMinusNum) {
                maxMinusNum = arr[i];
                pos = i;
            }
        }
        cout << "\nМакс. отрицательное число: " << maxMinusNum << " и его индекс: " << pos << endl;
    }
}

void MinPlus(int* arr, int& MinPlusNum, int& pos, int& lenPlussArr) {
    bool found = false;
    for (int i = 0; i < lenPlussArr; i++) {
        if (arr[i] > 0) {
            MinPlusNum = arr[i];
            pos = i;
            found = true;
            break;
        }
    }

    if (found) {
        for (int i = 0; i < lenPlussArr; i++) {
            if (arr[i] > 0 && arr[i] < MinPlusNum) {
                MinPlusNum = arr[i];
                pos = i;
            }
        }
        cout << "\nМин. положительное число: " << MinPlusNum << " и его индекс: " << pos << endl;
    }
}