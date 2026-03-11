#include <iostream>
#include <windows.h>
#include "headers.hpp"
using namespace std;
//вариант 9. Найти количество чисел, расположенных между первым и минимальным элементами массива.

int main() {
    SetConsoleOutputCP(65001);  // Для поддержки русского языка в Windows
    
    int lenArr = 0;
    generator(lenArr);

    if (lenArr > 0) {
    int* arr = makeArray(lenArr);
        // Читаем данные из файла
        readArrayFromFile(arr, lenArr, "temp.txt");
        int minVal = arr[0];
        int minIdx = 0;
        for (int i = 1; i < lenArr; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
                minIdx = i;
            }
        }

        int start = 1; // Индекс после первого элемента (индекс 0)
        int end = minIdx;
        
        if (start < end) {
            cout << "Элементы между первым и минимальным: ";
            for (int i = start; i < end; i++) {
                cout << arr[i] << " ";
            }
            cout << "\nКоличество элементов: " << (end - start) << endl;
        } else {
            cout << "\nМежду первым и минимальным элементами нет чисел." << endl;
        }

        delete[] arr;
    }

    
}