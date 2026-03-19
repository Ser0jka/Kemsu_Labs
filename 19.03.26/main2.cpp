#include <iostream>
#include <ctime>

void generateArray(int array[], int size, int minVal, int maxVal) {
    for (int i = 0; i < size; i++) {
        array[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void swap(int& a, int& b){
    
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    srand(time(0));
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* a = new int[n];
    generateArray(a, n, -10, 10);

    for (int size = n; size > 1; size--){
        for (int i = 0; i < size - 1; i++){
            if (a[i] < a[i+1]){
                swap(a[i], a[i+1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    delete[] a;
}