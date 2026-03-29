#include "headers.hpp"
#include <stdlib.h>
#include <time.h>


void f(int *a,int n,int b,int c){
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=1.*rand()/RAND_MAX*(c-b)+b;
}

void selectionSort(int *a,int n){
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}

void insertionSort(int *a, int n){
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

