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

    smartSwap(arr, lenArr);
    cout << "После smartSwap: ";
    printArray(arr, lenArr);


    delete[] arr;
}