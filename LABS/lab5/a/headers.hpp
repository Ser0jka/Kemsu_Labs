#pragma once
#include <string>

// Функция для генерации чисел и записи в общий файл
void generator(int& lenMinusArr, int& lenPlusArr);

int* makeArray(int& lenArr);

// Функция для чтения массива из файла
void readArrayFromFile(int* arr, int size, std::string fileName);

// Функция для вывода массива на экран
void printArray(const int* arr, int size);

// Функция для вывода Максимального отрицательного числа и его индекса
void MaxMinus(int* arr, int& maxMinusNum, int& pos, int& lenMinusArr);

// Функция для вывода Минимального положительного числа и его индекса
void MinPlus(int* arr, int& MinPlusNum, int& pos, int& lenPlussArr);