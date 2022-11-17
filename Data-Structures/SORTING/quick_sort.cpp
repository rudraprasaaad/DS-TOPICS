#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //element to put at the correct position in an array
    int i = (low - 1);

    for(int j=low; j <= high-1; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partitionLeft(int arr[], int low, int high){
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j],arr[low]);
    return j; 
}

void quickSort(int arr[], int low, int high){

    if(low>=high)   //base condition
        return;
    
    // int pi = partition(arr, low, high); // pivot index for taking high as pivot value
    int pi = partitionLeft(arr, low, high); // pivot index for taking low as pivot value
    quickSort(arr, low, pi-1);  //recursion for left part
    quickSort(arr, pi+1, high); //rescursion for right part
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}