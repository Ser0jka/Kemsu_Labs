#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int generator(){
    ofstream fout("temp.txt");
    int count = 0;
    int n = -1;
    cout << "Введите число (0 = стоп): " << endl;
    while (n != 0){
        cin >> n;
        if (n != 0 && n % 3 == 0) {
            fout << n << "\n";
            count++;
        }
    }
    return count;
}

int main(){
    SetConsoleOutputCP(65001);
    
    int lenArr = generator();
    
    if (lenArr == 0) {
        cout << "\nНет чисел, кратных 3." << endl;
        return 0;
    }

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

    cout << "\nМассив: [";
    for (int i = 0; i < lenArr; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "]" << endl;

    delete[] arr;
    return 0;
}