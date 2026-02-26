#include <iostream>
#include <windows.h>  // Для SetConsoleOutputCP
#include <fstream>
using namespace std;

int waiting_n(){
    int n = -1;
    while (n <= 0){
        cout << "Введите положительное число: " << endl;
        cin >> n;
    }
    return n;
}

int main(){
    SetConsoleOutputCP(65001);

    int n = waiting_n();
    cout << "Вы ввели число: " << n << endl;


    int* arr = new int[n];

    cout << "\n[1] Ввод с экрана" << endl;
    cout << "[2] Ввод из файла" << endl;
    cout << "[3] Случайные числа" << endl;
    cout << "Выбор: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Введите " << n << " чисел:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;
        }
        case 2: {
            ifstream fin("input.txt");
            if (fin.is_open()) {
                for (int i = 0; i < n; i++) {
                    fin >> arr[i];
                }
                fin.close();
                cout << "Данные прочитаны из input.txt" << endl;
            } else {
                cout << "Файл не найден! Заполняем нулями." << endl;
                for (int i = 0; i < n; i++) arr[i] = 0;
            }
            break;
        }
        case 3: {
            // srand(time(0));
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 100;
            }
            break;
        }
        default:
            cout << "Вы не выбрали один из трех вариантов" << endl;
    }

    cout << "\nМассив: [";
    for (int i = 0; i < n; i++) {
        if (!(i + 1 < n)){cout << arr[i];}
        else{cout << arr[i] << ", ";}
        
    }
    cout << "]" << endl;

    ofstream fout("result.txt");
    fout << "[";
    for (int i = 0; i < n; i++) {
        if (!(i + 1 < n)){fout << arr[i];}
        else{fout << arr[i] << ", ";}
    }
    fout << "]" << endl;
    fout.close();
    cout << "Результат сохранен в result.txt" << endl;


    delete[] arr;
}