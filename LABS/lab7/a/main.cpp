#include <iostream>
#include "headers.hpp"
using namespace std;

int main() {
    int n = 0, b = -10, c = 10;
    cout << "Enter n: ";
    cin >> n;

    int *a = new int[n];
    f(a, n, b, c);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int choice;
    cout << "(1 - Selection, 2 - Insertion):";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(a, n);
            break;
        case 2:
            insertionSort(a, n);
            break;
    }

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    delete[] a;
}