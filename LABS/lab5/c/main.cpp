#include <iostream>
#include <windows.h>
#include "headers.hpp"
#include <cmath>
using namespace std;
//вариант 9. Вывести на экран все элементы массива, которые по модулю больше минимального 
// положительного, и находятся левее максимального отрицательного. 

int main() {
    SetConsoleOutputCP(65001);
    
    int lenArr = 0;
    generator(lenArr);

    if (lenArr > 0) {
        int* arr = makeArray(lenArr);
        readArrayFromFile(arr, lenArr, "temp.txt");

        int minPlus = 0;
        bool hasPlus = false;
        int maxMinus = 0;
        int maxMinusIndex = -1;
        bool hasMinus = false;

        for (int i = 0; i < lenArr; ++i) {
            if (arr[i] > 0) {
                if (!hasPlus || arr[i] < minPlus) {
                    minPlus = arr[i];
                }
                hasPlus = true;
            } else if (arr[i] < 0) {
                if (!hasMinus || arr[i] > maxMinus) {
                    maxMinus = arr[i];
                    maxMinusIndex = i;
                }
                hasMinus = true;
            }
        }
        
        if (!hasPlus) {
            cout << "В массиве нет положительных элементов." << endl;
        } else if (!hasMinus) {
            cout << "В массиве нет отрицательных элементов." << endl;
        } else {
            cout << "Элементы, которые по модулю больше " << minPlus 
                 << " и находятся левее " << maxMinus << ":" << endl;
            bool found = false;
            for (int i = 0; i < maxMinusIndex; ++i) {
                if (abs(arr[i]) > minPlus) {
                    cout << arr[i] << " ";
                    found = true;
                }
            } 
            if (!found) {
                cout << "Таких элементов не найдено." << endl;
            }
            cout << endl;
        }

        delete[] arr;
    } else {
        cout << "Массив пуст." << endl;
    }

}