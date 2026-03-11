#include <iostream>
#include <windows.h>
#include "headers.hpp"
using namespace std;

int main() {
    SetConsoleOutputCP(65001); 

    int lenMinusArr = 0;
    int lenPlusArr = 0;
    
    // Генерируем данные в один файл "tempAll.txt"
    generator(lenMinusArr, lenPlusArr);

    int totalLen = lenMinusArr + lenPlusArr;

    if (totalLen == 0) {
        cout << "\nМассив пуст." << endl;
    } else {
        // Создаем ОДИН общий массив
        int* arr = makeArray(totalLen);
        
        // Читаем всё в один массив
        readArrayFromFile(arr, totalLen, "tempAll.txt");
        
        cout << "\nОбщий массив: ";
        printArray(arr, totalLen);

        // Работаем с отрицательными
        if (lenMinusArr == 0) {
            cout << "\nОшибка, нет отрицательных чисел." << endl;
        } else {
            int maxMinusNum = 0; 
            int pos = 0;
            MaxMinus(arr, maxMinusNum, pos, totalLen);
        }

        // Работаем с положительными
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