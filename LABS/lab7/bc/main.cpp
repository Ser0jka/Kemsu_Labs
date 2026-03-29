#include <iostream>
#include "headers.hpp"
using namespace std;

int main(){
    int sizes[] = {10, 100, 1000};
    int b = -10, c = 10;

    for (int k = 0; k < 3; k++) {
        int n = sizes[k];
        int comparisons = 0, swaps = 0;
        int *a = new int[n];
        
        // f(a, n, b, c);
        f_random(a, n, b, c);

        cout << "Array size: " << n << endl;
        // bubleSort(a, n, comparisons, swaps);
        // selectionSort(a, n, comparisons, swaps);
        insertionSort(a, n, comparisons, swaps);
        // shellSort(a, n, comparisons, swaps);


        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "--------------------------" << endl;
        
        delete[] a;
    }
}