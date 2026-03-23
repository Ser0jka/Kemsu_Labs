#include <math.h>
#include <time.h>
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

void f_merge(int *a,int n)
{
    int *a1=new int[n/2];
    int *a2=new int[n/2];
    for(int i=0;i<n/2;i++){
        a1[i]=a[i];
        a2[i]=a[n/2+i];
    }

    int *k1=a1, *k2=a2,k=0;

    for(int i=0;i<n;i++){
        if(*k1<*k2){
            a[k]=*k1;
            if(k1==a1+n/2-1) break;
            k1++;
            k++;
        }
        else{
            a[k]=*k2;
            if(k2==a2+n/2-1) break;
            k2++;
            k++;
        }
    }

    if(k1==a1+n/2-1){
        while(k2!=a2+n/2){
            k++;
            a[k]=*k2;
            k2++;
        }

        delete []a1;
        delete []a2;
        return;
    }

    if(k2==a2+n/2-1){
        while(k1!=a1+n/2){
            k++;
            a[k]=*k1;
            k1++;
        }
    }

    delete []a1;
    delete []a2;
}


void f_new_merge(int *a, int n) {
    int mid = n / 2;
    int *temp = new int[n];

    int i = 0;
    int j = mid;
    int k = 0;

    while (i < mid && j < n) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } 
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i < mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j < n) {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (int idx = 0; idx < n; idx++) {
        a[idx] = temp[idx];
    }

    delete[] temp;
}


void f_new_merge_div3(int *a, int n) {
    int n1 = n / 3;
    int n2 = 2 * n / 3;

    int *temp = new int[n];

    int i = 0;
    int j = n1;
    int l = n2;
    int k = 0;

    while (i < n1 && j < n2 && l < n) {
        if (a[i] <= a[j] && a[i] <= a[l]) {
            temp[k++] = a[i++];
        } else if (a[j] <= a[i] && a[j] <= a[l]) {
            temp[k++] = a[j++];
        } else {
            temp[k++] = a[l++];
        }
    }
    
    while (i < n1 && j < n2) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (j < n2 && l < n) {
        if (a[j] <= a[l]) temp[k++] = a[j++];
        else temp[k++] = a[l++];
    }
    while (i < n1 && l < n) {
        if (a[i] <= a[l]) temp[k++] = a[i++];
        else temp[k++] = a[l++];
    }


    while (i < n1) temp[k++] = a[i++];
    while (j < n2) temp[k++] = a[j++];
    while (l < n)  temp[k++] = a[l++];


    for (int idx = 0; idx < n; idx++) {
        a[idx] = temp[idx];
    }

    delete[] temp;
}