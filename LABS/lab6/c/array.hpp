#pragma once
#include <string>

// функция для генерации чисел и записи в общий файл
int generator();

// вывод массива
void printArray(int* arr, int size);

//свап
void swap(int& a, int& b);

//свап k-того и максимального элемента массива
void smartSwap(int* arr, int size);
