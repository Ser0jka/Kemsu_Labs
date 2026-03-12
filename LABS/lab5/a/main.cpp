#include <iostream>
#include <windows.h>
#include "headers.hpp"
using namespace std;

int main() {
    SetConsoleOutputCP(65001); 

    int lenMinusArr = 0;
    int lenPlusArr = 0;
    
    generator(lenMinusArr, lenPlusArr);

    int totalLen = lenMinusArr + lenPlusArr;

    if (totalLen == 0) {
        cout << "\nМассив пуст." << endl;
    } else {
        int* arr = makeArray(totalLen);
        
        readArrayFromFile(arr, totalLen, "tempAll.txt");
        
        cout << "\nОбщий массив: ";
        printArray(arr, totalLen);

        if (lenMinusArr == 0) {
            cout << "\nОшибка, нет отрицательных чисел." << endl;
        } else {
            int maxMinusNum = 0; 
            int pos = 0;
            MaxMinus(arr, maxMinusNum, pos, totalLen);
        }

        if (lenPlusArr == 0) {
            cout << "\nОшибка, нет положительных чисел." << endl;
        } else {
            int MinPlusNum = 0;
            int pos = 0;
            MinPlus(arr, MinPlusNum, pos, totalLen);
        }

        delete[] arr;
    }

    return 0;
}