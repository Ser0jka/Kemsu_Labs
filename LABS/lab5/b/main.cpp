#include <iostream>
#include <windows.h>
#include "headers.hpp"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    
    int lenArr = 0;
    generator(lenArr);

    if (lenArr > 0) {
    int* arr = makeArray(lenArr);
        readArrayFromFile(arr, lenArr, "temp.txt");
        int minVal = arr[0];
        int minIdx = 0;
        for (int i = 1; i < lenArr; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
                minIdx = i;
            }
        }

        int start = 1;
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