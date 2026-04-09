#include <iostream>
#include "headers.hpp"
using namespace std;

int main(){
    int n, k, c = 0, b = 10;
    cout << "n: ";
    cin >> n;

    cout << "k: ";
    cin >> k;

    int **a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    
    generateMatrix(a, n, c, b);

    int max = c-1;
    for (int j = 0; j < n; j++){
        if (a[k][j] > max)
            max = a[k][j];
    }
    cout << "Max in row " << k+1 << ": " << max << endl;

    int min = b+1;
        for (int i = 0; i < n; i++){
            if (a[i][k] < min)
                min = a[i][k];
        }
    cout << "Min in col " << k+1 << ": " << min << endl;

    OutputDescMatr(a, n, n);

    FreeMatr(a, n);
    a = NULL;
}