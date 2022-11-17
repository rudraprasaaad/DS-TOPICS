#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){  
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++)
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
    }
}

void bubbleRecursive(int arr[], int n){
    if(n == 0 || n == 1){
        return;
    }
    for(int i = 0; i < n -1; i++){
        if(arr[i] > arr[i + 1])
            swap(arr[i], arr[i+1]);
    }
    bubbleRecursive(arr, n-1);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {2, 8, 5, 4, 6};
    int n = sizeof(arr) /  sizeof(arr[0]);
    // bubbleSort(arr, n);
    bubbleRecursive(arr, n);
    cout<<"Sorted array: ";
    printArray(arr,n);
}