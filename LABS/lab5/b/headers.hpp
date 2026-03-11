#pragma once
#include <string>

// Функция для генерации чисел и записи в файл
// Возвращает количество записанных чисел
void generator(int& lenArr);

int* makeArray(int& lenArr);

// Функция для чтения массива из файла
// Принимает указатель на массив и его размер
void readArrayFromFile(int* arr, int size, std::string fileName);

// Функция для вывода массива на экран
void printArray(const int* arr, int size);

