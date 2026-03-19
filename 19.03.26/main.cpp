#include <iostream>

void swap(int array[], int index){
    
    int temp = array[index];
    array[index] = array[index+1];
    array[index+1] = temp;
}


int main(){
    const int arraySize = 6;
    int a[arraySize] = {1,5,23,9,100,0};

    for (int size = arraySize; size > 1; size--){
        for (int i = 0; i < size - 1; i++){
            if (a[i] > a[i+1]){
                swap(a, i);
            }
        }
    }

    for (int i = 0; i < arraySize; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}