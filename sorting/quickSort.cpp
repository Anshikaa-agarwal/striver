#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &arr, int low, int high) {
    //base case
    if(low>=high) return;

    //choose a pivot element, here we're choosing first element of array.
    int pivot = arr[low];
    int i=low+1, j=high;

    //place all elements smaller than pivot on left side and greater to right side.
    while(i<j) {
        while(arr[i] < pivot && i<=high) i++;
        while(arr[j]>pivot) j--;

        if(i<j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
}

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) 
    cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {2,9,1,-5,9,11,3};
    quickSort(arr, 0, arr.size()-1);
    printArr(arr);

    return 0;
}