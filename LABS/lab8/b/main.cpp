#include <iostream>
#include "headers.hpp"

using namespace std;

int main() {
    int n, m;

    do {
        cout << "Enter matrix size (n and m): ";
        cin >> n >> m;
        if (n <= 0 || m <= 0)
            cout << "Invalid input! Please enter positive numbers." << endl;
    } while (n <= 0 || m <= 0);

    double **a = new double*[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];

    cout << "------Input Menu------" << endl;
    cout << "1. Screen input" << endl;
    cout << "2. File input" << endl;
    cout << "3. Random input" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        InputDescMatr(a, n, m);
    } 
    else if (choice == 2) {
        if (!InputFileMatr(a, n, m)) {
            cout << "Switching to screen input..." << endl;
            InputDescMatr(a, n, m);
        }
    } 
    else if (choice == 3) {
        double A, B;
        cout << "Enter range A and B: ";
        cin >> A >> B;
        RandomMatr(a, n, m, A, B);
    }

    OutputDescMatr(a, n, m);
    OutputFileMatr(a, n, m);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    a = NULL;
}