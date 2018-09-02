#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    a+=b;
    b = a-b;
    a-=b;
}

void bubbleSort(int a[], int n){
    bool swapped;
    for(int i =0;i<n-1;i++){
        swapped = 0;
        for(int j =0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                swapped = 1;
            }
        }
        if(!swapped)
            break;
    }   
}
void printArray(int a[], int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
