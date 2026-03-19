#include <iostream>
#include <fstream>
#include "array.hpp"
using namespace std;



int main(){
    
    int lenArr = generator();

    int* arr = new int[lenArr];

    ifstream fin("temp.txt");
    if (fin.is_open()) {
        int num;
        for (int i = 0; i < lenArr; i++) {
            fin >> num;
            arr[i] = num;
        }
        fin.close();
        remove("temp.txt");
    }

    cout << "\nИсходный массив: ";
    printArray(arr, lenArr);

    int k = 0;
    cout << "Введите k: ";
    cin >> k;
    swapKthMax(arr, lenArr, k-1);

    cout << "После swapKthMax: ";
    printArray(arr, lenArr);


    delete[] arr;
}