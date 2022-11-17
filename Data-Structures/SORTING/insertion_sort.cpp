#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }   
}

void insertionRecurisve(int arr[], int n){
    if(n<=1)
        return;

    insertionRecurisve(arr, n-1);
    int temp = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {5, 1, 8 ,20, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // insertionSort(arr,n);   
    insertionRecurisve(arr, n);
    cout<<"After insertion sort: ";
    printArray(arr, n);
    return 0;
}