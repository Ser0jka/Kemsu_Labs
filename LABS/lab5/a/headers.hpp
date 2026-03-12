#pragma once
#include <string>

// функция для генерации чисел и записи в общий файл
void generator(int& lenMinusArr, int& lenPlusArr);

int* makeArray(int& lenArr);

// функция для чтения массива из файла
void readArrayFromFile(int* arr, int size, std::string fileName);

// функция для вывода массива на экран
void printArray(const int* arr, int size);

// функция для вывода максимального отрицательного числа и его индекса
void MaxMinus(int* arr, int& maxMinusNum, int& pos, int& lenMinusArr);

// функция для вывода минимального положительного числа и его индекса
void MinPlus(int* arr, int& MinPlusNum, int& pos, int& lenPlussArr);