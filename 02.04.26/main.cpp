#include <iostream>
#include "headers.hpp"
using namespace std;

int main(){
    int n;
    cout << "Введите n: ";
    cin >> n;

    int **a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    
    // generateMatrix(a, n);
    generateA1(a,n);
    OutputDescMatr(a, n, n);
    cout << "SrSumCol2: "<< srSumCol(a, n, 2) << endl;
    cout << "\n";

    generateA2(a,n);
    OutputDescMatr(a, n, n);
    cout << "CountZerosRow2: "<< countZeros(a, n, 2) << endl;
    cout << "\n";

    generateA3(a,n);
    OutputDescMatr(a, n, n);
    cout << "PositiveRows: "<< "1" << endl;
    cout << "\n";

    generateA4(a,n);
    OutputDescMatr(a, n, n);
    cout << "del3Cols: "<< "1, " << n << endl;
    cout << "\n";

    // int sum = 0;
    // for (int i = 1; i < n+1; i++){
    //     if (i % 2 != 0){
    //         sum += i*n;
    //     }
    // }
    // cout << "sum odds: " << sum << endl;

    FreeMatr(a, n);
    a = NULL;
}