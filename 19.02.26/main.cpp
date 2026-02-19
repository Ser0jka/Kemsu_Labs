#include <iostream>

unsigned long long factorial(int n){
    unsigned long long result = 1;
    for(int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

void fillArray(unsigned long long* array, size_t n){
    for(size_t index = 0; index < n; ++index){
        array[index] = factorial(index + 1);
    }
}

void printArray(unsigned long long* array, size_t n){
    std::cout << "[";
    for (size_t index = 0; index < n; ++index){
        std::cout << array[index];
        if (index < n - 1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;  // Добавлено закрытие массива и перевод строки
}

int main()
{
    size_t n;
    std::cout << "n = ";
    std::cin >> n;

    unsigned long long* array = new unsigned long long[n];
    fillArray(array, n);
    printArray(array, n);
    delete[] array;
}