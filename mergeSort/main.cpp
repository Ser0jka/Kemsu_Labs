#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include "headers.hpp"
using namespace std;

int main() {
    
    int n = 0, b = 0, c = 100000;
    cout << "Enter n (or press Enter for 100000): ";
    string input;
    getline(cin, input);
    if (input.empty()) {
        n = 100000;
    } else {
        n = stoi(input);
    }

    int *a = new int[n];
    f(a, n, b, c);

    auto s1 = std::chrono::steady_clock::now();
    f_sort(a, n / 2);
    f_sort(a + n / 2, n / 2);
    mergeSort(a, n);
    auto e1 = std::chrono::steady_clock::now();
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds>(e1 - s1).count();
    cout << fixed << setprecision(9);
    cout << "time: " << t1 / 1e9 << " sec" << endl;


    cout << "first 10 elements: ";
    for(int i = 0; i < (n < 10 ? n : 10); i++) cout << a[i] << " ";
    cout << endl;
}