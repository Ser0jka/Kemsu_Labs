#include "headers.hpp"
#include <stdlib.h>
#include <time.h>


void f(int *a,int n,int b,int c){
    for(int i=0;i<n;i++)
        a[i] = n - i;
}

void f_random(int *a,int n,int b,int c){
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=1.*rand()/RAND_MAX*(c-b)+b;
}


void swap(int array[], int index){
    
    int temp = array[index];
    array[index] = array[index+1];
    array[index+1] = temp;
}

void bubleSort(int *a, int n, int &comparisons, int &swaps){
    comparisons = 0;
    swaps = 0;
    for (int size = n; size > 1; size--){
        for (int i = 0; i < size - 1; i++){
            comparisons++;
            if (a[i] > a[i+1]){
                swap(a, i);
                swaps++;
            }
        }
    }
}

void selectionSort(int *a, int n, int &comparisons, int &swaps){
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
        swaps++;
    }
}

void insertionSort(int *a, int n, int &comparisons, int &swaps){
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && (++comparisons && a[j] > key)) {
            a[j + 1] = a[j];
            j = j - 1;
            swaps++;
        }
        a[j + 1] = key;
    }
}

void shellSort(int *a, int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && (++comparisons && a[j - gap] > temp); j -= gap) {
                a[j] = a[j - gap];
                swaps++;
            }
            a[j] = temp;
        }
    }
}