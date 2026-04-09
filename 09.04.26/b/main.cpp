#include <iostream>
#include "headers.hpp"
using namespace std;

int main(){
    int n, c = 0, b = 10;
    cout << "n: ";
    cin >> n;

    int **a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    
    generateMatrix(a, n, c, b);

    int max = c-1;
    int pos = n-1;
    int x,y;
    for (int j = n-1; j > n/2-1; j--){
        int i = pos;
        while (i < n-1){
            if (a[i][j] > max){
                max = a[i][j];
                x = i;
                y = j;
            }
            i++;
        }
        pos--;
    }

    for (int j = n/2-1; j < n; j++){
        int i = pos;
        while (i < n-1){
            if (a[i][j] > max){
                max = a[i][j];
                x = i;
                y = j;
            }
            i++;
        }
        pos++;
    }

    cout << "Max in shape " << max << endl;
    cout << "Pos: " << x << ", " << y << endl;

    OutputDescMatr(a, n, n);

    FreeMatr(a, n);
    a = NULL;
}