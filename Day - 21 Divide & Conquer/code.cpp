#include <iostream>
#include <vector>
using namespace std;

void printArr(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Merge Sort Algorithm

// Merge/Combine Step
void merge(int arr[], int si, int mid, int ei) {
    
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }
    // vector -> original array
    for(int idx=si, x=0; idx<=ei; idx++) {
        arr[idx] = temp[x++];
    }
}
// Merge Sort
void mergeSort(int arr[], int si, int ei) { // O(nlogn)
    if(si >= ei) {                // Base Case
        return;
    }
    // To avoid Stack Overflow - (si + ei) / 2
    int mid = si + (ei - si) / 2; // Divide
    mergeSort(arr, si, mid);      // Left
    mergeSort(arr, mid+1, ei);    // Right
    merge(arr, si, mid, ei);      // Conquer (Merge/Combine)
} 

// Quick Sort Algorithm

// Partiton Step
int partition(int arr[], int si, int ei) {
    int i = si-1;
    int pivot = arr[ei];
    for(int j=si; j<ei; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    // pivotIdx = i;
    return i;
}
// Quick Sort - Pivot Element
void quickSort(int arr[], int si, int ei) { // Average - O(nlogn) Worst - O(n^2)
    if(si >= ei) { // Base Case
        return;
    }

    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx-1); // Left Half
    quickSort(arr, pivotIdx+1, ei); // Right Half

}

// Search in Rotated Sorted Array
int search(int arr[], int si, int ei, int tar) { // O(logn)
    if(si > ei) {                              // Base Case
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if(arr[mid] == tar) {                       // Element Found
        return mid;
    } 
    if(arr[si] <= arr[mid]) {                   // L1
        if(arr[si] <= tar && tar <= arr[mid]) {
            return search(arr, si, mid-1, tar); // Left Half
        } else {
            return search(arr, mid+1, ei, tar); // Right Half
        } 
    } else {                                    // L2
        if(arr[mid] <= tar && tar <= arr[ei]) {
            return search(arr, mid+1, ei, tar); // Right Half
        } else {
            return search(arr, si, mid-1, tar); // Left Half
        }
    }
}

int main() {

    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    // Merge Sort
    mergeSort(arr, 0, n-1); 
    printArr(arr, n);
    // Quick Sort
    quickSort(arr, 0, n-1);
    printArr(arr, n);

    // Search in Rotated Sorted Array
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    int m = 7;
    cout << "Index: " << search(a, 0, m-1, 0) << endl;

    return 0;
}