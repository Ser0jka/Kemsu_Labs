//----------vect.cpp-----------------

#include <iostream>
#include "vect.hpp"

using namespace std;

// Реализация ввода вектора
void InputDescVect(double* v, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> v[i];
    }
}

// Реализация вывода вектора
void OutputDescVect(double* v, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}
