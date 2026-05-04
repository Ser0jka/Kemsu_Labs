#include <math.h>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

void f(int *a,int n,int b,int c){
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=1.*rand()/RAND_MAX*(c-b)+b;
}

void f_sort(int *a,int n){
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}


// void mergeSort(int* a, int n){
//     int mid = n / 2;

//     int k1 = 0;
//     int k2 = mid;

//     while (k1 < mid && k2 < n){
//         if (a[k1] <= a[k2]){
//             k1 += 1;
//         }
//         else{
//             // int temp = a[k2];
//             // for (int i = k2; i > k1; i--) {
//             //     a[i] = a[i - 1];
//             // }
//             // a[k1] = temp;
//             // k1++;
//             // k2++;
//             // mid++; 

//             // std::rotate(a + k1, a + k2, a + k2 + 1);
//             // k1++;
//             // k2++;
//             // mid++; 

//             int temp = a[k1];
//             a[k1] = a[k2];
//             int j = k2;
//             while (j < n - 1 && temp > a[j + 1]) {
//                 a[j] = a[j + 1];
//                 j++;
//             }
//             a[j] = temp;
//             k1++;
//         }
//     }
// }

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSort(int* a, int n){

    int mid = n / 2;
    int k1 = 0;
    int k2 = mid;
    int k3 = -1;
    bool k3_on = false;

    if (a[mid - 1] <= a[mid]) {
        return; 
    }

    if (n < 16) {
        f_sort(a, n);
        return;
    }

    while (k1 < mid && k2 < n && k3 != k2 - 1){
        if (a[k1] <= a[k2]){
            k1++;
        }
        else{
            k3 = k2;
            k2++;
        }
    }

    if (k3 != -1) {
        while (k1 < mid) {
            bool k2_valid = (k2 < n);
            
            if (!k2_valid || a[k3] <= a[k2]) {
                if (a[k1] <= a[k3]) {
                    k1++;
                } else {
                    swap(&a[k1], &a[k3]);
                    k1++;
                    k3_on = true;
                }
            } 
            else {
                if (a[k1] <= a[k2]) {
                    k1++;
                } else {
                    swap(&a[k1], &a[k2]);
                    k1++;
                    k2++;
                    k3_on = true;
                }
            }
        }

        if(k3_on){
            mergeSort(a + mid, n - mid); 
        }
        
    }
}