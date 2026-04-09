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
    int c,i_min_a;
    for(int k=0;k<n;k++){
        i_min_a=k;

        for(int i=k+1;i<n;i++){
            if( a[i] < a[i_min_a] ){
                i_min_a=i;
            } 
        }  

        c=a[k];
        a[k]=a[i_min_a];
        a[i_min_a]=c;
    }
}


void mergeSort(int* a, int n){
    int mid = n / 2;

    int k1 = 0;
    int k2 = mid;

    while (k1 < mid && k2 < n){
        if (a[k1] <= a[k2]){
            k1 += 1;
        }
        else{
            // int temp = a[k2];
            // for (int i = k2; i > k1; i--) {
            //     a[i] = a[i - 1];
            // }
            // a[k1] = temp;
            // k1++;
            // k2++;
            // mid++; 

            // std::rotate(a + k1, a + k2, a + k2 + 1);
            // k1++;
            // k2++;
            // mid++; 

            int temp = a[k1];
            a[k1] = a[k2];
            int j = k2;
            while (j < n - 1 && temp > a[j + 1]) {
                a[j] = a[j + 1];
                j++;
            }
            a[j] = temp;
            k1++;
        }
    }
}



