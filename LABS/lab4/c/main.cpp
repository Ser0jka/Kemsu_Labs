#include <iostream>
#include <windows.h>
#include "headers.hpp"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // Для поддержки русского языка в Windows
    
    int lenArr = 0;
    generator(lenArr);
    if (lenArr == 0) {
        cout << "\nНет чисел, кратных 3." << endl;
        return 0;
    }
    
    // Выделяем память под массив
    int* arr = makeArray(lenArr);
    
    // Читаем данные из файла
    readArrayFromFile(arr, lenArr);
    
    // Выводим результат
    cout << "\nМассив: ";
    printArray(arr, lenArr);
    
    // Очищаем память
    delete[] arr;
    
    return 0;
}