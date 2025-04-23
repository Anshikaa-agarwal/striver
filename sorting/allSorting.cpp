#include<iostream>
#include<vector>
using namespace std;

int minIndex(vector<int> &arr, int start) {
    int index = start;
    for(int i=start; i<arr.size(); i++) {
        if(arr[i]<arr[index])
        index = i;
    }
    return index;
}

void merge(vector<int> &arr, int low, int mid, int high) {

    //we've to merge 2 arrays - low to mid, mid+1 to high
    vector<int> temp;
    int i=low;
    int j=mid+1;

    while(i<=mid && j<=high) {
        if(arr[i]<arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else temp.push_back(arr[j++]);
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=high) temp.push_back(arr[j++]);

    for(int k=0; k<temp.size(); k++) {
        arr[k+low] = temp[k];
    }
}

void selectionSort(vector<int> &arr) {
    //select minimum and place it at first index
    for(int i=0; i<arr.size()-1; i++) {
        int index = minIndex(arr, i);
        swap(arr[i], arr[index]);
    }

    //Time complexity: O(n^2)
}

void bubbleSort(vector<int> &arr) {
    //push max element to last
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr.size()-i-1; j++) {
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

    //time complexity: O(n^2)
}

void insertionSort(vector<int> &arr) {
    //select an element and place it at it's correct place

    int i=1;
    int n=arr.size();

    while(i<n) {
        while(arr[i]>arr[i-1] && i<n-1) i++;
        int element = arr[i];
        int j=i-1;
        while(element<arr[j] && j>=0) {
            arr[j+1] = arr[j];
            j--; 
        } 
        arr[j+1] = element;
        i++;
    }

    //time complexity: O(n^2)
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low>=high) return;

    int mid = (high+low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);

    //time complexity: O(n*log n)
}

void quickSort(vector<int> &arr) {

}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) 
    cout << arr[i] << " ";
}

int main() {
    vector<int> arr1 = {3,9,0,-4,3,11,7};
    vector<int> arr2 = {7,1,1,3,1,0,1,1,1,2,9};
    vector<int> arr3 = {4,5,1,2,0,9,3};
    vector<int> arr4 = {1,0,3,9,4,7,1,2};

    selectionSort(arr1);
    cout << "Selection sort: ";
    printArr(arr1);

    bubbleSort(arr2);
    cout << endl << "Bubble sort: ";
    printArr(arr2);

    insertionSort(arr3);
    cout << endl << "Insertion sort: ";
    printArr(arr3);

    mergeSort(arr4, 0, arr4.size()-1);
    cout << endl << "Merge sort: ";
    printArr(arr4);

    return 0;
}